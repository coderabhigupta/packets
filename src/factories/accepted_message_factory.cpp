#include "factories/accepted_message_factory.hpp"
#include "messages/accepted_message.hpp"

std::unique_ptr<OuchMessage> AcceptedMessageFactory::createMessage(std::fstream& ifs, OuchMessage message) const { 
    AcceptedMessage* msg = new AcceptedMessage(message.getLength(), message.getTimestamp());

    char orderToken[15], symbol[9], firm[5];        
    char side, display, orderCapacity, interMarketSweep, crossType, orderState;  
    unsigned int shares, price, timeInForce, minimumQuantity;
    unsigned long orderReferenceNumber;

    ifs.read(orderToken, sizeof(orderToken)-1);
    ifs.read(reinterpret_cast<char*>(&side), sizeof(side));
    ifs.read(reinterpret_cast<char*>(&shares), sizeof(shares));
    ifs.read(symbol, sizeof(symbol)-1);
    ifs.read(reinterpret_cast<char*>(&price), sizeof(price));
    ifs.read(reinterpret_cast<char*>(&timeInForce), sizeof(timeInForce));
    ifs.read(firm, sizeof(firm)-1);
    ifs.read(reinterpret_cast<char*>(&display), sizeof(display));
    ifs.read(reinterpret_cast<char*>(&orderReferenceNumber), sizeof(orderReferenceNumber));
    ifs.read(reinterpret_cast<char*>(&orderCapacity), sizeof(orderCapacity));
    ifs.read(reinterpret_cast<char*>(&interMarketSweep), sizeof(interMarketSweep));
    ifs.read(reinterpret_cast<char*>(&minimumQuantity), sizeof(minimumQuantity));
    ifs.read(reinterpret_cast<char*>(&crossType), sizeof(crossType));
    ifs.read(reinterpret_cast<char*>(&orderState), sizeof(orderState));

    msg->setOrderToken(orderToken);
    msg->setSide(side);
    msg->setShares(shares);
    msg->setSymbol(symbol);
    msg->setPrice(price);
    msg->setTimeInForce(timeInForce);
    msg->setFirm(firm);
    msg->setDisplay(display);
    msg->setOrderReferenceNumber(orderReferenceNumber);
    msg->setOrderCapacity(orderCapacity);
    msg->setInterMarketSweep(interMarketSweep);
    msg->setMinimumQuantity(minimumQuantity);
    msg->setCrossType(crossType);
    msg->setOrderState(orderState);

    return std::unique_ptr<OuchMessage>(msg);
}

AcceptedMessageFactory::~AcceptedMessageFactory() {}
