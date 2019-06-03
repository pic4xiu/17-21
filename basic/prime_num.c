#include <stdio.h>
int main()
{
    int j;
    for (int i = 101; i <= 200; i++)
    {
        for (j = 2; j < i / 2; j++)
            if (i % j == 0)
                break;
        if (j == i / 2)
            printf("%d\n", i);
    }
    return 0;
}
