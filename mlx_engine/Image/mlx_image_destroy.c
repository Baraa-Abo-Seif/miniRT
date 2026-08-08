
#include "mlx_image.h"

void	mlx_image_destroy(t_image *image)
{
    if (!image)
        return ;
    if (image->img)
        mlx_destroy_image(image->mlx, image->img);
    free(image);
}

