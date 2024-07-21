#pragma once

class Money
{
protected:
    int amount;
public:
    Money(int amount):amount(amount) {}
    bool equals (const Money & another) const;
    bool operator==(const Money & another) const;
};


