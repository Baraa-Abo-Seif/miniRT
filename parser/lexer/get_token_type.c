/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bablo <bablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 16:09:20 by bablo             #+#    #+#             */
/*   Updated: 2026/10/19 17:55:25 by bablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_token.h"

t_token_type	get_token_type(const char *identifier)
{
    if (!identifier)
        return (TOKEN_UNKNOWN);
    if (ft_strncmp(identifier, "A" , 2) == 0)
        return (TOKEN_AMBIENT);
    if (ft_strncmp(identifier, "C" , 2) == 0)
        return (TOKEN_CAMERA);
    if (ft_strncmp(identifier, "L" , 2 ) == 0)
        return (TOKEN_LIGHT);
    if (ft_strncmp(identifier, "l" , 2) == 0)
        return (TOKEN_MULTI_LIGHT);
    if (ft_strncmp(identifier, "sp" , 3) == 0)
        return (TOKEN_SPHERE);
    if (ft_strncmp(identifier, "pl" , 3) == 0)
        return (TOKEN_PLANE);
    if (ft_strncmp(identifier, "cy" , 3) == 0)
        return (TOKEN_CYLINDER);
    if (ft_strncmp(identifier, "tr" , 3) == 0)
        return (TOKEN_TRIANGLE);
    if (ft_strncmp(identifier, "pa" , 3) == 0)
        return (TOKEN_PARABOLOID);       
    return (TOKEN_UNKNOWN);
}
