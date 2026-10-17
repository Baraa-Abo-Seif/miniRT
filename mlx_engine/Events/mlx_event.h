/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:26:28 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 17:30:16 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_EVENT_H
# define MLX_EVENT_H

# include "../../mlx/mlx.h"
#include "../Window/mlx_window.h"
#include "../Display/mlx_display.h"
# include "../../utils/utils.h"

#ifndef KEY_ESC
# define KEY_ESC				65307
#endif

#ifndef EVENT_KEY_PRESS
# define EVENT_KEY_PRESS		2
#endif

#ifndef EVENT_DESTROY_NOTIFY
# define EVENT_DESTROY_NOTIFY	17
#endif

#ifndef KEY_PRESS_MASK
# define KEY_PRESS_MASK		(1L << 0)
#endif

typedef struct s_window	t_window;

void	mlx_event_init(t_window *window);
void	mlx_event_loop(t_window *window);
int		mlx_event_close(void *param);
int		mlx_event_expose(void *param);
int		mlx_event_key(int keycode, void *param);

#endif