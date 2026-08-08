
#include "mlx_window.h"

void		mlx_window_destroy(t_window *window)
{
    if (!window)
        return ;
    if (window->win)
        mlx_destroy_window(window->mlx, window->win);

    if (window->mlx)
    {
        mlx_destroy_display(window->mlx);
        free(window->mlx);
    }
    free(window);
}
