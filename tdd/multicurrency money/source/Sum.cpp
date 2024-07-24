#include "Sum.h"

Money Sum::reduce(const std::string &to) const
{
    int amount = augend.amount + addend.amount;
    return Money(amount, to);
}
