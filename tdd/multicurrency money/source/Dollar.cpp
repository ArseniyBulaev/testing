#include "Dollar.h"


Money * Dollar::times(int multiplier) const{
    return new Dollar(amount * multiplier);
}


