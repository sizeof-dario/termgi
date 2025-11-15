#include "termgci.h"

#include <stdio.h>
#include <string.h>
int main()
{

    colour8_t colour = FOREGROUND_BLUE;

    AssignColour(colour, FOREGROUND_RED);

    SetTerminalColour(colour);

    printf("Hello World!\n");

    RestoreTerminalColour();
}