#ifndef MLX_WINDOW_H
# define MLX_WINDOW_H

# include "../../mlx/mlx.h"
# include "../../Libft/libft.h"

typedef struct s_window
{
	void	*mlx; // Pointer to the MLX instance
	void	*win; // Pointer to the window instance
	int		width; // Width of the window in pixels
	int		height; // Height of the window in pixels
}	t_window;




t_window	*mlx_window_create(int width, int height, char *title);
void		mlx_window_destroy(t_window *window);



#endif
