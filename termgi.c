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
    /** vvv * Calculates bufsize **********************************************/

    int hashcount = 0;
    for (int i = 0; format[i]; i++)
    {
        if (format[i] == '#')
        {
            hashcount++;
        }
    }
    
    int bufsize = strlen(format) 
        + COLOR_T_LENGTH * hashcount 
        + DEFAULT_COLORS_SEQUENCE_LENGTH;

    /** ^^^ * Calculates bufsize **********************************************/

    // Gets the buffer.
    char *buffer = (char*)malloc(bufsize);
    if(!buffer) return -1;

    /** vvv * Color formatting ************************************************/

    int bufidx = 0; // Index iterating over the buffer.
    int ftmidx = 0; // Index iterating over the format string.
    int written = 0;
    color_t temp_color;
    va_list ap;
    va_start(ap, format);
    while(bufidx < bufsize && format[ftmidx])
    {
        if (format[ftmidx] == '#')
        {
            switch (format[ftmidx + 1])
            {
            case 'f':
            case 'F':
                tocolor(&temp_color, va_arg(ap, int), FOREGROUND);
                strcpy(buffer + bufidx, temp_color);
                bufidx += COLOR_T_LENGTH - 1; // Excluding the null-terminator.
                ftmidx += 2;
                written -= COLOR_T_LENGTH - 1;
                break;
            
            case 'b':
            case 'B':
                tocolor(&temp_color, va_arg(ap, int), BACKGROUND);
                strcpy(buffer + bufidx, temp_color);
                bufidx += COLOR_T_LENGTH - 1;
                ftmidx += 2;
                written -= COLOR_T_LENGTH - 1;
                break;

            case '#':
                buffer[bufidx] = '#';
                bufidx++;
                ftmidx += 2;
                break;

            default:
                buffer[bufidx] = format[ftmidx];
                bufidx++;
                ftmidx++;
                break;
            }
        }
        else
        {
            buffer[bufidx] = format[ftmidx];
            bufidx++;
            ftmidx++;
        }
    }

    strcpy(buffer + bufidx, DEFAULT_COLORS_SEQUENCE);

    /** ^^^ * Color formatting ************************************************/

    // Calls vprintf and updates written. The +1 is needed to exclude the final
    // null-terminator that is othewise counted with 
    // `DEFAULT_COLORS_SEQUENCE_LENGTH`.
    written += vprintf(buffer, ap) - DEFAULT_COLORS_SEQUENCE_LENGTH + 1;

    // Cleans and return
    va_end(ap);
    free(buffer);
    return written;
}
