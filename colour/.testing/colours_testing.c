#include <stdio.h>

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        printf("You passed %s (%d) arguments. You need to pass one.\n", argc == 1 ? "not enough" : "too many", argc - 1);
        return 1;
    }

    // index:      0 1234
    char c16f[] = "\e[3_m";
    char c16b[] = "\e[4_m";

    // index:       0 1234
    char c16bf[] = "\e[9_m";

    // index:       0 12345
    char c16bb[] = "\e[10_m";

    switch (*argv[1])
    {
    case '0': // colour16
        printf("                                           Bright              Bright\n");
        printf(" Foreground          Background          foreground          background\n\n");
        for (char i = '0'; i < '8'; i++)
        {
            c16f[3] = i;
            c16b[3] = i;
            printf("%sHello World!%s        %sHello World!%s        ", c16f, "\e[0m", c16b, "\e[0m");

            c16bf[3] = i;
            c16bb[4] = i;
            printf("%sHello World!%s        %sHello World!%s\n", c16bf, "\e[0m", c16bb, "\e[0m");
        }
        
        break;
    
    default:
        break;
    }
}