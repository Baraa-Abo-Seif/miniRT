#include "renderer.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "miniRT"

// int	run_renderer(t_scene *scene)
// {
// 	t_window	*window;
// 	t_image		*image;

// 	if (!scene)
// 		return (-1);
// 	if (camera_init(&scene->camera, WINDOW_WIDTH, WINDOW_HEIGHT) != 0)
// 		return (-1);

// 	window = mlx_window_create(
// 			WINDOW_WIDTH,
// 			WINDOW_HEIGHT,
// 			WINDOW_TITLE);
// 	if (!window)
// 		return (-1);
// 	if (load_bump_maps(window->mlx, scene) != 0
// 		|| load_color_textures(window->mlx, scene) != 0)
// 	{
// 		destroy_bump_maps(window->mlx, scene);
// 		destroy_color_textures(window->mlx, scene);
// 		mlx_window_destroy(window);
// 		return (-1);
// 	}

// 	image = mlx_image_create(
// 			window->mlx,
// 			WINDOW_WIDTH,
// 			WINDOW_HEIGHT);
// 	if (!image)
// 	{
// 		mlx_window_destroy(window);
// 		return (-1);
// 	}

// 	if (mlx_image_data(image) == -1)
// 	{
// 		mlx_image_destroy(image);
// 		mlx_window_destroy(window);
// 		return (-1);
// 	}

// 	window->image = image;
// 	render(scene, image); 

// 	mlx_display_image(window, image);

// 	mlx_event_init(window);
// 	mlx_event_loop(window);

// 	destroy_bump_maps(window->mlx, scene);
// 	destroy_color_textures(window->mlx, scene);
// 	mlx_image_destroy(image);
// 	mlx_window_destroy(window);
// 	return (0);
// }

static void	destroy_renderer(t_window *window, t_scene *scene)
{
	destroy_bump_maps(window->mlx, scene);
	destroy_color_textures(window->mlx, scene);
	mlx_window_destroy(window);
}



static t_window	*init_renderer_window(void)
{
	t_window	*window;

	window = mlx_window_create(WINDOW_WIDTH,
			WINDOW_HEIGHT, WINDOW_TITLE);
	if (!window)
		return (NULL);
	return (window);
}

static int	load_scene_textures(t_window *window, t_scene *scene)
{
	if (load_bump_maps(window->mlx, scene) != 0)
		return (-1);
	if (load_color_textures(window->mlx, scene) != 0)
	{
		destroy_bump_maps(window->mlx, scene);
		return (-1);
	}
	return (0);
}

static t_image	*init_renderer_image(t_window *window)
{
	t_image	*image;

	image = mlx_image_create(window->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!image)
		return (NULL);
	if (mlx_image_data(image) == -1)
	{
		mlx_image_destroy(image);
		return (NULL);
	}
	return (image);
}

int	run_renderer(t_scene *scene)
{
	t_window	*window;
	t_image		*image;

	if (!scene)
		return (-1);
	if (camera_init(&scene->camera,
			WINDOW_WIDTH, WINDOW_HEIGHT) != 0)
		return (-1);
	window = init_renderer_window();
	if (!window)
		return (-1);
	if (load_scene_textures(window, scene) != 0)
		return (destroy_renderer(window, scene), -1);
	image = init_renderer_image(window);
	if (!image)
		return (destroy_renderer(window, scene), -1);
	window->image = image;
	render(scene, image);
	mlx_display_image(window, image);
	mlx_event_init(window);
	mlx_event_loop(window);
	mlx_image_destroy(image);
	destroy_renderer(window, scene);
	return (0);
}

