#include "mlx_event.h"
#include "mlx_window.h"

int	mlx_event_key(int keycode, void *param)
{
	t_window	*window;

	window = (t_window *)param;
	if (keycode == KEY_ESC)
		return (mlx_event_close(window));
	return (0);
}


