#include "lexer_internal.h"


int is_whitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}


int count_tokens(char *line)
{
    int count;

    count = 0;
    while (*line)
    {
        while (*line && is_whitespace(*line))
            line++;
        if (*line)
        {
            count++;
            while (*line && !is_whitespace(*line))
                line++;
        }
    }
    return (count);
}


char **split_fail(char **arr, int filled)
{
    int i;

    i = 0;
    while (i < filled)
    {
        free(arr[i]);
        i++;
    }
    free(arr);
    return (NULL);
}

int	fill_args(char **args, char *line, int count)
{
	int			i;
	const char	*start;

	i = 0;
	while (*line && i < count)
	{
		while (*line && is_whitespace(*line))
			line++;
		if (!*line)
			break ;
		start = line;
		while (*line && !is_whitespace(*line))
			line++;
		args[i] = ft_substr(start, 0, line - start);
		if (!args[i])
			return (split_fail(args, i), 0);
		i++;
	}
	return (1);
}

char	**split_line(char *line, int *arg_count)
{
	char	**args;
	int		count;

	if (!line || !arg_count)
		return (NULL);
	count = count_tokens(line);
	if (count == 0)
		return (NULL);
	args = malloc((count + 1) * sizeof(char *));
	if (!args)
		return (NULL);
	if (!fill_args(args, line, count))
		return (NULL);
	args[count] = NULL;
	*arg_count = count;
	return (args);
}
