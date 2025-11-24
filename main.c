#include "termgi.h"

#include <string.h>

int main()
{
    printfc("#f\"#f%s#f\" but it's a #fT#fe#fr#fm#fG#fI #fapplication!\n",
        0xffffff, RGB(125, 125, 125), 0xffffff, 0xff0000, 0xffff00, 0x00ff00, 0x00ffff, 0x0000ff, 0xff00ff, 0xffffff,
        "Hello World!"
    );

}

