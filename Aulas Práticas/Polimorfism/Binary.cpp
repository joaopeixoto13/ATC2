#include "Binary.h"

string Binary::toString()
{
    int final = 0, i = 1;
    while (value != 0)
    {
        final += (value % 2) * i;
        value /= 2;
        i *= 10;
    }
    return to_string(final);
}
