#ifndef SYSTEM_EVENT_MESSAGE_HEADER_H
#define SYSTEM_EVENT_MESSAGE_HEADER_H

#include <string>
#include "ouch_message.hpp"

class SystemEventMessage : public OuchMessage {                    
    char mEventEnumeration;
    
    public:
    SystemEventMessage();
    SystemEventMessage(unsigned short length, unsigned long long timestamp);

    char getMEventEnumeration() const { return mEventEnumeration; }
    void setEventEnumeration(char eventEnumeration) {
        mEventEnumeration = eventEnumeration;
    };

    void display() const;
};

#endif // SYSTEM_EVENT_MESSAGE_HEADER_H