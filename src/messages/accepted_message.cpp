#include "messages/accepted_message.hpp"
#include <iostream>

// Constructor
AcceptedMessage::AcceptedMessage() {}

AcceptedMessage::AcceptedMessage(unsigned short length, unsigned long long timestamp)
    : OuchMessage(length, 'S', 'A', timestamp) {
}

AcceptedMessage::~AcceptedMessage() {}

// Getters and Setters
const char* AcceptedMessage::getOrderToken() const {
    return mOrderToken;
}

void AcceptedMessage::setOrderToken(const char* newOrderToken) {
    strncpy(mOrderToken, newOrderToken, sizeof(mOrderToken) - 1);
    mOrderToken[sizeof(mOrderToken) - 1] = '\0'; // Ensure null-termination
}

char AcceptedMessage::getSide() const {
    return mSide;
}

void AcceptedMessage::setSide(char side) {
    mSide = side;
}

unsigned int AcceptedMessage::getShares() const {
    return mShares;
}

void AcceptedMessage::setShares(unsigned int shares) {
    mShares = shares;
}

const char* AcceptedMessage::getSymbol() const {
    return mSymbol;
}

void AcceptedMessage::setSymbol(const char* symbol) {
    strncpy(mSymbol, symbol, sizeof(mSymbol) - 1);
    mSymbol[sizeof(mSymbol) - 1] = '\0'; // Ensure null-termination
}

unsigned int AcceptedMessage::getPrice() const {
    return mPrice;
}

void AcceptedMessage::setPrice(unsigned int price) {
    mPrice = price;
}

unsigned int AcceptedMessage::getTimeInForce() const {
    return mTimeInForce;
}

void AcceptedMessage::setTimeInForce(unsigned int timeInForce) {
    mTimeInForce = timeInForce;
}

const char* AcceptedMessage::getFirm() const {
    return mFirm;
}

void AcceptedMessage::setFirm(const char* firm) {
    strncpy(mFirm, firm, sizeof(mFirm) - 1);
    mFirm[sizeof(mFirm) - 1] = '\0'; // Ensure null-termination
}

char AcceptedMessage::getDisplay() const {
    return mDisplay;
}

void AcceptedMessage::setDisplay(char display) {
    mDisplay = display;
}

unsigned long AcceptedMessage::getOrderReferenceNumber() const {
    return mOrderReferenceNumber;
}

void AcceptedMessage::setOrderReferenceNumber(unsigned long orderReferenceNumber) {
    mOrderReferenceNumber = orderReferenceNumber;
}

char AcceptedMessage::getOrderCapacity() const {
    return mOrderCapacity;
}

void AcceptedMessage::setOrderCapacity(char orderCapacity) {
    mOrderCapacity = orderCapacity;
}

char AcceptedMessage::getInterMarketSweep() const {
    return mInterMarketSweep;
}

void AcceptedMessage::setInterMarketSweep(char interMarketSweep) {
    mInterMarketSweep = interMarketSweep;
}

unsigned int AcceptedMessage::getMinimumQuantity() const {
    return mMinimumQuantity;
}

void AcceptedMessage::setMinimumQuantity(unsigned int minimumQuantity) {
    mMinimumQuantity = minimumQuantity;
}

char AcceptedMessage::getCrossType() const {
    return mCrossType;
}

void AcceptedMessage::setCrossType(char crossType) {
    mCrossType = crossType;
}

char AcceptedMessage::getOrderState() const {
    return mOrderState;
}

void AcceptedMessage::setOrderState(char orderState) {
    mOrderState = orderState;
}

void AcceptedMessage::display() const {
    OuchMessage::display();

    std::cout << "Order Token: " << mOrderToken << std::endl;
    std::cout << "Side: " << mSide << std::endl;
    std::cout << "Shares: " << mShares << std::endl;
    std::cout << "Symbol: " << mSymbol << std::endl;
    std::cout << "Price: " << mPrice << std::endl;
    std::cout << "Time In Force: " << mTimeInForce << std::endl;
    std::cout << "Firm: " << mFirm << std::endl;
    std::cout << "Display: " << mDisplay << std::endl;
    std::cout << "Order Reference Number: " << mOrderReferenceNumber << std::endl;
    std::cout << "Order Capacity: " << mOrderCapacity << std::endl;
    std::cout << "Inter-Market Sweep: " << mInterMarketSweep << std::endl;
    std::cout << "Minimum Quantity: " << mMinimumQuantity << std::endl;
    std::cout << "Cross Type: " << mCrossType << std::endl;
    std::cout << "Order State: " << mOrderState << std::endl;
}
