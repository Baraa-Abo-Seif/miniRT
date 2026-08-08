#include "mlx_event.h"
#include "mlx_window.h"

void	mlx_event_init(t_window *window)
{
	if (!window || !window->mlx || !window->win)
		return ;

	mlx_hook(window->win, EVENT_DESTROY_NOTIFY, 0,
		(int (*)())mlx_event_close, window);
	mlx_hook(window->win, EVENT_KEY_PRESS, KEY_PRESS_MASK,
		(int (*)())mlx_event_key, window);
}

