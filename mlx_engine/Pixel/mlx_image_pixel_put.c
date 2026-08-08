#include "mlx_pixel.h"
#include "mlx_image.h"

void	mlx_image_pixel_put(t_image *image, int x, int y, int color)
{
	int		offset;
	char	*pixel;

	if (!image || !image->addr
		|| x < 0 || x >= image->width
		|| y < 0 || y >= image->height)
		return ;

	offset = (y * image->line_length)
		+ (x * (image->bits_per_pixel / 8));
	pixel = image->addr + offset;
	*(unsigned int *)pixel = color;
}

