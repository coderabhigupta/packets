#ifndef PACKET_CAPTURE_HEADER_H
#define PACKET_CAPTURE_HEADER_H

class PacketCaptureHeader {               
    int mStreamIdentifer;
    int mPacketLength;

    public:

    // Constructors
    PacketCaptureHeader();
    PacketCaptureHeader(int streamIdentifer, int packetLength);
    
    // Setters
    void setStreamIdentifer(int streamIdentifier);
    void setPacketLength(int packetLength);

    // Getters
    int getStreamIdentifer();
    int getPacketLength();
};

#endif // PACKET_CAPTURE_HEADER