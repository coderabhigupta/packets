#include "packets/packet_capture_header.hpp"
#include "packets/packet.hpp"

// Constructor
Packet::Packet() {}

Packet::Packet(const PacketCaptureHeader &header, const OuchMessage& message) {
    mHeader = header;
    mMessage = message;
}

// Getter and Setter for header
PacketCaptureHeader Packet::getHeader() const {
    return mHeader;
}

void Packet::setHeader(const PacketCaptureHeader& header) {
    mHeader = header;
}

// Getter and Setter for bytes
OuchMessage Packet::getMessage() const {
    return mMessage;
}

void Packet::setMessage(const OuchMessage& message) {
    mMessage = message;
}
