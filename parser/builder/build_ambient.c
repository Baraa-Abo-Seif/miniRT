/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 16:16:37 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/22 16:16:38 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./builder.h"

bool	build_ambient(const t_token *token, t_ambient *ambient)
{
	ambient->ratio = ft_atof(token->args[0]);
	if (!check_positive(ambient->ratio) || !check_ratio(ambient->ratio))
		return (false);
	return (parse_color(token->args[1], &ambient->color));
}



