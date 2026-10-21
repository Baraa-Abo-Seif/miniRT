
#include "./object_builder.h"

void parse_checker_pattern(t_object *object, char *const *args, size_t *i)
{
	if (1)//!args[*i + 1] || !args[*i + 2])
		return ;
	object->pattern.type = PATTERN_CHECKER;
	if (!parse_color(args[*i + 1], &object->pattern.color_a)
		|| !parse_color(args[*i + 2], &object->pattern.color_b))
		return ;
	if (args[*i + 3])
	{
		object->shininess = ft_atof(args[*i + 3]);
		if (!check_positive(object->shininess))
			return ;
	}
	*i += 2;
}

void	parse_color_texture(t_object *object, const char *arg)
{
	if (!arg || !arg[4])
		return ;
	object->color_texture.filepath = ft_strdup(arg + 4);
	if (object->color_texture.filepath)
		object->color_texture.is_active = true;
	else
		error_msg("Failed to allocate memory for color texture filepath");
}



void	parse_bump_map(t_object *object, const char *arg)
{
	char	**parts;

	if (!arg || !arg[4])
		return ;
	parts = ft_split(arg + 4, ',');
	if (!parts || !parts[0] || !parts[0][0])
		return (failled_massage("Failed to parse bump map: missing filepath",
			 parts));
	object->bump_map.filepath = ft_strdup(parts[0]);
	if (!object->bump_map.filepath)
		return (failled_massage("Failed to allocate for bump map filepath",
			 parts));
	object->bump_map.is_active = true;
	object->bump_map.intensity = DEFAULT_BUMP_INTENSITY;
	if (parts[1])
	{
		object->bump_map.intensity = ft_atof(parts[1]);
		if (!check_positive(object->bump_map.intensity))
			return (failled_massage(NULL,parts));
	}
	free_string_array(parts);
}

bool	parse_object_bonus(t_object *object,
			const t_token *token, size_t color_index)
{
	size_t	i;

	i = color_index ;
	while (token->args[++i])
	{
		if (ft_strncmp(token->args[i], "bum:", 4) == 0)
			parse_bump_map(object, token->args[i]);
		else if (ft_strncmp(token->args[i], "txm:", 4) == 0)
			parse_color_texture(object, token->args[i]);
		else if (ft_strncmp(token->args[i], "checker", 8) == 0)
		{
			parse_checker_pattern(object, token->args, &i);
			// if (!parse_checker_pattern(object, token->args, &i))
			// 	return (false);
		}
		else
		{
			object->shininess = ft_atof(token->args[i]);
			if (!check_positive(object->shininess))
				return (false);
		}
	}
	return (true);
}
