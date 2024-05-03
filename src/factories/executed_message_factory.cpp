#include "factories/executed_message_factory.hpp"
#include "messages/executed_message.hpp"

std::unique_ptr<OuchMessage> ExecutedMessageFactory::createMessage(std::fstream& ifs, OuchMessage message) const {
    ExecutedMessage* msg = new ExecutedMessage(message.getLength(), message.getTimestamp());

    char orderToken[15];        
    char liquidity;  
    unsigned int shares, price;
    unsigned long long matchNum;

    ifs.read(orderToken, sizeof(orderToken)-1);
    ifs.read(reinterpret_cast<char*>(&shares), sizeof(shares));
    ifs.read(reinterpret_cast<char*>(&price), sizeof(price));
    ifs.read(reinterpret_cast<char*>(&liquidity), sizeof(liquidity));
    ifs.read(reinterpret_cast<char*>(&matchNum), sizeof(matchNum));

    msg->setOrderToken(orderToken);
    msg->setExecutedShares(shares);
    msg->setExecutedPrice(price);
    msg->setLiquidityFlag(liquidity);
    msg->setMatchNumber(matchNum);

    return std::unique_ptr<OuchMessage>(msg);
}

ExecutedMessageFactory::~ExecutedMessageFactory() {}
