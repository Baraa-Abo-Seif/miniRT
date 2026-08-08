#include "mlx_display.h"
#include "mlx_window.h"
#include "mlx_image.h"



void	mlx_display_image(t_window *window, t_image *image)
{
	if (!window || !image
		|| !window->mlx
		|| !window->win
		|| !image->img)
		return ;

	mlx_put_image_to_window(
		window->mlx,
		window->win,
		image->img,
		0,
		0);
}
