#include "lexer_internal.h"

t_token	*tokenize_line(const char *line, size_t line_number)
{
	char	**words;
	t_token	*token;

	if (!line)
		return (NULL);

	words = ft_split(line, ' ');
	if (!words)
		return (NULL);

	if (!words[0])
	{
		free_string_array(words);
		return (NULL);
	}

	token = create_token(line, line_number, words);

	free_string_array(words);

	return (token);
}

