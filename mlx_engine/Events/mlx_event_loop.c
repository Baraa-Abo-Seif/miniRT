
#include "mlx_event.h"
#include "../Window/mlx_window.h"

void	mlx_event_loop(t_window *window)
{
	if (!window || !window->mlx)
		return ;
	mlx_loop(window->mlx);
}


