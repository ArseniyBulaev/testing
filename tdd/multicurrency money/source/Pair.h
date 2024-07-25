#pragma once

#include <string>

class Pair
{
private:
    const std::string & from;
    const std::string & to;
public:
    Pair(const std::string & from, const std::string & to):from(from), to(to) {};
    bool operator==(const Pair &other) const;
};

template <>
struct std::hash<Pair>
{
  std::size_t operator()(const Pair& k) const
  {
    return 0;
  }
};