#ifndef CANCELED_MESSAGE_HEADER_H
#define CANCELED_MESSAGE_HEADER_H

#include "ouch_message.hpp"

class CanceledMessage : public OuchMessage {                      
    char mOrderToken[15];        
    unsigned int mDecrementShares;
    char mReason;
    
    public:
    // Constructors
    CanceledMessage();
    CanceledMessage(unsigned short length, unsigned long long timestamp);
    ~CanceledMessage();

    // Getter and Setter for orderToken
    const char* getOrderToken() const;
    void setOrderToken(const char* orderToken);

    // Getter and Setter for decrementShares
    unsigned int getDecrementShares() const;
    void setDecrementShares(unsigned int decrementShares);

    // Getter and Setter for reason
    char getReason() const;
    void setReason(char reason);

    // Display
    void display() const;
};

#endif // CANCELED_MESSAGE_HEADER_H