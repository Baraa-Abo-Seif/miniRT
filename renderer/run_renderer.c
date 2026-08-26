#include "renderer.h"

#include "../mlx_engine/mlx_api.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define WINDOW_TITLE "miniRT"

int	run_renderer(t_scene *scene)
{
	t_window	*window;
	t_image		*image;

	(void)scene;

	window = mlx_window_create(
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			WINDOW_TITLE);
	if (!window)
		return (-1);

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

	/* render(scene, image); */

	mlx_display_image(window, image);

	/* Events */

	mlx_loop(window->mlx);

	return (0);
}


