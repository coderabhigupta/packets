#ifndef EXECUTED_MESSAGE_FACTORY_HEADER_H
#define EXECUTED_MESSAGE_FACTORY_HEADER_H

#include <memory>
#include <fstream>
#include "message_factory.hpp"
#include "messages/ouch_message.hpp"

class ExecutedMessageFactory : public MessageFactory {
public:
    std::unique_ptr<OuchMessage> createMessage(std::fstream& ifs, OuchMessage message) const;
    ~ExecutedMessageFactory();
};

#endif // EXECUTED_MESSAGE_FACTORY_HEADER_H