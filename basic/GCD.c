#include <stdio.h>
int GCD(int a, int b)
{
    if (b)
        while ((a %= b) && (b %= a))
            ;
            printf("%d\n%d\n",a,b);
    return a + b;
}
int LCM(int a, int b)
{
    return a * b / GCD(a, b);
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("最大公约数为%d\n", GCD(a, b));
    printf("最小公倍数为%d", LCM(a, b));
    return 0;
}
