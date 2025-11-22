#ifdef __unix__

#include "io-linux.h"

char pegarInput ()
{
    char in = getch();

    if (in == ERR)
        return '\0';
    else
        return in;
}

#endif
