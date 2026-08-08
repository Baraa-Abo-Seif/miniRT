#include "./mlx_engine/mlx_api.h"

int	main(void)
{
	t_window	*window;
	t_image		*image;

	window = mlx_window_create(800, 600, "MLX Integration Test");
	if (!window)
		return (1);

	image = mlx_image_create(window->mlx, 800, 600);
	if (!image)
	{
		mlx_window_destroy(window);
		return (1);
	}

	if (mlx_image_data(image) != 0)
	{
		mlx_image_destroy(image);
		mlx_window_destroy(window);
		return (1);
	}

	mlx_image_pixel_put(image, 400, 300, 0x00FF0000);

	mlx_display_image(window, image);
	mlx_event_init(window);
	mlx_event_loop(window);

	mlx_image_destroy(image);
	mlx_window_destroy(window);
	return (0);
}

