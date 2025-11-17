
#include "termgi.h"

int main()
{
    printfc("\n#fI can both use %s and #fcolour specifiers#f (I guess that's how I'm calling them)\n\n", 0xffff00, RGB(255, 0, 0), 0xFFFF00, "format specifiers");
}


