#include <stdio.h>
int main()
{
    float x = 1, y = 2, tmp, sum = 0;
    for (int i = 1; i <= 20; i++)
    {
        sum = sum + y / x;
        tmp = y;
        y = x + y;
        x = tmp;
    }
    printf("%f\n\n", sum);
    return 0;
}