#include "Octal.h"

string Octal::toString()
{
    int final = 0, i = 1;
    while (value != 0)
    {
        final += (value % 8) * i;
        value /= 8;
        i *= 10;
    }
    return "0" + to_string(final);
}
