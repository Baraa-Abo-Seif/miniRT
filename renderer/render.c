#include "renderer.h"
#include "../mlx_engine/Image/mlx_image.h"
#include "../mlx_engine/Pixel/mlx_pixel.h"

void	render(t_scene *scene, t_image *image)
{
	int		x;
	int		y;
	t_ray	ray;
	t_color	color;

	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			ray = camera_generate_ray(&scene->camera, x, y);
			color = ray_color(ray, scene);
			mlx_image_pixel_put(image,x,y,color_to_hex(color));
			x++;
		}
		y++;
	}
}





