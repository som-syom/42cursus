#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"
#include "./libft/libft.h"

int main()
{
    char *str = "abcde";
    // float aa = 0.12345;
    printf("=========   printf  =========]\n");
    printf("|||");
    int ret1 = printf("%8.6S", str);
    //int ret1 = printf("%s", "NULL");
    printf("|||\n");
    printf("ret_val : %d\n", ret1);
    // int e = 12345;
    // int *ee = &e;
    // printf("e == %d\n", *ee);
    // printf("n ===== %n", ee);
    // printf("\ne == %d", *ee);
    printf("\n========= ft_printf =========\n");
    ft_putstr_fd("|||", 1);
    int ret2 = ft_printf("%8.6s", str);
    ft_putstr_fd("|||\n", 1);
    printf("ret_val : %d\n", ret2);

    // int a = 111;
    // printf("\n-----test-----\n");
    // printf("||%0d||\n", a);

    printf("-------[end]---------");
}