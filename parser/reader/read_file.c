#include "reader_internal.h"


char	**read_file(const char *filename)
{
	int		fd;
	char	**array;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		if (errno == EACCES)
			error_msg("Cannot read scene file: permission denied.");
		else if (errno == ENOENT)
			error_msg("Scene file does not exist.");
		else
			error_msg("Cannot open scene file.");
		return (NULL);
	}

	array = read_lines(fd);
	close(fd);

	return (array);
}
