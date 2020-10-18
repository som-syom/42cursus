#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int main()
{
    int aa = 12345;
    printf("=========   printf  =========\n");
    int ret1 = printf("aa%+08d", aa);
    printf("       ret_val : %d\n", ret1);
    printf("========= ft_printf =========\n");
    int ret2 = ft_printf("aa%+08d", aa);
    printf("       ret_val : %d\n", ret2);

    int a = 111;
    printf("\n-----test-----\n");
    printf("||%0d||\n", a);
}