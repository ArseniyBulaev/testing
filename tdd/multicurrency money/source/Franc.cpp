#include "Franc.h"


Franc Franc::times(int multiplier) const{
    return Franc(amount * multiplier);
}

