#include <common/types.h>

std::ostream& operator<<(std::ostream& os, const byte& byte)
{
    os << +byte;
    return os;
}

std::ostream& operator<<(std::ostream& os, const word& word)
{
    os << +word;
    return os;
}