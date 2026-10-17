/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 18:12:39 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 18:12:40 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
