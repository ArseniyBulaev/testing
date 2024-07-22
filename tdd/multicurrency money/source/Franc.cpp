#include "Franc.h"


Money * Franc::times(int multiplier) const{
    return new Franc(amount * multiplier);
}
