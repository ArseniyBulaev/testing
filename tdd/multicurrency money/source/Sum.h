#pragma once

#include <string>

#include "Money.h"
#include "Expression.h"

class Sum: public Expression {
public:
    Money augend;
    Money addend;
    Sum(Money augend, Money addend):augend(augend), addend(addend) {}
    Money reduce(const Bank & bank, const std::string & to) const override;
};