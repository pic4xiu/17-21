#include <stdio.h>
int main()
{
    int i(1);
    for (int day = 2; day <= 10; day++)
        i = (i + 1) * 2;
    printf("%d\n", i);
    return 0;
}


//monkey eat peaches