#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_putstr(char *str)
{
    int i;
    int counter;

    counter = 0;
    if (str == NULL)
        str = ("(null)");
    i = 0;
    while(str[i])
        {
            ft_putchar(str[i]);
            i++;
            counter++;
        }
    return(counter);
}

int ft_count(char *s)
{
    int i;

    i = 0;
    while(s[i])
        i++;
    return(i);
}

int ft_putnbr_base(ssize_t num, char *base)
{
    int count;
    int base_len;

    count = 0;
    base_len = ft_count(base);
    if (num < 0)
    {
        ft_putchar('-');
        num = num * -1;
        count++;
    }
    if (num >= base_len)
        count += ft_putnbr_base(num / base_len, base);
    ft_putchar(base[num % base_len]);
    count++;
    return(count);

}

int ft_put_x(unsigned int digit)
{
    int count;

    count = ft_putnbr_base(digit, "0123456789abcdef");
    return(count);
}

int ft_put_digit(int digit)
{
    int count;

    count = ft_putnbr_base(digit, "0123456789");
    return(count);
}

int ft_printf(const char *s, ...)
{
    int     i;
    int     count;
    va_list args;

    i = 0;
    count = 0;
    va_start(args, s);

    while(s[i])
    {
        while (s[i] && s[i] != '%')
        {
            ft_putchar(s[i]);
            i++;
            count++;
        }
        if (s[i] == '%' && s[i + 1] == 'd')
        {
            count += ft_put_digit(va_arg(args, int));
            i += 2; 
        }
        else if (s[i] == '%' && s[i + 1] == 'x')
        {
            count += ft_put_x(va_arg(args, unsigned int)); 
            i += 2; 
        }
        else if (s[i] == '%' && s[i + 1] == 's')
        {
            count += ft_putstr(va_arg(args, char *));
             i += 2;  
        }
    va_end(args);
    }
    return(count);
}
