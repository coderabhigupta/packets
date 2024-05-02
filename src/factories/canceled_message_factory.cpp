#include "factories/canceled_message_factory.hpp"
#include "messages/canceled_message.hpp"

std::unique_ptr<OuchMessage> CanceledMessageFactory::createMessage(std::fstream& ifs, OuchMessage message) const {
    CanceledMessage* msg = new CanceledMessage(message.getLength(), message.getTimestamp());
    char orderToken[15];        
    char reason;  
    unsigned int decrementShares;

    ifs.read(orderToken, sizeof(orderToken)-1);
    ifs.read(reinterpret_cast<char*>(&reason), sizeof(reason));
    ifs.read(reinterpret_cast<char*>(&decrementShares), sizeof(decrementShares));

    return std::unique_ptr<OuchMessage>(msg);
}

CanceledMessageFactory::~CanceledMessageFactory() {}