#pragma once

#include "Money.h"

class Dollar: public Money {
public:
    Dollar(int amount): Money(amount) {}
    Money * times(int multiplier) const;
};