#include "get_next_line.h"

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*find_chr(char *buff, char c)
{
	int	i;

	i = 0;
	if (!buff)
		return (NULL);
	while (buff[i])
	{
		if (buff[i] == c)
		{
			return (&buff[i]);
		}
		i++;
	}
	return (0);
}
