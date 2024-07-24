#include "Bank.h"
#include "Sum.h"

#include <typeinfo>

Money Bank::reduce(const Expression & source, const std::string &to) const
{
    return source.reduce(to);
}
