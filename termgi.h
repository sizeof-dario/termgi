/*************************************************
 * 
 *      termgi.h
 * 
 *          Master header for termGI applications.
 * 
 *************************************************/

#ifndef TERMGI_H
#define TERMGI_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define RGB(r, g, b) \
    (((unsigned int)(unsigned char)r << 16) | \
     ((unsigned int)(unsigned char)g << 8)  | \
      (unsigned int)(unsigned char)b)

typedef enum layer { FOREGROUND = '3', BACKGROUND = '4' } layer_t;

#define COLOUR_LENGTH 20
typedef char colour_t[COLOUR_LENGTH];

// Convert a colour value to a 24bit colour sequence.
void tocolour(colour_t colour, int value, layer_t layer);

// Write formatted and coloured output to stdout.
//
// Accepts format specifiers % as printf, but also colour specifiers #.
// Use #f or #F for specifying a foreground colour, #b or #B for a background one.
// After the format_and_colour argument, first list all the colour values and then the format specifier arguments.
//
// (For examples of usage, check the repo README)
int printfc(const char *format_and_colour, ...);

#endif // TERMGI_H