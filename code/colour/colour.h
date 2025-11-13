/**
 * @file colour.h
 * 
 * @brief Umbrella header for the colour*.h files.
 * 
 * @details 
 * 
 * @link https://github.com/sizeof-dario/termgci.git @endlink
 * 
 */

#ifndef COLOUR_H
#define COLOUR_H

#include "colour16.h"
#include "colour256.h"
#include "colour24b.h"

typedef union colour
{
    colour16_t c16;
    colour256_t c256;
    colour24b_t c24b;
} colour_t;

#endif // COLOUR_H