#pragma once

#include <string>

#include "Money.h"


class Franc: public Money {
public:
    Franc(int amount, const std::string & currency): Money(amount, currency) {}
};