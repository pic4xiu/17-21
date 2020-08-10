#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char x[500]={0};
int main(int argc, char** argv) {
    char buf[128];
    char a[100];
    scanf("%s",a);
    printf(a);
    printf("done\n");
    read(0, buf,128);
    printf("ok\n");
    read(0, x, 20);
    write(1, "Hello, World\n", 13);
}
