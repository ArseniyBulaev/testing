#pragma once

#include <string>

class Money;

class Expression {
public:
    virtual ~Expression() = default;
    virtual Money reduce(const std::string & to) const = 0;
};
