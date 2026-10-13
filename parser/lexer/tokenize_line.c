#include "lexer_internal.h"

static bool	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f');
}

static char	normalize_whitespace(unsigned int index, char c)
{
	(void)index;
	if (is_whitespace(c))
		return (' ');
	return (c);
}

t_token	*tokenize_line(const char *line, size_t line_number)
{
	char	*normalized_line;
	char	**words;
	t_token	*token;

	if (!line)
		return (NULL);

	normalized_line = ft_strmapi(line, normalize_whitespace);
	if (!normalized_line)
		return (NULL);
	words = ft_split(normalized_line, ' ');
	free(normalized_line);
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
