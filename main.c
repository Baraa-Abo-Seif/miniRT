#include "scene/scene.h"
#include "parser/parser.h"
#include "parser/Cleanup/cleanup.h"
#include "renderer/renderer.h"
#include <stdlib.h>
#include "utils/error.h"


int	main(int argc, char **argv)
{
	t_scene	*scene;


	if (argc != 2)
	{
		error_msg("Usage: ./miniRT <scene.rt>");
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

