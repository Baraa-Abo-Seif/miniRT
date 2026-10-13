#include "mlx_event.h"
#include "../Window/mlx_window.h"
#include "../Display/mlx_display.h"

int	mlx_event_expose(void *param)
{
	t_window	*window;

	window = (t_window *)param;
	if (!window || !window->image)
		return (0);
	mlx_display_image(window, window->image);
	return (0);
}
