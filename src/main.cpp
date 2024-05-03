#include <iostream>
#include <fstream>
#include <iosfwd>
#include <vector>
#include <string>
#include <map>
#include "packets/packet_capture_header.hpp"
#include "packets/packet.hpp"
#include "factories/message_factory.hpp"
#include "factories/accepted_message_factory.hpp"
#include "factories/replaced_message_factory.hpp"
#include "factories/canceled_message_factory.hpp"
#include "factories/system_event_message_factory.hpp"

typedef std::vector<Packet> PacketVec;

int main() {
    std::fstream packets_file;
    packets_file.open("OUCHLMM2.incoming.packets", std::ios::in | std::ios::binary);

    if (!packets_file) {
		std::cout << "No such file";
        return 0;
	} 

    std::map<int, PacketVec> packet_streams;
    std::unique_ptr<MessageFactory> factory(new SystemEventMessageFactory());
    
    unsigned short si, ml;
    unsigned int pl;
    unsigned long long ts;
    char ptype, mtype;
    int packet_count = 0;

    while (!packets_file.eof()) {
        packets_file.read(reinterpret_cast<char*>(&si), sizeof(si));
        packets_file.read(reinterpret_cast<char*>(&pl), sizeof(pl));
        packets_file.read(reinterpret_cast<char*>(&ml), sizeof(ml));
        packets_file.read(reinterpret_cast<char*>(&ptype), sizeof(ptype));
        packets_file.read(reinterpret_cast<char*>(&mtype), sizeof(mtype));
        packets_file.read(reinterpret_cast<char*>(&ts), sizeof(ts));
        
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
            // case 'E':
            //     factory = new ExecutedMessageFactory();
            //     break;
            case 'C':
                factory.reset(new CanceledMessageFactory());
                break;
        }

        OuchMessage ouchMessage(ml, ptype, mtype, ts);
        std::unique_ptr<OuchMessage> message = factory->createMessage(packets_file, ouchMessage);

        // Uncomment this to see contents of all packets
        // message->display();

        PacketCaptureHeader header(si, pl);

        std::map<int, PacketVec>::const_iterator c_it = packet_streams.find(si);

        if (c_it == packet_streams.end()) {
            packet_streams.insert(std::pair<int, PacketVec>(si, PacketVec()));
        }

        packet_streams[si].push_back(Packet(header, *message));
        packet_count++;
    }
	
    packets_file.close();

    // Get aggregated summary of all the parsed packets
    int accepted = 0, replaced = 0, canceled = 0, system = 0;

    for (auto cit = packet_streams.cbegin(); cit != packet_streams.cend(); ++cit) {
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
            default:
                std::cout << "Unidentified" << std::endl;
        }
    }
    std::cout << "-----Aggregated OUCH Message Summary-----" << std::endl;
    std::cout << "Total number of captured packets: " << packet_count << std::endl;
    std::cout << "Total number of Unique streams: " << packet_streams.size() << std::endl;
    std::cout << "Total number of Accepted Messages: " << accepted << std::endl;
    std::cout << "Total number of Replaced Messages: " << replaced << std::endl;
    std::cout << "Total number of Canceled Messages: " << canceled << std::endl;
    std::cout << "Total number of System Event Messages: " << system << std::endl;

    return 0;
}