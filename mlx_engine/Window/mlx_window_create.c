#include "mlx_window.h"

t_window	*mlx_window_create(int width, int height, char *title)
{
	t_window	*window;

	window = ft_calloc(1, sizeof(t_window));
	if (!window)
		return (NULL);

	window->width = width;
	window->height = height;

	window->mlx = mlx_init();
	if (!window->mlx)
	{
		free(window);
		return (NULL);
	}

	window->win = mlx_new_window(window->mlx, width, height, title);
	if (!window->win)
	{
		mlx_window_destroy(window);
		return (NULL);
	}
	return (window);
}
