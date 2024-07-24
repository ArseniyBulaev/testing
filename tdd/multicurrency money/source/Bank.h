#pragma once

#include <string>

#include "Money.h"
#include "Expression.h"

class Bank
{
public:
    Money reduce(const Expression & source, const std::string & to) const;
};