#include "parser.h"
t_scene	*parse_scene(const char *filename)
{
	char	**lines;
	t_token	*tokens;
	t_scene	*scene;

	lines = read_file(filename);
	if (!lines)
		return (NULL);

	tokens = tokenize(lines);
	free_string_array(lines);
	if (!tokens)
		return (NULL);

	if (!validate_tokens(tokens))
	{
		destroy_token_list(tokens);
		return (NULL);
	}

	scene = build_scene(tokens);
	destroy_token_list(tokens);
	return (scene);
}

