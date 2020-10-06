#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	unsigned char tmp;

	if (fd < 0)
		return ;
	if ((unsigned char)c >= 0x80)
	{
		tmp = (unsigned char)c / 0x40 + 0xC0;
		write(fd, &tmp, 1);
		tmp = (unsigned char)c % 0x40 + 0x80;
		write(fd, &tmp, 1);
	}
	else
		write(fd, &c, 1);
}

void	ft_rec_nbr(int n, int fd)
{
	if (n >= 10)
		ft_rec_nbr((n / 10), fd);
	write(fd, &"0123456789"[n % 10], 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	ft_rec_nbr(n, fd);
}