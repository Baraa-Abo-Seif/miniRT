#include "reader_internal.h"


char	**read_file(const char *filename)
{
	int		fd;
	char	**array;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);

	array = read_lines(fd);
	close(fd);

	return (array);
}

