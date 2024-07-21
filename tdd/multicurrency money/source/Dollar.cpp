#include "Dollar.h"


Dollar Dollar::times(int multiplier) const{
    return Dollar(amount * multiplier);
}


