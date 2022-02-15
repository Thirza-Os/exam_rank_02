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

static char	*ft_strjoin_free(char *s1, char *s2, size_t len)
{
	char	*str;
	int		i;
	int		a;

	i = 0;
	a = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[a] && len > 0)
	{
		str[i] = s2[a];
		i++;
		a++;
		len--;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

void	*ft_memcpy(char *dst, char *src, size_t i)
{
	size_t	a;

	a = 0;
	while (i > 0)
	{
		dst[a] = src[a];
		a++;
		i--;
	}
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	left_over[BUFFER_SIZE];
	char		buffer[BUFFER_SIZE + 1];
	char		*return_buff;
	ssize_t		ret_read;
	ssize_t		index;

	return_buff = NULL;
	ret_read = ft_strlen(left_over);
	if (ret_read > 0)
	{
		ft_memcpy(buffer, left_over, ret_read + 1);
		left_over[0] = '\0';
	}
	else
	{
		ret_read = read(fd, buffer, BUFFER_SIZE);
		if (ret_read < 0)
			return (NULL);
		buffer[ret_read] = '\0';
	}
	while (ret_read > 0 && (find_chr(buffer, '\n') == NULL))
	{
		return_buff = ft_strjoin_free(return_buff, buffer, ret_read + 1);
		ret_read = read(fd, buffer, BUFFER_SIZE);
		buffer[ret_read] = '\0';
	}
	if (ret_read < 0)
	{
		free(return_buff);
		return (NULL);
	}
	if (ret_read > 0 && find_chr(buffer, '\n') != NULL)
	{
		index = (size_t)find_chr(buffer, '\n') - (size_t)buffer;
		return_buff = ft_strjoin_free(return_buff, buffer, index + 1);
		if (return_buff && (ret_read - index) > 0)
			ft_memcpy(left_over, buffer + (index + 1), (ret_read - index));
	}
	return (return_buff);
}
