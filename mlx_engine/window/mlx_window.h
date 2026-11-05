/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralhoura <ralhoura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 18:13:22 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/05 16:21:40 by ralhoura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WINDOW_H
# define MLX_WINDOW_H

# include "../../mlx/mlx.h"
# include "../../utils/utils.h"

typedef struct s_image	t_image;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	t_image	*image;
	int		width;
	int		height;
}			t_window;

t_window	*mlx_window_create(int width, int height, char *title);
void		mlx_window_destroy(t_window *window);

#endif
