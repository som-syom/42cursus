#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // char buf[1] = {0};
    char aa[1000];

    aa[0] = 'a';
    aa[1] = 'b';
    aa[2] = 'c';
    printf("%s\n", aa);
}