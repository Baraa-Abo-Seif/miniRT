#include "scene/scene.h"
#include "parser/parser.h"
#include "parser/Cleanup/cleanup.h"
#include "renderer/renderer.h"
#include <stdlib.h>
#include "utils/error.h"

static bool	has_rt_extension(const char *filename)
{
	size_t	length;

	if (!filename)
		return (false);
	length = ft_strlen(filename);
	return (length >= 3
		&& ft_strncmp(filename + length - 3, ".rt", 3) == 0);
}

int	main(int argc, char **argv)
{
	t_scene	*scene;

	if (argc != 2)
	{
		error_msg("Usage: ./miniRT <scene.rt>");
		return (EXIT_FAILURE);
	}
	if (!has_rt_extension(argv[1]))
	{
		error_msg("Scene file must have a .rt extension.");
		return (EXIT_FAILURE);
	}

	scene = parse_scene(argv[1]);
	
	if (!scene)
		return (EXIT_FAILURE);
		
	printf("PARSER OK\n");

	if (run_renderer(scene) == -1)
	{
		destroy_scene(scene);
		return (EXIT_FAILURE);

	}

	destroy_scene(scene);
	return (EXIT_SUCCESS);
}
