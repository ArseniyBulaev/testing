#pragma once

class Dollar {
public:
    int amount;
    Dollar(int amount):amount(amount) {}
    void times(int multiplier);

};