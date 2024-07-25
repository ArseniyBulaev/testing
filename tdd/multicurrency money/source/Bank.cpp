#include "Bank.h"
#include "Sum.h"

#include <typeinfo>

Money Bank::reduce(const Expression & source, const std::string &to) const
{
    return source.reduce(*this, to);
}

void Bank::addRate(const std::string from, const std::string to, int rate)
{
    rates[Pair(from, to)] = rate;
}

int Bank::rate(const std::string from, const std::string to) const
{
    if(from == to) return 1;
    return rates.at(Pair(from, to));
}
