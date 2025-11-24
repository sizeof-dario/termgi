
/*************************************************************************//***
 * @file termgi.h
 * 
 * @brief Master header file for the TermGI library.
 * 
 * Applications should include this header to access all TermGI definitions of 
 * macros, types and functions.
 * 
 ******************************************************************************/

#ifndef TERMGI_H
#define TERMGI_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/** @brief Single byte (0-255). */
typedef unsigned char byte;



/** 
 * @brief Double word (4 bytes).
 * 
 * 4-byte size guaranteed via static assertion.
*/
typedef unsigned int dword;



// Guarantees dword's size is 4 bytes.
_Static_assert(sizeof(dword) == 4, "dword must be 4 bytes.");



/**
 * @brief Size of a `color_t` storing a 24-bit color escape sequence.
 * 
 * A value of 20 is chosen to accommodate for the maximum length such sequences
 * can reach, including the null-terminator.
 * 
 */
#define COLOR_T_SIZE 20



/**
 * @brief Represents an escape sequence used to change colors in terminals that
 *      support 24-bit colors.
 * 
 * Such sequences take the form "E[L8;2;R;G;Bm", where
 * 
 *      - E is the escape character.
 * 
 *      - L is either 3 (for foreground) or 4 (for background).
 * 
 *      - R, G and B are respectively the red, green and blue components of the
 *        represented color.
 * 
 * The sequence is stored as a null-terminated string of length `COLOR_T__SIZE`.
 * 
 */
typedef char color_t[COLOR_T_SIZE];



/** 
 * @brief Template string used by the `tocolor` function to build a color
 *      sequence based on the provided arguments.
 * 
 * The initial null-terminator makes the literal unusable as a regular C string,
 * ensuring that it is accessed only through explicit manipulation.
 * 
 */
#define COLOR_T_TEMPLATE "\0[08;2;000;000;000m"



/**
 * @brief Copies source `color_t` to destination `color_t`.
 * 
 * @param destination A pointer to the `color_t` to copy to.
 * @param source A pointer to the `color_t` to copy from.
 * @return A pointer to destination after the copy.
 * 
 * @note Since `color_t` is defined to be a 20-characters-long array, this
 *      function really works as a null-terminator-ignoring `strcpy` over
 *      20-characters-long C strings. Thus, it can be used to work with
 *      `COLOR_T_TEMPLATE`.
 */
static inline color_t *clrcpy (
    color_t *const restrict destination,
    const color_t *const restrict source
)   
{
    for (byte i = 0; i < COLOR_T_SIZE; i++)
    {
        (*destination)[i] = (*source)[i];
    }
}



/**
 * @brief Specifies the terminal layer for functions using `color_t`.
 *
 * This type is used to indicate whether a color should be applied to the
 * foreground or the background.
 * 
 */
typedef enum layer { 
    FOREGROUND = '3', /**< Foreground layer. */
    BACKGROUND = '4'  /**< Background layer. */
} layer_t;



/** Extracts the red component from a 24-bit RGB color value. */
#define RGB_GET_R(x) (byte)(x >> 16)



/** Extracts the green component from a 24-bit RGB color value. */
#define RGB_GET_G(x) (byte)(x >> 8)



/** Extracts the blue component from a 24-bit RGB color value. */
#define RGB_GET_B(x) (byte)(x)



/**
 * @brief Converts a 24-bit RGB color value into a `color_t` type.
 * 
 * @param color_p A pointer to a `color_t` to store the conversion result.
 * @param value The 24-bit RGB value of the color to convert.
 * @param layer The terminal layer of the color to convert, either being
 *      `FOREGROUND` or `BACKGROUND`.
 * 
 */
void tocolor (
    color_t *const restrict color_p, 
    const int value, 
    const layer_t layer
);



/**
 * @brief Writes formatted and colorized output to stdout.
 *      
 * @param format A format string that may contain both printf-like format
 *      specifiers (%) and color specifiers (#).
 *
 *      - Format specifiers behave like those of printf, except that the
 *        character '#' is reserved. To obtain the literal behaviour used by
 *        printf, each '#' must be doubled as '##'.
 *
 *      - Color specifiers indicate foreground or background color changes: a #f
 *        or #F allows to change the foreground color, while a #b or #B is used
 *        for background.
 *        A literal '#' character is written using '##', analogous to how printf
 *        uses '%%' for a literal '%'.
 *
 * @param ... If the format string contains any specifiers, the function expects
 *      additional arguments. All color values – as RGB values – must appear
 *      first, in the same order as their corresponding color specifiers in the
 *      format string. After these, the remaining arguments correspond to the
 *      printf-like format specifiers, following the same rules as printf.
 *
 * @return The number of characters written to stdout, excluding any color
 *      control sequences.
 *
 * @note Color sequences do not count toward the return value.
 * 
 * @warning Passing arguments in the wrong order results in undefined behaviour.
 * 
 */
int printfc(const char *format, ...);



/**
 * @brief Converts independent red, green and blue components to a whole RGB
 *      color value.
 *  
 * @param r Red component (0-255).
 * @param g Green component (0-255).
 * @param b Blue component (0-255).
 * 
 * @return The color of RGB components r, g and b as a 24-bit unsigned int.
 * 
 */
#define RGB(r, g, b) \
    (((dword)(byte)(r) << 16) | ((dword)(byte)(g) << 8) | (dword)(byte)(b))



#endif // TERMGI_H

