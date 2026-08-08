#ifndef MLX_IMAGE_H
# define MLX_IMAGE_H

# include "../../mlx/mlx.h"
# include "../../Libft/libft.h"


typedef struct s_image
{
	void	*mlx;			// MLX instance handle
	void	*img;			// MLX image handle
	char	*addr;			// Pointer to image buffer

	int		width;			// Image width in pixels
	int		height;			// Image height in pixels

	int		bits_per_pixel;	// Bits used to represent one pixel
	int		line_length;	// Number of bytes in one image row
	int		endian;			// Endianness of the image buffer
}	t_image;

/*
** Creates a new MLX image.
*/
t_image	*mlx_image_create(void *mlx, int width, int height);

/*
** Initializes the image buffer information.
*/
int		mlx_image_data(t_image *image);

/*
** Destroys the image and releases all allocated resources.
*/
void	mlx_image_destroy(t_image *image);

#endif
