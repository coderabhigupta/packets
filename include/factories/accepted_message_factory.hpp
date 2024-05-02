#ifndef ACCEPTED_MESSAGE_FACTORY_HEADER_H
#define ACCEPTED_MESSAGE_FACTORY_HEADER_H

#include <memory>
#include <fstream>
#include "message_factory.hpp"
#include "messages/ouch_message.hpp"

class AcceptedMessageFactory : public MessageFactory {
public:
    std::unique_ptr<OuchMessage> createMessage(std::fstream& ifs, OuchMessage message) const;
    ~AcceptedMessageFactory();
};

#endif // ACCEPTED_MESSAGE_FACTORY_HEADER_H