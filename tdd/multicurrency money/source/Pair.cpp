#include "Pair.h"

bool Pair::operator==(const Pair &other) const
{
    return from == other.from && to == other.to;
}
