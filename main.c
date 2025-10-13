#include "get_next_line.h"

// 0-czyta  z stdin
//3+-otwarte pliki

int main (int argc, char **argv)
{
	int	fd;
	char	*line;

	if (argc >= 2)
	{
		fd = open(argv[1],O_RDONLY);
	}
	else
		fd = 0;
	if (fd < 0)
	{
		perror("open");
		return 1;
	}
	while ((line = get_next_line(fd)) != NULL)
	{
    	printf("%s", line);
    	free(line);
	}
	if (fd != 0)
		close (fd);
	return (0);
}
