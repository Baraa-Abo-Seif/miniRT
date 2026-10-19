/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_scene_rules.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bablo <bablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 18:47:35 by bablo             #+#    #+#             */
/*   Updated: 2026/10/19 18:47:36 by bablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"

bool	validate_scene_rules(t_token *tokens)
{
    t_scene_counts	counts;
    t_token		*current;

    counts.ambient = 0;
    counts.camera = 0;
    counts.light = 0;
    current = tokens;
    while (current)
    {
        if (!update_scene_counts(&counts, current))
            return (false);
        current = current->next;
    }
    if (!validate_required_scene_objects(&counts))
        return (false);
    return (true);
}


