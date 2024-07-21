#pragma once

class Dollar {
public:
    int amount;
    Dollar(int amount):amount(amount) {}
    Dollar times(int multiplier) const;
    bool equal (const Dollar & another_dollar) const;
};