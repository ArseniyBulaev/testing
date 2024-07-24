#pragma once
#include <string>

#include "Expression.h"

class Money: public Expression
{
protected:
    int amount;
    const std::string _currency;
public:
    // factory
    static Money dollar(int amount);
    static Money franc(int amount);

    Money(int amount, const std::string & currency):amount(amount), _currency(currency) {}
    bool equals (const Money & another) const;
    bool operator==(const Money & another) const;
    
    virtual Money times(int multiplier) const;
    virtual const std::string & currency() const;

    Expression plus(const Money & addend) const;

};


