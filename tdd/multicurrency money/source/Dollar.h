#pragma once

class Dollar {
private:
    int amount;
public:
    Dollar(int amount):amount(amount) {}
    Dollar times(int multiplier) const;
    bool equal (const Dollar & another_dollar) const;
    bool operator==(const Dollar & another_dollar) const;
};