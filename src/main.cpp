#include <iostream>
#include <fstream>
#include <iosfwd>
#include <vector>
#include <string>
#include <map>
#include "packets/packet_capture_header.hpp"
#include "packets/packet.hpp"
#include "messages/executed_message.hpp"
#include "factories/message_factory.hpp"
#include "factories/accepted_message_factory.hpp"
#include "factories/replaced_message_factory.hpp"
#include "factories/canceled_message_factory.hpp"
#include "factories/executed_message_factory.hpp"
#include "factories/system_event_message_factory.hpp"

typedef std::vector<Packet> PacketVec;

int main() {
    std::fstream packetsFile;
    packetsFile.open("OUCHLMM2.incoming.packets", std::ios::in | std::ios::binary);

    if (!packetsFile) {
		std::cout << "No such file";
        return 0;
	} 

    std::unique_ptr<MessageFactory> factory;
    std::map<int, PacketVec> streamPacketMap;
    int packetCount = 0;

    while (!packetsFile.eof()) {
        unsigned short si, ml;
        unsigned int pl;
        unsigned long long ts;
        char ptype, mtype;

        packetsFile.read(reinterpret_cast<char*>(&si), sizeof(si));
        packetsFile.read(reinterpret_cast<char*>(&pl), sizeof(pl));
        
        packetsFile.read(reinterpret_cast<char*>(&ml), sizeof(ml));
        packetsFile.read(reinterpret_cast<char*>(&ptype), sizeof(ptype));
        packetsFile.read(reinterpret_cast<char*>(&mtype), sizeof(mtype));
        packetsFile.read(reinterpret_cast<char*>(&ts), sizeof(ts));
        
        // Uncomment this to see contents of Packet Capture Header
        // std::cout << "\n\nStream: " << si << " Packet Length: " << pl << std::endl;

        switch(mtype) {
            case 'S':
                factory.reset(new SystemEventMessageFactory());
                break;
            case 'A':
                factory.reset(new AcceptedMessageFactory());
                break;
            case 'U':
                factory.reset(new ReplacedMessageFactory());
                break;
            case 'E':
                factory.reset(new ExecutedMessageFactory());
                break;
            case 'C':
                factory.reset(new CanceledMessageFactory());
                break;
        }

        OuchMessage ouchMessage(ml, ptype, mtype, ts);
        std::unique_ptr<OuchMessage> message = factory->createMessage(packetsFile, ouchMessage);

        // Uncomment this to see contents of all packets
        // message->display();

        PacketCaptureHeader header(si, pl);

        std::map<int, PacketVec>::const_iterator c_it = streamPacketMap.find(si);

        if (c_it == streamPacketMap.end()) {
            streamPacketMap.insert(std::pair<int, PacketVec>(si, PacketVec()));
        }

        streamPacketMap[si].push_back(Packet(header, *message));
        packetCount++;
    }
	
    packetsFile.close();

    // Get aggregated summary of all the parsed packets
    int accepted = 0, replaced = 0, canceled = 0, system = 0, executed = 0;
    unsigned int totalExecutedShares = 0;

    for (auto cit = streamPacketMap.cbegin(); cit != streamPacketMap.cend(); ++cit) {
        std::cout << "Stream: " << cit->first << " Number of packets: " << cit->second.size() << std::endl;

        char mtype = cit->second.front().getMessage().getMessageType();

        switch(mtype) {
            case 'A':
                accepted++;
                break;
            case 'C':
                canceled++;
                break;
            case 'U':
                replaced++;
                break;
            case 'S':
                system++;
                break;
            case 'E':
                for (auto it = cit->second.begin(); it != cit->second.end(); ++it) {
                    OuchMessage ouchMsg = it->getMessage();
                    ExecutedMessage* execMsg = dynamic_cast<ExecutedMessage*>(&ouchMsg);
                    totalExecutedShares += execMsg->getExecutedShares();
                }
                executed++;
                break;
            default:
                std::cout << "Unidentified" << std::endl;
        }
    }
    std::cout << "-----Aggregated OUCH Message Summary-----" << std::endl;
    std::cout << "Total number of captured packets: " << packetCount << std::endl;
    std::cout << "Total number of Unique streams: " << streamPacketMap.size() << std::endl;
    std::cout << "Total number of Accepted Messages: " << accepted << std::endl;
    std::cout << "Total number of Replaced Messages: " << replaced << std::endl;
    std::cout << "Total number of Canceled Messages: " << canceled << std::endl;
    std::cout << "Total number of System Event Messages: " << system << std::endl;
    std::cout << "Total number of Executed Messages: " << executed << std::endl;
    std::cout << "Total number of Executed Shares: " << totalExecutedShares << std::endl;

    return 0;
}