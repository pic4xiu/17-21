#include <stdio.h>
int main()
{
    int num, quan, total(0);
    scanf("%d %d", &num, &quan);
    while (quan)
    {
        total = total + quan-- * num;
        num = num * 10;
    }
    printf("%d\n", total);
    return 0;
}


//s=a+aa+aaa+aaaa+aa...a