#ifndef EXECUTED_MESSAGE_HEADER_H
#define EXECUTED_MESSAGE_HEADER_H

#include <string>
#include "ouch_message.hpp"

class ExecutedMessage : public OuchMessage {                      
    char mOrderToken[15];        
    unsigned int mExecutedShares;
    unsigned int mExecutedPrice;
    char mLiquidityFlag;
    unsigned long long mMatchNumber;

    public:
    // Constructors
    ExecutedMessage();
    ExecutedMessage(unsigned short length, unsigned long long timestamp);
    virtual ~ExecutedMessage();

    // Getters and Setters
    const char* getOrderToken() const;
    void setOrderToken(const char* orderToken);

    unsigned int getExecutedShares() const;
    void setExecutedShares(unsigned int executedShares);

    unsigned int getExecutedPrice() const;
    void setExecutedPrice(unsigned int executedPrice);

    char getLiquidityFlag() const;
    void setLiquidityFlag(char liquidityFlag);

    unsigned long long getMatchNumber() const;
    void setMatchNumber(unsigned long long matchNumber);

    // Display
    void display() const;
};

#endif // EXECUTED_MESSAGE_HEADER_H