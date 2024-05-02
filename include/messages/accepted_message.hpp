#ifndef ACCEPTED_MESSAGE_HEADER_H
#define ACCEPTED_MESSAGE_HEADER_H

#include <string>
#include "ouch_message.hpp"

class AcceptedMessage : public OuchMessage {               
    char mOrderToken[15];        
    char mSide;  
    unsigned int mShares;
    char mSymbol[9];
    unsigned int mPrice;
    unsigned int mTimeInForce;
    char mFirm[5];
    char mDisplay;
    unsigned long mOrderReferenceNumber;
    char mOrderCapacity;
    char mInterMarketSweep;
    unsigned int mMinimumQuantity;
    char mCrossType;
    char mOrderState;

    public:
    // Constructor
    AcceptedMessage();
    AcceptedMessage(unsigned short length, unsigned long long timestamp);
    ~AcceptedMessage();

    // Getters and Setters
    const char* getOrderToken() const;
    void setOrderToken(const char* orderToken);

    char getSide() const;
    void setSide(char side);

    unsigned int getShares() const;
    void setShares(unsigned int shares);

    const char* getSymbol() const;
    void setSymbol(const char* symbol);

    unsigned int getPrice() const;
    void setPrice(unsigned int price);

    unsigned int getTimeInForce() const;
    void setTimeInForce(unsigned int timeInForce);

    const char* getFirm() const;
    void setFirm(const char* firm);

    char getDisplay() const;
    void setDisplay(char display);

    unsigned long getOrderReferenceNumber() const;
    void setOrderReferenceNumber(unsigned long orderReferenceNumber);

    char getOrderCapacity() const;
    void setOrderCapacity(char orderCapacity);

    char getInterMarketSweep() const;
    void setInterMarketSweep(char interMarketSweep);

    unsigned int getMinimumQuantity() const;
    void setMinimumQuantity(unsigned int minimumQuantity);

    char getCrossType() const;
    void setCrossType(char crossType);

    char getOrderState() const;
    void setOrderState(char orderState);

    void display() const;
};

#endif // ACCEPTED_MESSAGE_HEADER