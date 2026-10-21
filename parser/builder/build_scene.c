#include "./builder.h"


t_scene	*build_scene(t_token *tokens)
{
	t_scene	*scene;
	t_token	*current;

	scene = ft_calloc(1, sizeof(t_scene));
	if (!scene)
	{
		error_msg("Failed to allocate memory for scene");
		return (NULL);
	}
	current = tokens;
	while (current)
	{
		if (current->type == TOKEN_AMBIENT)
		{
			if (!build_ambient(current, &scene->ambient))
			{
				destroy_scene(scene);
				return (NULL);
			}
		}
		else if (current->type == TOKEN_CAMERA)
		{
			if (!build_camera(current, &scene->camera))
			{
				destroy_scene(scene);
				return (NULL);
			}
		}

		else if (current->type == TOKEN_LIGHT ||current->type == TOKEN_MULTI_LIGHT )
		{
			if (!add_light_to_scene(scene, current))
			{
				destroy_scene(scene);
				return (NULL);
			}
		}
		else
		{
			if (!add_object_to_scene(scene, current))
			{
				destroy_scene(scene);
				return (NULL);
			}
		}
		current = current->next;
	}
	return (scene);
}

