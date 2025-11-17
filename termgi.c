#include "termgi.h"

void tocolourseq(colourseq_t seq, int colour, layer_t layer)
{
    strcpy(seq, "\e[08;2;000;000;000m");
    seq[2] = layer;
    unsigned char r = (unsigned char)(colour >> 16);
    unsigned char g = (unsigned char)(colour >>  8);
    unsigned char b = (unsigned char)colour;


    for (unsigned char i = 0; i < 3; i++)
    {
        seq[9 - i] = r % 10 + 48;
        r /= 10;

        seq[13 - i] = g % 10 + 48;
        g /= 10;

        seq[17 - i] = b % 10 + 48;
        b /= 10;
    }
}

int printfc(const char* format_and_colour, ...)
{
    
    int i = 0;
    int j = 0;
    char seq[20];

    char *buffer = (char*)malloc(4096);
    memset(buffer, '\0', 4096);

    va_list ap;
    va_start(ap, format_and_colour);

    while(i < 4096 && format_and_colour[j])
    {
        if(format_and_colour[j] == '#' && format_and_colour[j + 1] != '#')
        {
            tocolourseq(seq, va_arg(ap, int), format_and_colour[j + 1] == 'f' ? FOREGROUND : BACKGROUND);
            strcpy(buffer + i, seq);
            i += 19;
            j += 2;
        }

        if(format_and_colour[j] == '#' && format_and_colour[j + 1] == '#')
        {
            buffer[i] = format_and_colour[j];
            i++;
            j += 2;
        }

        buffer[i] = format_and_colour[j];

        i++;
        j++;
    }

    i += vprintf(buffer, ap);

    va_end(ap);
    return i;
}