#include <typeinfo>

#include "Money.h"
#include "Dollar.h"
#include "Franc.h"

Money * Money::dollar(int amount)
{
    return new Dollar(amount);
}

Money *Money::franc(int amount)
{
    return new Franc(amount);
}

bool Money::equals(const Money &another) const
{
    return (amount == another.amount) && (typeid(another) == typeid(*this));
}

bool Money::operator==(const Money &another) const
{
    return equals(another);
}

const std::string & Money::currency() const
{
    return _currency;
}
