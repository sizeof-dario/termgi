#ifndef COLOUR_H
#define COLOUR_H

#include <stdio.h>

#include "colour16.h"
#include "colour256.h"
#include "colour24b.h"

typedef char *colour_t;

typedef enum colourset
{
    COLOUR8, 
    COLOUR16, 
    COLOUR256, 
    COLOUR24B
} colourset_t;

void colour8_to_16(colour16_t destination, colour8_t source);
void colour16_to_256(colour256_t destination, colour8_t source);
void colour256_to_24b(colour24b_t destination, colour256_t source);

int colour24b_to_256(colour256_t destination, colour24b_t source);
int colour256_to_16(colour16_t destination, colour256_t source);
int colour16_to_8(colour8_t destination, colour16_t source);

void copy_colour(colour_t destination, colour_t source);

int copy_colour_safe(colour_t destination, colourset_t destination_set, colour_t source, colourset_t source_set);

static inline int set_terminal_colour(colour_t colour)
{
    return printf("%s", colour);
}

static inline int restore_terminal_colour()
{
    return printf("%s%s", FOREGROUND_DEFAULT, BACKGROUND_DEFAULT);
}

#endif // COLOUR_H