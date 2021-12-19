// #include <stdio.h>
// #include <unistd.h>
// #include <limits.h>
// #include <stdarg.h>
#include "ft_printf.h"

static int	count_length(char *base)
{
	int	i;

	i = 0;
	while (*base)
	{
		base++;
		i++;
	}
	return (i);
}

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	putnbr_base(ssize_t num, char *base)
{
	ssize_t	base_len;
	int		counter;

	counter = 0;
	base_len = count_length(base);
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
		counter++;
	}
	if (num >= base_len)
	{
		counter += putnbr_base(num / base_len, base);
	}
	ft_putchar(base[num % base_len]);
	counter++;
	return (counter);
}

static int	ft_printf_char(char c)
{
	int	str_len;

	ft_putchar(c);
	str_len = 1;
	return (str_len);
}

static int	ft_print_hexa(char c, size_t i)
{
	int	str_len;

	str_len = 0;
	if (c == 'X')
		str_len += putnbr_base(i, "0123456789ABCDEF");
	if (c == 'x')
		str_len += putnbr_base(i, "0123456789abcdef");
	return (str_len);
}

static int ft_printf_void(size_t i)
{
	int		str_len;

	str_len = 0;
	write(1, "0x", 2);
	str_len += putnbr_base(i, "0123456789abcdef");
	return (str_len + 2);
}

static int	ft_printf_string(char *s)
{
	int	str_len;

	str_len = 0;
	if (s == NULL)
		s = ("(null)");
	while (s[str_len])
	{
		ft_putchar(s[str_len]);
		str_len++;
	}
	return (str_len);
}

static int	ft_printf_uint(unsigned int i)
{
	int	str_len;

	str_len = putnbr_base(i, "0123456789");
	return (str_len);
}

static int	ft_printf_int(int i)
{
	int	str_len;

	str_len = putnbr_base(i, "0123456789");
	return (str_len);
}

static int	ft_printf_sym(const char *s, int *i, int str_len, va_list args)
{
	if (s[*i + 1] == '%')
		str_len += ft_printf_char(s[*i + 1]);
	else if (s[*i + 1] == 'x' || s[*i + 1] == 'X')
		str_len += ft_print_hexa(s[*i + 1], va_arg(args, unsigned int));	
	else if (s[*i + 1] == 's')
		str_len += ft_printf_string(va_arg(args, char *));				//Parameter for the index
	else if (s[*i + 1] == 'u')
		str_len += ft_printf_uint(va_arg(args, unsigned int));
	else if (s[*i + 1] == 'p')
		str_len += ft_printf_void(va_arg(args, size_t));
	else if (s[*i + 1] == 'c')
		str_len += ft_printf_char(va_arg(args, int));
	else if (s[*i + 1] == 'i' || s[*i + 1] == 'd')
		str_len += ft_printf_int(va_arg(args, int));
	else
	{
		(*i)++;
		return (str_len);
	}
	(*i) += 2;
	return (str_len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		str_len;

	i = 0;
	str_len = 0;
	va_start(args, s);
	while (s[i])
	{
		while (s[i] && s[i] != '%')
		{
			str_len += ft_printf_char(s[i]);
			i++;
		}
		while (s[i] == '%')
			str_len = ft_printf_sym(s, &i, str_len, args);
	}
	return (str_len);
}

// int	main(void)
// {
// 	char *p;
// 	int	hexa;
// 	int HEXA;
// 	char *s;

// 	s = "Hello";

// 	hexa = 20;
// 	HEXA = 20;
// 	p = "hoi";
// 	printf("\nnr0:	%d\n", ft_printf("%x%c%s%u%d%i", hexa, '*', s, -900, 7, -8));
// 	printf("\nnr1:	%d\n", printf("%x%c%s%u%d%i", hexa, '*', s, -900, 7, -8));
	// printf("\nnr2: %d\n", ft_printf("%x", hexa));
	// printf("\nnr2: %d\n", printf("%x", hexa));
// }
