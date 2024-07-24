#pragma once

#include <string>

#include "Money.h"
#include "Expression.h"

class Bank
{
public:
    Money reduce(Expression source, const std::string & to) const;
};