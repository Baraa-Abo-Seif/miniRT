/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:41:22 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/15 14:41:23 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"


t_color	color_add(t_color a, t_color b)
{
    t_color add;
    
    add.r = a.r + b.r;
    add.g = a.g + b.g;
    add.b = a.b + b.b;

    return (add);
}
