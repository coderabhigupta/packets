#ifndef REPLACED_MESSAGE_FACTORY_HEADER_H
#define REPLACED_MESSAGE_FACTORY_HEADER_H

#include <memory>
#include <fstream>
#include "message_factory.hpp"
#include "messages/ouch_message.hpp"

class ReplacedMessageFactory : public MessageFactory {
public:
    std::unique_ptr<OuchMessage> createMessage(std::fstream& ifs, OuchMessage message) const;
    ~ReplacedMessageFactory();
};

#endif // REPLACED_MESSAGE_FACTORY_HEADER_H