#include "termgi.h"

int main()
{
    printfc("#fHello #f%s#f! #b##%d\n", 
        RGB(255, 0, 0), RGB(0, 255, 0), RGB(255, 255, 255), RGB(0, 0, 255), 
        "World", 128);

}



