#include <typeinfo>

#include "Money.h"
#include "Sum.h"

Money Money::dollar(int amount)
{
    return Money(amount, std::string("USD"));
}

Money Money::franc(int amount)
{
    return Money(amount, std::string("CHF"));
}

bool Money::equals(const Money &another) const
{
    return (amount == another.amount) && (another._currency == _currency);
}

bool Money::operator==(const Money &another) const
{
    return equals(another);
}

Expression * Money::times(int multiplier) const
{
    return new Money(amount * multiplier, _currency);
}

const std::string &Money::currency() const
{
    return _currency;
}

Expression * Money::plus(Expression &addend) 
{
    return new Sum(*this, addend);
}

Money Money::reduce(const Bank & bank, const std::string &to) const
{
    int rate = bank.rate(_currency, to);
    return Money(amount/rate, to);
}
