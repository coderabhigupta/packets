#include <string>
#include <iostream>
#include "messages/ouch_message.hpp"

// Constructors
OuchMessage::OuchMessage() {}

OuchMessage::OuchMessage(unsigned short length, char packetType, char messageType, unsigned long long timestamp)
{
    mLength = length;
    mPacketType = packetType;
    mMessageType = messageType;
    mTimestamp = timestamp;
}

// Getter and Setter for length
unsigned short OuchMessage::getLength()
{
    return mLength;
}

void OuchMessage::setLength(unsigned short length)
{
    mLength = length;
}

// Getter and Setter for packetType
char OuchMessage::getPacketType()
{
    return mPacketType;
}

void OuchMessage::setPacketType(char packetType)
{
    mPacketType = packetType;
}

// Getter and Setter for messageType
char OuchMessage::getMessageType()
{
    return mMessageType;
}

void OuchMessage::setMessageType(char messageType)
{
    mMessageType = messageType;
}

// Getter and Setter for timestamp
unsigned long long OuchMessage::getTimestamp()
{
    return mTimestamp;
}

void OuchMessage::setTimestamp(unsigned long long timestamp)
{
    mTimestamp = timestamp;
}

void OuchMessage::display() const {
    std::cout << "Message Length: " << mLength << std::endl;
    std::cout << "Packet Type: " << mPacketType << std::endl;
    std::cout << "Message Type: " << mMessageType << std::endl;
    std::cout << "Timestamp: " << mTimestamp << std::endl;
}
