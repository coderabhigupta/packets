#ifndef MESSAGE_FACTORY_HEADER_H
#define MESSAGE_FACTORY_HEADER_H

#include <memory>
#include <fstream>
#include "messages/ouch_message.hpp"

class MessageFactory {
public:
    virtual std::unique_ptr<OuchMessage> createMessage(std::fstream& ifs, OuchMessage message) const;
    virtual ~MessageFactory() {};
};

#endif // MESSAGE_FACTORY_HEADER_H