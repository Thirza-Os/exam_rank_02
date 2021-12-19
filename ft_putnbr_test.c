// #include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_putnbr_fd(int n, int fd)
{
	long	num;
	int		i;

	i = 0;
	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		i++;
		num = num * -1;
	}
	if ((num >= 10)
	{
		i += ft_putnbr_fd((num / 10), fd);
	}
	ft_putchar_fd(base[num % 10]), fd);
	i++;
	return (i);
}

int main(void)
{
	printf("\n%d", ft_putnbr_fd(-0, 1));
	return(0);
}

int	ft_putnbr_base_fd(int n, char *base, int fd)