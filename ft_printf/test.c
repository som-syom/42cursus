#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"
#include "./libft/libft.h"

int main()
{
    float aa = 0.12345;
    printf("=========   printf  =========]\n");
    int ret1 = printf("%f\n", aa);
    printf("       ret_val : %d\n", ret1);
    printf("|||");
    int ret11 = printf("%c", 128);
    printf("|||\n");
    printf("ret_val : %d\n", ret11);
    printf("========= ft_printf =========\n");
    ft_putstr_fd("|||", 1);
    int ret2 = ft_printf("%7c", 'z');
    ft_putstr_fd("|||\n", 1);
    printf("ret_val : %d\n", ret2);

    // int a = 111;
    // printf("\n-----test-----\n");
    // printf("||%0d||\n", a);

    printf("-------[end]---------");
}