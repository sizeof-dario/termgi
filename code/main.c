#include "termgci.h"

#include <stdio.h>

int main()
{
    SetTerminalColour(FOREGROUND_BRIGHT_YELLOW);

    printf("Hello World!\n");
    
    RestoreTerminalColour();
}