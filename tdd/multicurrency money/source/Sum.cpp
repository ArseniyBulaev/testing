#include "Sum.h"
#include <typeinfo>

Money Sum::reduce(const Bank & bank, const std::string &to) const
{
    bool is_augend_money = typeid(augend) == typeid(Money);
    int amount = augend.reduce(bank, to).amount + addend.reduce(bank, to).amount;
    return Money(amount, to);
}

Expression *Sum::plus(Expression &addend) 
{
    return nullptr;
}
