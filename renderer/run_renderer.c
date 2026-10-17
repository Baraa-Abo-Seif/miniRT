#include "renderer.h"

#include "../mlx_engine/mlx_api.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "miniRT"

int	run_renderer(t_scene *scene)
{
	t_window	*window;
	t_image		*image;

	if (!scene)
		return (-1);
	if (camera_init(&scene->camera, WINDOW_WIDTH, WINDOW_HEIGHT) != 0)
		return (-1);

	window = mlx_window_create(
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			WINDOW_TITLE);
	if (!window)
		return (-1);
	if (load_bump_maps(window->mlx, scene) != 0
		|| load_color_textures(window->mlx, scene) != 0)
	{
		destroy_bump_maps(window->mlx, scene);
		destroy_color_textures(window->mlx, scene);
		mlx_window_destroy(window);
		return (-1);
	}

	image = mlx_image_create(
			window->mlx,
			WINDOW_WIDTH,
			WINDOW_HEIGHT);
	if (!image)
	{
		mlx_window_destroy(window);
		return (-1);
	}

	if (mlx_image_data(image) == -1)
	{
		mlx_image_destroy(image);
		mlx_window_destroy(window);
		return (-1);
	}

	window->image = image;
	render(scene, image); 

	mlx_display_image(window, image);

	mlx_event_init(window);
	mlx_event_loop(window);

	destroy_bump_maps(window->mlx, scene);
	destroy_color_textures(window->mlx, scene);
	mlx_image_destroy(image);
	mlx_window_destroy(window);
	return (0);
}
