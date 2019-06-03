#include <stdio.h>
int main()
{
    int x;
    scanf("%d", &x);
    for (int y = 2; y <= x; y++)
    {
        if (x % y == 0)
        {
            x = x / y;
            printf("%d\t", y);
            y = 1;
        }
    }
    return 0;
}
