#include "termgi.h"



void tocolor (
    color_t *const restrict color_p, 
    const int value,
    const layer_t layer
)   
{
    // Prepares color_p.
    clrcpy(color_p, &COLOR_T_TEMPLATE);
    (*color_p)[0] = '\e'; 
    (*color_p)[2] = layer;

    // Extracts value components.
    byte r = RGB_GET_R(value);
    byte g = RGB_GET_G(value);
    byte b = RGB_GET_B(value);

    // Converts value components into characters and completes color_p.
    for (byte i = 0; i < 3; i++)
    {
        // Converts first decimal digit to character, then divides by ten to
        // shift digits towards the right. 
        (*color_p)[9 - i] = r % 10 + '0';
        r /= 10;

        (*color_p)[13 - i] = g % 10 + '0';
        g /= 10;

        (*color_p)[17 - i] = b % 10 + '0';
        b /= 10;
    }
}



int printfc(const char* format, ...)
{   
    // Declare local variables
    int i, j, written, bufsize;
    char *buffer;
    color_t t;
    va_list ap;

    /* Calculate bufsize *******************************************/
    i = 0; // iterate over format
    j = 0; // used as # counter
    while (format[i])
    {
        if (format[i] == '#')
        {
            j++;
        }
        i++;
    }
    bufsize = strlen(format) + COLOR_T_SIZE * j + 10 + 1;
    /***************************************************************/ 

    // Get the buffer
    if(!(buffer = (char*)malloc(bufsize)))
    {
        va_end(ap);
        return -1;
    }

    /* Add colour escape sequences * ↓ *****************/
    i = 0; // iterate over buffer
    j = 0; // iterate over format
    written = 0;
    va_start(ap, format);
    while(i < bufsize && format[j])
    {
        if (format[j] == '#')
        {
            switch (format[j + 1])
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
                buffer[i] = format[j];
                i++;
                j++;
                break;
            }
        }
        else
        {
            buffer[i] = format[j];
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
