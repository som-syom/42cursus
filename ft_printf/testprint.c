#include "ft_printf.h"

void	test_print(t_flags *flag)
{
	printf("=======t_flags=======\n");
	printf("[[[ plus = %d\n", flag->plus);
	printf("[[[ minus = %d\n", flag->minus);
	printf("[[[ zero = %d\n", flag->zero);
	printf("[[[ space = %d\n", flag->space);
	printf("[[[ dot = %d\n", flag->dot);
	printf("[[[ width = %d\n", flag->width);
	printf("[[[ sharp = %d\n", flag->sharp);
	printf("[[[ precision = %d\n", flag->precision);
	printf("[[[ type = %c\n", flag->type);
	printf("[[[ sign = %c\n", flag->sign);
}