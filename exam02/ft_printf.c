#include "ft_printf.h"

void    ft_putchar(char a)
{
    write(1, &a, 1);
}

void    init_flag(t_flags *flag)
{
    flag->width = 0;
    flag->precision = 0;
    flag->dot = 0;
    flag->type = 0;
}

int     ft_atoi(char **str)
{
    long int    i;
    int         sign;

    i = 0;
    if (**str == '-')
    {
        sign = -1;
        (*str)++;
    }
    else
        sign = 1;
    while (**str != 0 && ('0' <= **str && **str <= '9'))
    {
        i = (i * 10) + (**str) - 48;
        (*str)++;
    }
    if (sign == -1)
        i *= sign;
    return (i);
}

void    check_type(char **format, t_flags *flag)
{
    if (**format == 'c')
        flag->type = 'c';
    else if (**format == 'd')
        flag->type = 'd';
    else if (**format == 'x')
        flag->type = 'x';
}

void    print_type(va_list args, t_flags *flag, int *ret)
{
    
}


void    parse_format(va_list args, char **format, int *ret)
{
    t_flags flag;

    if ((*format) + 1 == 0)
        return ;
    else
        (*format)++;
    init_flag(&flag);
    flag.width = ft_atoi(format);
    // printf("s = %s", *format);
    if (*format == '.')
    {
        flag.dot = 1;
        (*format)++;
        flag.precision = ft_atoi(format);
    }
    check_type(format, &flag);
    if (flag.type == 0 || ++(*format) == 0)
        return ;
    print_type(args, &flag, ret);
}

int     ft_printf(const char *format, ...)
{
    int     ret;
    va_list args;

    va_start(args, format);
    ret = 0;
    while (*format)
    {
        if (*format == '%')
            parse_format(args, (char **)&format, &ret);
        else
        {
            ft_putchar(*format);
            ret++;
        }
        format++;
    }
    va_end(args);
    return (ret);
}

int     main(void)
{
    printf("|||");
    int a = printf("%123s", "abcde");
    printf("|||\n");
    printf("a = %d\n", a);
    printf("|||");
    int b = ft_printf("%123s", "abcde");
    printf("|||\n");
    printf("a = %d\n", b);
}