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
typedef char colourseq_t[20];

void tocolourseq(colourseq_t seq, int colour, layer_t layer);

// Write formatted and coloured output to stdout.
int printfc(const char *format_and_colour, ...);

#endif // TERMGI_H