#include "messages/canceled_message.hpp"
#include <iostream>

// Constructor
CanceledMessage::CanceledMessage() {}

CanceledMessage::CanceledMessage(unsigned short length, unsigned long long timestamp)
    : OuchMessage(length, 'S', 'C', timestamp) {
}

CanceledMessage::~CanceledMessage() {}

// Getter and Setter for orderToken
const char* CanceledMessage::getOrderToken() const {
    return mOrderToken;
}

void CanceledMessage::setOrderToken(const char* orderToken) {
    strncpy(mOrderToken, orderToken, sizeof(mOrderToken) - 1);
    mOrderToken[sizeof(mOrderToken) - 1] = '\0';
}

// Getter and Setter for decrementShares
unsigned int CanceledMessage::getDecrementShares() const {
    return mDecrementShares;
}

void CanceledMessage::setDecrementShares(unsigned int decrementShares) {
    mDecrementShares = decrementShares;
}

// Getter and Setter for reason
char CanceledMessage::getReason() const {
    return mReason;
}

void CanceledMessage::setReason(char reason) {
    mReason = reason;
}

void CanceledMessage::display() const {
    OuchMessage::display();
    
    std::cout << "Order Token: " << mOrderToken << std::endl;
    std::cout << "Decrement Shares: " << mDecrementShares << std::endl;
    std::cout << "Reason: " << mReason << std::endl;
}
