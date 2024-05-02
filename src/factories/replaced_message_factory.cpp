#include "factories/replaced_message_factory.hpp"
#include "messages/replaced_message.hpp"

std::unique_ptr<OuchMessage> ReplacedMessageFactory::createMessage(std::fstream& ifs, OuchMessage message) const {
    ReplacedMessage* msg = new ReplacedMessage(message.getLength(), message.getTimestamp());

    char orderToken[15], symbol[9], firm[5];        
    char side, display;  
    unsigned int shares, price, timeInForce;

    ifs.read(orderToken, sizeof(orderToken)-1);
    ifs.read(reinterpret_cast<char*>(&side), sizeof(side));
    ifs.read(reinterpret_cast<char*>(&shares), sizeof(shares));
    ifs.read(symbol, sizeof(symbol)-1);
    ifs.read(reinterpret_cast<char*>(&price), sizeof(price));
    ifs.read(reinterpret_cast<char*>(&timeInForce), sizeof(timeInForce));
    ifs.read(firm, sizeof(firm)-1);
    ifs.read(reinterpret_cast<char*>(&display), sizeof(display));

    msg->setOrderToken(orderToken);
    msg->setSide(side);
    msg->setShares(shares);
    msg->setSymbol(symbol);
    msg->setPrice(price);
    msg->setTimeInForce(timeInForce);
    msg->setFirm(firm);
    msg->setDisplay(display);

    return std::unique_ptr<OuchMessage>(msg);
}

ReplacedMessageFactory::~ReplacedMessageFactory() {}
