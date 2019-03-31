#include <stdio.h>
int main()
{
    float h(100), total(0);
    for (int i = 1; i <= 10; i++)
    {
        total = total + h;
        h = h / 2;
       // printf("%f\t%f\n", total, 2 * h);
    }
    printf("%f\t%f\n", total,  h);
    return 0;
}


//free fall