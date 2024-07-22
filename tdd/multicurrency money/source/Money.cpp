#include <typeinfo>

#include "Money.h"
#include "Dollar.h"
#include "Franc.h"

Money * Money::dollar(int amount)
{
    return new Dollar(amount, std::string("USD"));
}

Money *Money::franc(int amount)
{
    return new Franc(amount, std::string("CHF"));
}

bool Money::equals(const Money &another) const
{
    return (amount == another.amount) && (another._currency == _currency);
}

bool Money::operator==(const Money &another) const
{
    return equals(another);
}

Money *Money::times(int multiplier) const
{
    return new Money(amount * multiplier, _currency);
}

const std::string &Money::currency() const
{
    return _currency;
}
