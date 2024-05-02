#include "packets/packet_capture_header.hpp"

// Constructors
PacketCaptureHeader::PacketCaptureHeader() {}

PacketCaptureHeader::PacketCaptureHeader(int streamIdentifier, int packetLength) {
    mStreamIdentifer = streamIdentifier;
    mPacketLength = packetLength;
}
   
// Getter and Setter for streamIdentifer
int PacketCaptureHeader::getStreamIdentifer() {
    return mStreamIdentifer;
}

void PacketCaptureHeader::setStreamIdentifer(int streamIdentifer) {
    mStreamIdentifer = streamIdentifer;
}

// Getter and Setter for packetLength
int PacketCaptureHeader::getPacketLength() {
    return mPacketLength;
}

void PacketCaptureHeader::setPacketLength(int packetLength) {
    mPacketLength = packetLength;
}
