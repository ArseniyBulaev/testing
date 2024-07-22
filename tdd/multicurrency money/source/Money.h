#pragma once
#include <string>


class Money
{
protected:
    int amount;
    const std::string _currency;
public:
    // factory
    static Money * dollar(int amount);
    static Money * franc(int amount);

    Money(int amount, const std::string & currency):amount(amount), _currency(currency) {}
    bool equals (const Money & another) const;
    bool operator==(const Money & another) const;
    
    // abstract
    virtual Money * times(int multiplier) const = 0;
    virtual const std::string currency() const;

};


