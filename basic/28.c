#include<stdio.h>
int age(int x)
{
    if(x==1)
    return 10;
    else
    {
        return age(x-1)+2;
    }
    
}
int main()
{
    int a=age(5);
    printf("%d\n",a);
    return 0;
}