#include "factories/system_event_message_factory.hpp"
#include "messages/system_event_message.hpp"

std::unique_ptr<OuchMessage> SystemEventMessageFactory::createMessage(std::fstream& ifs, OuchMessage message) const {
    SystemEventMessage* msg = new SystemEventMessage(message.getLength(), message.getTimestamp());

    char ee;
    ifs.read(reinterpret_cast<char*>(&ee), sizeof(ee));
    msg->setEventEnumeration(ee);

    return std::unique_ptr<OuchMessage>(msg);
}

SystemEventMessageFactory::~SystemEventMessageFactory() {}
