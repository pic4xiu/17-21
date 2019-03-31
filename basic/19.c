#include <stdio.h>
int main()
{
    int temp, i, j;
    for (i = 2; i <= 1000; i++)
    {
        temp = 0;
        for (j = 1; j <=i/2; j++)
        {
            if (i % j == 0)
                temp += j;
        }
        if (temp == i)
            printf("%d\n", i);
    }
    return 0;
}


//calc the wanderful num