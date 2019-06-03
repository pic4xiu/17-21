#include <stdio.h>
#define ABS(x) ((x) > 0 ? (x) : -(x))

int main()
{
    double a = 3, b = 3; /*菱形宽度和高度的一半*/
    int i, j;
    for (i = -a; i <= a; ++i) {
        for (j = -b; j <= b; ++j)
            putchar((ABS(i)/a + ABS(j)/b > 1) ? ' ' : '*');
        putchar('\n');
    }
    return 0;
}
