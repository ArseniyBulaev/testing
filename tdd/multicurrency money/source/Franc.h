#pragma once

#include "Money.h"

class Franc: public Money {
public:
    Franc(int amount):Money(amount) {}
    Franc times(int multiplier) const;
};