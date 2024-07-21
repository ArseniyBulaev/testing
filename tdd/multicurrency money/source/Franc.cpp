#include "Franc.h"


Franc Franc::times(int multiplier) const{
    return Franc(amount * multiplier);
}

bool Franc::equal(const Franc &another) const
{
    return amount == another.amount;
}

bool Franc::operator==(const Franc &another) const
{
    return equal(another);
}
