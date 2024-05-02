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

    int count = 0, max_count = INT_MAX;
    std::cout << "Enter number of packets to be captured: ";
    std::cin >> max_count;

    while (!packets_file.eof() && (count == 0 || count < max_count)) {
        // std::cout << "Current stream position: " << packets_file.tellg() << std::endl;

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
        count++;
    }
	
    packets_file.close();
    std::cout << "Total number of captured packets: " << count << std::endl;
    std::cout << "Total number of unique streams: " << packet_streams.size() << std::endl;

    for (auto cit = packet_streams.cbegin(); cit != packet_streams.cend(); ++cit) {
        std::cout << "Stream: " << cit->first << " Number of packets: " << cit->second.size() << std::endl;
    }

    return 0;
}