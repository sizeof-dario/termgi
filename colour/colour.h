#ifndef COLOUR_H
#define COLOUR_H

#include <stdarg.h>
#include <stdio.h>

#include "colour16.h"
#include "colour256.h"
#include "colour24bit.h"

typedef char *colour_t;

static inline void cpyclr(colour_t dest, const colour_t src)
{
    for (unsigned char i = 0; src[i]; i++)
    {
        dest[i] = src[i];
    }
}

static inline int settermclr(const colour_t colour)
{
    return printf("%s", colour);
}

static inline int rsttermclr()
{
    return printf("%s%s", FOREGROUND_DEFAULT, BACKGROUND_DEFAULT);
}

static inline int printfc(const colour_t foreground_colour, const colour_t background_colour, const char* const format, ...)
{
    va_list argument_pointer;
    
    settermclr(foreground_colour);
    settermclr(background_colour);
    va_start(argument_pointer, format);
    vprintf(format, argument_pointer);
    va_end(argument_pointer);
    rsttermclr();
}

#endif // COLOUR_H