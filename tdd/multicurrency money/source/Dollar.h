#pragma once

#include "Money.h"

class Dollar: public Money {
public:
    Dollar(int amount): Money(amount, std::string("USD")) {}
    Money * times(int multiplier) const;
};