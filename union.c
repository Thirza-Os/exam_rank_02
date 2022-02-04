#include <unistd.h>
#include <stdio.h>

int check_arr(char *str, char c, int count)
{
    count = count -1;
    while(count >= 0)
    {
        if(str[1] == c)
            return(0);
    count--;
    }
    return(1);
}

void    ft_union(char s1[], char s2[])
{
	int		i;
	int		len;

	i = 0;
	while (s1[i])
	{
		if (check_arr(s1, s1[i], i) == 1)
			write(1, &s1[i], 1);
		i++;
	}
	len = i;
	i = 0;
	while (s2[i])
	{
		if (check_arr(s2, s2[i], i) == 1)
		{
			if (check_arr(s1, s2[i], len) == 1)
				write(1, &s2[i], 1);
		}
		i++;
	}
}

int main(int argc, char *argv[])
{
    if (argc==3)
        ft_union(argv[1], argv[2]);
    write(1, "\n", 1);
    return(0);
}