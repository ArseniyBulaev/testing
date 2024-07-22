#pragma once

#include <string>

#include "Money.h"

class Dollar: public Money {
public:
    Dollar(int amount, const std::string & currency): Money(amount, currency) {}
    Money * times(int multiplier) const;
};