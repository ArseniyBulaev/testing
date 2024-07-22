#pragma once


class Money
{
protected:
    int amount;
public:
    // factory
    static Money * dollar(int amount);
    static Money * franc(int amount);

    Money(int amount):amount(amount) {}
    bool equals (const Money & another) const;
    bool operator==(const Money & another) const;
    
    // abstract
    virtual Money * times(int multiplier) const = 0;

};


