#include "./builder.h"

t_light	*build_light(const t_token *token)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		return (NULL);

	ft_bzero(light, sizeof(t_light));

	light->position = parse_point(token->args[0]);

	light->brightness = ft_atof(token->args[1]);
	if (!check_ratio(light->brightness))
	{
		free(light);
		return (NULL);
	}

	if (!parse_color(token->args[2], &light->color))
	{
		free(light);
		return (NULL);
	}

	return (light);
}

