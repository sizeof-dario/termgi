#include <stdio.h>

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        printf("You passed %s (%d) arguments. You need to pass o:\n", argc == 1 ? "not enough" : "too many", argc - 1);
        printf("0 -> 8 colours set\n"
               "1 -> 16 colours set\n"
               "2 -> 256 colours set\n"
               "3 - > 24 bit colours set\n");
        return 1;
    }

    char colour8[] = "\e[4_m";

    switch (*argv[1])
    {
    case '0': // 8 colours
        for (char i = '0'; i < '8'; i++)
        {
            colour8[3] = i;
            printf("%s  ", colour8);
        }
        colour8[3] = '9';
        printf("%s\n", colour8);
        break;
    
    default:
        break;
    }
}