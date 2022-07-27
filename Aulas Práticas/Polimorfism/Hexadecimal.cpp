#include "Hexadecimal.h"

string Hexadecimal::toString()
{
    int final = 0, i = 1;
    while (value != 0)
    {
        final += (value % 16) * i;
        value /= 16;
        i *= 10;
    }
    return "0x" + to_string(final);
}
