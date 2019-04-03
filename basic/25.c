#include <stdio.h>
int main()
{

    int sum = 0, x = 1;
    for (int i = 1; i <= 20; i++)
    {
        x = x * i;
        sum = sum + x;
        //     printf("%d\n", sum);
    }
    printf("%d\n", sum);
    return 0;
}