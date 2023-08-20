#include <common/types.h>

std::ostream& operator<<(std::ostream& os, const byte& byte)
{
    os << +byte;
    return os;
}
