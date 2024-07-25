#pragma once

#include <string>
#include <unordered_map>

#include "Money.h"
#include "Expression.h"
#include "Pair.h"

class Bank
{
public:
    Money reduce(const Expression & source, const std::string & to) const;
    void addRate(const std::string from, const std::string to, int rate);
    int rate(const std::string from, const std::string to) const;
private:
    std::unordered_map<Pair, int> rates;
};