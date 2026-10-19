#ifndef READER_H
#define READER_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <errno.h>

#include "../../Libft/libft.h"
#include "../../get_next_line/get_next_line.h"
#include "../../utils/utils.h"
#include "../utils/parsing_utils.h"

typedef t_list t_line_node;

char **read_file(const char *filename);

char	**read_lines(int fd);

char **list_to_array(t_line_node *list);

#endif

