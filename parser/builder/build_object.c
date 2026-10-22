/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 17:22:21 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/22 17:22:22 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./builder.h"


t_object	*build_object(const t_token *token)
{
	if (token->type == TOKEN_SPHERE)
		return (build_sphere(token));
	if (token->type == TOKEN_PLANE)
		return (build_plane(token));
	if (token->type == TOKEN_CYLINDER)
		return (build_cylinder(token));
	if (token->type == TOKEN_TRIANGLE)
		return (build_triangle(token));
	if (token->type == TOKEN_PARABOLOID)
		return (build_paraboloid(token));
	return (NULL);
}
