/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralhoura <ralhoura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:26:28 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/05 18:08:57 by ralhoura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_EVENT_H
# define MLX_EVENT_H

# include "../../mlx/mlx.h"
# include "../../utils/utils.h"
# include "../display/mlx_display.h"
# include "../window/mlx_window.h"

# ifndef KEY_ESC
#  define KEY_ESC 65307
# endif

# ifndef EVENT_KEY_PRESS
#  define EVENT_KEY_PRESS 2
# endif

# ifndef EVENT_DESTROY_NOTIFY
#  define EVENT_DESTROY_NOTIFY 17
# endif

void	mlx_event_init(t_window *window);
void	mlx_event_loop(t_window *window);
int		mlx_event_close(void *param);
int		mlx_event_expose(void *param);
int		mlx_event_key(int keycode, void *param);

#endif