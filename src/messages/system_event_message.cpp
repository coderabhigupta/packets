#include "messages/system_event_message.hpp"
#include <iostream>

SystemEventMessage::SystemEventMessage() {} 

SystemEventMessage::SystemEventMessage(unsigned short length, unsigned long long timestamp)
    : OuchMessage(length, 'S', 'S', timestamp) {}

void SystemEventMessage::display() const {
    OuchMessage::display();

    std::cout << "Event Enumeration: " << mEventEnumeration << std::endl;
}