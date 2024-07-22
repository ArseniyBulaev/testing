#pragma once

#include <string>

#include "Money.h"


class Franc: public Money {
public:
    Franc(int amount): Money(amount, std::string("CHF")) {}
    Money * times(int multiplier) const;
};