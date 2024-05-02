#ifndef REPLACED_MESSAGE_HEADER_H
#define REPLACED_MESSAGE_HEADER_H

#include <string>
#include "ouch_message.hpp"

class ReplacedMessage : public OuchMessage {                      
    char mOrderToken[15];        
    char mSide;  
    unsigned int mShares;
    char mSymbol[9];
    unsigned int mPrice;
    unsigned int mTimeInForce;
    char mFirm[5];
    char mDisplay;

    public:
    // Constructors
    ReplacedMessage();
    ReplacedMessage(unsigned short length, unsigned long long timestamp);
    virtual ~ReplacedMessage();

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

    // Display
    void display() const;
};

#endif // REPLACED_MESSAGE_HEADER_H