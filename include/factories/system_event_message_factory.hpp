#ifndef SYSTEM_EVENT_MESSAGE_FACTORY_HEADER_H
#define SYSTEM_EVENT_MESSAGE_FACTORY_HEADER_H

#include <memory>
#include <fstream>
#include "message_factory.hpp"
#include "messages/ouch_message.hpp"

class SystemEventMessageFactory : public MessageFactory {
public:
    std::unique_ptr<OuchMessage> createMessage(std::fstream& ifs, OuchMessage message) const;
    ~SystemEventMessageFactory();
};

#endif // SYSTEM_EVENT_MESSAGE_FACTORY_HEADER_H