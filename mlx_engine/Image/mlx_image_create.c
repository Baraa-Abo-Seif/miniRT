
#include "mlx_image.h"

t_image	*mlx_image_create(void *mlx, int width, int height)
{
    t_image	*image;

    image = ft_calloc(1, sizeof(t_image));
    if (!image)
        return (NULL);
    image->mlx = mlx;
    image->width = width;
    image->height = height;
    image->img = mlx_new_image(mlx, width, height);
    if (!image->img)
    {
        mlx_image_destroy(image);
        return (NULL);
    }
    return (image); 
}

