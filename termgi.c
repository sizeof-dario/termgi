#include "termgi.h"

void tocolor (
    color_t *const restrict color_p, 
    const int value, 
    const layer_t layer
)
{
    strcpy(*color_p, "\e[08;2;000;000;000m");
    (*color_p)[2] = layer;

    unsigned char r = (unsigned char)(value >> 16);
    unsigned char g = (unsigned char)(value >>  8);
    unsigned char b = (unsigned char)value;

    for (unsigned char i = 0; i < 3; i++)
    {
        (*color_p)[9 - i] = r % 10 + 48;
        r /= 10;

        (*color_p)[13 - i] = g % 10 + 48;
        g /= 10;

        (*color_p)[17 - i] = b % 10 + 48;
        b /= 10;
    }
}

int printfc(const char* format_and_colour, ...)
{   
    // Declare local variables
    int i, j, written, bufsize;
    char *buffer;
    color_t t;
    va_list ap;

    /* Calculate bufsize *******************************************/
    i = 0; // iterate over format_and_colour
    j = 0; // used as # counter
    while (format_and_colour[i])
    {
        if (format_and_colour[i] == '#')
        {
            j++;
        }
        i++;
    }
    bufsize = strlen(format_and_colour) + COLOR_T__SIZE * j + 10 + 1;
    /***************************************************************/ 

    // Get the buffer
    if(!(buffer = (char*)malloc(bufsize)))
    {
        va_end(ap);
        return -1;
    }

    /* Add colour escape sequences * ↓ *****************/
    i = 0; // iterate over buffer
    j = 0; // iterate over format_and_colour
    written = 0;
    va_start(ap, format_and_colour);
    while(i < bufsize && format_and_colour[j])
    {
        if (format_and_colour[j] == '#')
        {
            switch (format_and_colour[j + 1])
            {
            case 'f':
            case 'F':
                tocolor(&t, va_arg(ap, int), FOREGROUND);
                strcpy(buffer + i, t);
                i += 19;
                j += 2;
                written -= 19;
                break;
            
            case 'b':
            case 'B':
                tocolor(&t, va_arg(ap, int), BACKGROUND);
                strcpy(buffer + i, t);
                i += 19;
                j += 2;
                written -= 19;
                break;

            case '#':
                buffer[i] = '#';
                i++;
                j += 2;
                break;

            default:
                buffer[i] = format_and_colour[j];
                i++;
                j++;
                break;
            }
        }
        else
        {
            buffer[i] = format_and_colour[j];
            i++;
            j++;
        }
    }
    strcpy(buffer + i, "\e[39m\e[49m");
    /* Add colour escape sequences * ↑ *****************/

    // Call vprintf
    written += vprintf(buffer, ap) - 10;

    // Clean and return
    va_end(ap);
    free(buffer);
    return written;
}
