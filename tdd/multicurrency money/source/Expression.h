#pragma once

#include <string>

class Money;
class Bank;

class Expression {
public:
    virtual ~Expression() = default;
    virtual Money reduce(const Bank & bank, const std::string & to) const = 0;
    virtual Expression * plus(Expression &addend) = 0;
    virtual Expression * times(int multiplier) const = 0;
};
