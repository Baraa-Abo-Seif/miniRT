#ifndef MLX_EVENT_H
# define MLX_EVENT_H

# include "../../mlx/mlx.h"

# define KEY_ESC				65307
# define EVENT_KEY_PRESS		2
# define EVENT_DESTROY_NOTIFY	17
# define KEY_PRESS_MASK		(1L << 0)

typedef struct s_window	t_window;

void	mlx_event_init(t_window *window);
void	mlx_event_loop(t_window *window);
int		mlx_event_close(void *param);
int		mlx_event_key(int keycode, void *param);

#endif