#ifndef OUCH_MESSAGE_HEADER_H
#define OUCH_MESSAGE_HEADER_H

class OuchMessage {               
    unsigned short mLength;        
    char mPacketType;  
    char mMessageType;
    unsigned long long mTimestamp;

    public:
    // Constructors
    OuchMessage();
    OuchMessage(unsigned short length, char packetType, char messageType, unsigned long long timestamp);
    virtual ~OuchMessage() {};
    
    // Setters
    void setLength(unsigned short length);
    void setPacketType(char packetType);
    void setMessageType(char messageType);
    void setTimestamp(unsigned long long timestamp);

    // Getters
    unsigned short getLength();
    char getPacketType();
    char getMessageType();
    unsigned long long getTimestamp();

    // Display
    virtual void display() const;
};

#endif // OUCH_MESSAGE_HEADER