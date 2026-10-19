#include "object_builder.h"

static void	parse_bump_map(t_object *object, const char *arg)
{
	char	**parts;

	if (!arg)
		return ;
	if (ft_strncmp(arg, "bum:", 4) != 0 || !arg[4])
		return ;
	parts = ft_split(arg + 4, ',');
	if (!parts || !parts[0] || !parts[0][0])
	{
		free_string_array(parts);
		return ;
	}
	object->bump_map.filepath = ft_strdup(parts[0]);
	if (!object->bump_map.filepath)
	{
		free_string_array(parts);
		return ;
	}
	object->bump_map.is_active = true;
	object->bump_map.intensity = DEFAULT_BUMP_INTENSITY;
	if (parts[1])
	{
		object->bump_map.intensity = ft_atof(parts[1]);
		check_positive(object->bump_map.intensity);
	}
	free_string_array(parts);
}

static void	parse_color_texture(t_object *object, const char *arg)
{
	if (!arg)
		return ;
	if (ft_strncmp(arg, "txm:", 4) != 0 || !arg[4])
		return ;
	object->color_texture.filepath = ft_strdup(arg + 4);
	if (object->color_texture.filepath)
		object->color_texture.is_active = true;
}

void	parse_object_bonus(t_object *object,
			const t_token *token, size_t color_index)
{
	size_t	i;

	if (!object || !token || !token->args)
		return ;
	i = color_index + 1;
	while (token->args[i])
	{
		if (ft_strncmp(token->args[i], "bum:", 4) == 0)
			parse_bump_map(object, token->args[i]);
		else if (ft_strncmp(token->args[i], "txm:", 4) == 0)
			parse_color_texture(object, token->args[i]);
		else if (ft_strncmp(token->args[i], "checker", 8) == 0)
		{
			if (!token->args[i + 1] || !token->args[i + 2])
				break ;
			object->pattern.type = PATTERN_CHECKER;
			object->pattern.color_a = parse_color(token->args[i + 1]);
			object->pattern.color_b = parse_color(token->args[i + 2]);
			if (token->args[i + 3])
			{
				object->shininess = ft_atof(token->args[i + 3]);
				check_positive(object->shininess);
			}
			i += 2;
		}
		else
		{
			object->shininess = ft_atof(token->args[i]);
			check_positive(object->shininess);
		}
		i++;
	}
}
