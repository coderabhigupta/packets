#ifndef PACKET_H
#define PACKET_H

#include <string>
#include <vector>
#include "packet_capture_header.hpp"
#include "../messages/ouch_message.hpp"

class Packet {
private:
    PacketCaptureHeader mHeader;
    OuchMessage mMessage;

public:
    // Constructors
    Packet();
    Packet(const PacketCaptureHeader &header, const OuchMessage &message);

    // Getter and Setter for header
    PacketCaptureHeader getHeader() const;
    void setHeader(const PacketCaptureHeader &header);

    // Getter and Setter for message
    OuchMessage getMessage() const;
    void setMessage(const OuchMessage &message);
};

#endif // PACKET_H
