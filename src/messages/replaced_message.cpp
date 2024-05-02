#include "messages/replaced_message.hpp"
#include <iostream>

// Constructors
ReplacedMessage::ReplacedMessage() {}

ReplacedMessage::ReplacedMessage(unsigned short length, unsigned long long timestamp)
    : OuchMessage(length, 'S', 'U', timestamp) {
}

ReplacedMessage::~ReplacedMessage() {}

// Getters and Setters
const char* ReplacedMessage::getOrderToken() const {
    return mOrderToken;
}

void ReplacedMessage::setOrderToken(const char* newOrderToken) {
    strncpy(mOrderToken, newOrderToken, sizeof(mOrderToken) - 1);
    mOrderToken[sizeof(mOrderToken) - 1] = '\0'; // Ensure null-termination
}

char ReplacedMessage::getSide() const {
    return mSide;
}

void ReplacedMessage::setSide(char side) {
    mSide = side;
}

unsigned int ReplacedMessage::getShares() const {
    return mShares;
}

void ReplacedMessage::setShares(unsigned int shares) {
    mShares = shares;
}

const char* ReplacedMessage::getSymbol() const {
    return mSymbol;
}

void ReplacedMessage::setSymbol(const char* symbol) {
    strncpy(mSymbol, symbol, sizeof(mSymbol) - 1);
    mSymbol[sizeof(mSymbol) - 1] = '\0'; // Ensure null-termination
}

unsigned int ReplacedMessage::getPrice() const {
    return mPrice;
}

void ReplacedMessage::setPrice(unsigned int price) {
    mPrice = price;
}

unsigned int ReplacedMessage::getTimeInForce() const {
    return mTimeInForce;
}

void ReplacedMessage::setTimeInForce(unsigned int timeInForce) {
    mTimeInForce = timeInForce;
}

const char* ReplacedMessage::getFirm() const {
    return mFirm;
}

void ReplacedMessage::setFirm(const char* firm) {
    strncpy(mFirm, firm, sizeof(mFirm) - 1);
    mFirm[sizeof(mFirm) - 1] = '\0'; // Ensure null-termination
}

char ReplacedMessage::getDisplay() const {
    return mDisplay;
}

void ReplacedMessage::setDisplay(char display) {
    mDisplay = display;
}

void ReplacedMessage::display() const {
    OuchMessage::display();
    
    std::cout << "Order Token: " << mOrderToken << std::endl;
    std::cout << "Side: " << mSide << std::endl;
    std::cout << "Shares: " << mShares << std::endl;
    std::cout << "Symbol: " << mSymbol << std::endl;
    std::cout << "Price: " << mPrice << std::endl;
    std::cout << "Time In Force: " << mTimeInForce << std::endl;
    std::cout << "Firm: " << mFirm << std::endl;
    std::cout << "Display: " << mDisplay << std::endl;
}