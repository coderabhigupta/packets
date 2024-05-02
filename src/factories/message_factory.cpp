#include <string>
#include <memory>
#include "factories/message_factory.hpp"
#include "messages/ouch_message.hpp"

std::unique_ptr<OuchMessage> MessageFactory::createMessage(std::fstream& ifs, OuchMessage message) const { 
    OuchMessage* msg = new OuchMessage(
        message.getLength(), 
        message.getPacketType(),
        message.getMessageType(), 
        message.getTimestamp()
    );
    return std::unique_ptr<OuchMessage>(msg);
}
  