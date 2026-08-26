#include "scene/scene.h"
#include "parser/parser.h"
#include "parser/Cleanup/cleanup.h"
#include "renderer/renderer.h"

int	main(int argc, char **argv)
{
	t_scene	*scene;

	if (argc != 2)
		return (1);

	scene = parse_scene(argv[1]);
	if (!scene)
		return (1);

	if (run_renderer(scene) == -1)
	{
		destroy_scene(scene);
		return (1);
	}

	destroy_scene(scene);
	return (0);
}

