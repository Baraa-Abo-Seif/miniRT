/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 18:13:22 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 18:13:23 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WINDOW_H
# define MLX_WINDOW_H

# include "../../mlx/mlx.h"
# include "../../Libft/libft.h"
# include "../../utils/utils.h"

typedef struct s_image	t_image;

typedef struct s_window
{
	void	*mlx; // Pointer to the MLX instance
	void	*win; // Pointer to the window instance
	t_image	*image; // Image currently displayed in the window
	int		width; // Width of the window in pixels
	int		height; // Height of the window in pixels
}	t_window;




t_window	*mlx_window_create(int width, int height, char *title);
void		mlx_window_destroy(t_window *window);



#endif
