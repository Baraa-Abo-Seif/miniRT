
#include "mlx_image.h"

int		mlx_image_data(t_image *image)
{
    if (!image || !image->img)
        return (-1);
    image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
            &image->line_length, &image->endian);
    if (!image->addr)
        return (-1);
    return (0);
}


