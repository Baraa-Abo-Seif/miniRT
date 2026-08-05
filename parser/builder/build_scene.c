
#include "builder_internal.h"

t_scene	*build_scene(t_token *tokens)
{
	t_scene	*scene;
	t_token	*current;

	scene = create_scene();
	if (!scene)
		return (NULL);
	current = tokens;
	while (current)
	{
		if (current->type == TOKEN_AMBIENT)
			scene->ambient = build_ambient(current);
		else if (current->type == TOKEN_CAMERA)
			scene->camera = build_camera(current);
		else if (current->type == TOKEN_LIGHT)
		{
			if (!add_light_to_scene(scene, current))
				return (NULL);
		}
		else if (!add_object_to_scene(scene, current))
				return (NULL);
		current = current->next;
	}
	return (scene);
}












