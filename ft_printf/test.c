#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int main()
{
    printf("=========   printf  =========\n");
    int ret1 = printf(" 21.1333");
    printf("       ret_val : %d\n", ret1);
    printf("========= ft_printf =========\n");
    int ret2 = ft_printf(" 21.1333");
    printf("       ret_val : %d\n", ret2);

    int a = 111;
    printf("\ntest\n");
    printf("%x", a);
}