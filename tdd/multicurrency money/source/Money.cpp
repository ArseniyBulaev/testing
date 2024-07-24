#include <typeinfo>

#include "Money.h"

Money Money::dollar(int amount)
{
    return Money(amount, std::string("USD"));
}

Money Money::franc(int amount)
{
    return Money(amount, std::string("CHF"));
}

bool Money::equals(const Money &another) const
{
    return (amount == another.amount) && (another._currency == _currency);
}

bool Money::operator==(const Money &another) const
{
    return equals(another);
}

Money Money::times(int multiplier) const
{
    return Money(amount * multiplier, _currency);
}

const std::string &Money::currency() const
{
    return _currency;
}

Expression Money::plus(const Money &addend) const
{
    return Money(amount + addend.amount, _currency);
}
