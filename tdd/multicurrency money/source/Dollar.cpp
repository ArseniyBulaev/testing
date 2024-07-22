#include "Dollar.h"


Money * Dollar::times(int multiplier) const{
    return Dollar::dollar(amount * multiplier);
}

