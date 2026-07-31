#include "lexer_internal.h"


int is_blank_line(char *line)
{
    if (!line || !*line)
        return (1);
    if (*line == '\n')
        return (1);
    return (0);
}


int is_comment(char *line)
{
    if (!line)
        return (0);
    if (*line == '#')
        return (1);
    return (0);
}



