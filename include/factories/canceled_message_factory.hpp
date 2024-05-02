#ifndef CANCELED_MESSAGE_FACTORY_HEADER_H
#define CANCELED_MESSAGE_FACTORY_HEADER_H

#include <memory>
#include <fstream>
#include "message_factory.hpp"
#include "messages/ouch_message.hpp"

class CanceledMessageFactory : public MessageFactory {
public:
    std::unique_ptr<OuchMessage> createMessage(std::fstream& ifs, OuchMessage message) const;
    ~CanceledMessageFactory();
};

#endif // CANCELED_MESSAGE_FACTORY_HEADER_H