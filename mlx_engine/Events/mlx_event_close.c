#include "mlx_event.h"
#include "mlx_window.h"

int	mlx_event_close(void *param)
{
	t_window	*window;

	window = (t_window *)param;
	if (!window || !window->mlx)
		return (0);
	mlx_loop_end(window->mlx);
	return (0);
}


