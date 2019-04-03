#include <stdio.h>
int f(int x)
{
    if (x == 1)
        return x;
    else
    {
        return x * f(x - 1);
    }
}
int main()
{
    int a = f(5);
    printf("%d\n", a);
    return 0;
}