#include "Dollar.h"


Dollar Dollar::times(int multiplier) const{
    return Dollar(amount * multiplier);
}

bool Dollar::equal(const Dollar &another_dollar) const
{
    return amount == another_dollar.amount;
}
