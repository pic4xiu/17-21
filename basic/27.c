#include <stdio.h>
void func(int n);
int main()
{
    printf("please input 5 numbers:");
    func(5);
    return 0;
}
void func(int n)
{
    if (n <= 1)
    {
        char next = getchar();
        putchar(next);
    }
    else
    {
        char next = getchar();
        func(n - 1);
        putchar(next);
    }
}