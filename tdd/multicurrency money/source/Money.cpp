#include "Money.h"

bool Money::equals(const Money &another) const
{
    return amount == another.amount;
}

bool Money::operator==(const Money &another) const
{
    return equals(another);
}