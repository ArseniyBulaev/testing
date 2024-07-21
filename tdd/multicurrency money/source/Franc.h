#pragma once

class Franc {
private:
    int amount;
public:
    Franc(int amount):amount(amount) {}
    Franc times(int multiplier) const;
    bool equal (const Franc & another_Franc) const;
    bool operator==(const Franc & another_Franc) const;
};