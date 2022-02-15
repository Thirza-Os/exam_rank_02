#include "get_next_line.h"

int	main(void)
{
	printf("buffer size: %i\n", BUFFER_SIZE);
	char	*file;
	char	*line;
	int		fd;
	int		i;

	file = "txt.txt";
	fd = (open (file, O_RDONLY));
	i = 0;
	while ((line = get_next_line(fd)))
	{
		i++;
		printf("\n%i. Outcome:\n%s\nend.", i, line);
		free(line);
		line = NULL;
	}
	close(fd);
	while (1);
}
