#include "termgi.h"

void tocolour(colour_t colour, int value, layer_t layer)
{
    strcpy(colour, "\e[08;2;000;000;000m");
    colour[2] = layer;

    unsigned char r = (unsigned char)(value >> 16);
    unsigned char g = (unsigned char)(value >>  8);
    unsigned char b = (unsigned char)value;

    for (unsigned char i = 0; i < 3; i++)
    {
        colour[9 - i] = r % 10 + 48;
        r /= 10;

        colour[13 - i] = g % 10 + 48;
        g /= 10;

        colour[17 - i] = b % 10 + 48;
        b /= 10;
    }
}

int printfc(const char* format_and_colour, ...)
{
    
    int i = 0;
    int j = 0;
    int written = 0;
    colour_t t = { 0 };
    size_t bufsizeexcess = 0;

    while (format_and_colour[i])
    {
        if (format_and_colour[i] == '#')
        {
            bufsizeexcess++;
        }
        i++;
    }
    i = 0;

    char *buffer = (char*)malloc(strlen(format_and_colour) + 20 * bufsizeexcess + 10 + 1);

    va_list ap;
    va_start(ap, format_and_colour);

    while(i < strlen(format_and_colour) + 20 * bufsizeexcess + 1 && format_and_colour[j])
    {
        if (format_and_colour[j] == '#')
        {
            switch (format_and_colour[j + 1])
            {
            case 'f':
            case 'F':
                tocolour(t, va_arg(ap, int), FOREGROUND);
                strcpy(buffer + i, t);
                i += 19;
                j += 2;
                written -= 19;
                break;
            
            case 'b':
            case 'B':
                tocolour(t, va_arg(ap, int), BACKGROUND);
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

    written += vprintf(buffer, ap) - 10;

    va_end(ap);
    free(buffer);
    return written;
}
