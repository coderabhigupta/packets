#include "messages/executed_message.hpp"
#include <iostream>

// Constructors
ExecutedMessage::ExecutedMessage() {}

ExecutedMessage::ExecutedMessage(unsigned short length, unsigned long long timestamp)
    : OuchMessage(length, 'S', 'U', timestamp) {
}

ExecutedMessage::~ExecutedMessage() {}

// Getters and Setters
const char* ExecutedMessage::getOrderToken() const {
    return mOrderToken;
}

void ExecutedMessage::setOrderToken(const char* newOrderToken) {
    strncpy(mOrderToken, newOrderToken, sizeof(mOrderToken) - 1);
    mOrderToken[sizeof(mOrderToken) - 1] = '\0'; // Ensure null-termination
}

unsigned int ExecutedMessage::getExecutedShares() const {
    return mExecutedShares;
}

void ExecutedMessage::setExecutedShares(unsigned int executedShares) {
    mExecutedShares = executedShares;
}

unsigned int ExecutedMessage::getExecutedPrice() const {
    return mExecutedPrice;
}

void ExecutedMessage::setExecutedPrice(unsigned int executedPrice) {
    mExecutedPrice = executedPrice;
}

char ExecutedMessage::getLiquidityFlag() const {
    return mLiquidityFlag;
}

void ExecutedMessage::setLiquidityFlag(char liquidityFlag) {
    mLiquidityFlag = liquidityFlag;
}

void ExecutedMessage::setMatchNumber(unsigned long long matchNumber) {
    mMatchNumber = matchNumber;
}

unsigned long long ExecutedMessage::getMatchNumber() const {
    return mMatchNumber;
}

void ExecutedMessage::display() const {
    OuchMessage::display();
    
    std::cout << "Order Token: " << mOrderToken << std::endl;
    std::cout << "Executed Shares: " << mExecutedShares << std::endl;
    std::cout << "Executed Price: " << mExecutedPrice << std::endl;
    std::cout << "Liquidity Flag: " << mLiquidityFlag << std::endl;
    std::cout << "Match NUmber: " << mMatchNumber << std::endl;
}