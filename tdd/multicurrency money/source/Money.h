#pragma once
#include <string>

#include "Expression.h"
#include "Bank.h"

class Money: public Expression
{
protected:
    const std::string _currency;
public:
    int amount;
    // factory
    static Money dollar(int amount);
    static Money franc(int amount);

    Money(int amount, const std::string & currency):amount(amount), _currency(currency) {}
    bool equals (const Money & another) const;
    bool operator==(const Money & another) const;
    
    virtual Money times(int multiplier) const;
    virtual const std::string & currency() const;

    Expression * plus(const Money & addend) const;
    Money reduce(const Bank & bank, const std::string & to) const override;

};


