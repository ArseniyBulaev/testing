#pragma once

#include <string>

#include "Money.h"
#include "Expression.h"

class Sum: public Expression {
public:
    Expression & augend;
    Expression & addend;
    Sum(Expression & augend, Expression & addend):augend(augend), addend(addend) {}
    Money reduce(const Bank & bank, const std::string & to) const override;
    Expression * plus(Expression & addend) override;
};