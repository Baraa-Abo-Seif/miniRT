/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bablo <bablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 15:26:09 by bablo             #+#    #+#             */
/*   Updated: 2026/10/21 15:26:36 by bablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./object_builder.h"

void parse_checker_pattern(t_object *object, char *const *args, size_t *i)
{
	t_color	color_a;
	t_color	color_b;

	if (!args[*i + 1] || !args[*i + 2])
	{
		if (args[*i + 1])
			(*i)++;
		error_msg("Checker pattern requires two colors as arguments");
		return;
	}
	if (!parse_color(args[*i + 1], &color_a)
		 || !parse_color(args[*i + 2], &color_b))
	{
		error_msg("Failed to parse colors for checker pattern");
		*i += 2;
		return ;
	}
	object->pattern.color_a = color_a;
	object->pattern.color_b = color_b;
	object->pattern.type = PATTERN_CHECKER;
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
			parse_checker_pattern(object, token->args, &i);
		else
		{
			object->shininess = ft_atof(token->args[i]);
			if (!check_positive(object->shininess))
				return (false);
		}
	}
	return (true);
}
