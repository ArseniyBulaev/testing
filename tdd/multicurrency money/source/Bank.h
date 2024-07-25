#pragma once

#include <string>

#include "Money.h"
#include "Expression.h"

class Bank
{
public:
    Money reduce(const Expression & source, const std::string & to) const;
    void addRate(const std::string from, const std::string to, int rate);
    int rate(const std::string from, const std::string to) const;
};