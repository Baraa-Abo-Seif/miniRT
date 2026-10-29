/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 20:28:50 by bablo             #+#    #+#             */
/*   Updated: 2026/10/26 19:50:07 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_UTILS_H
#define PARSING_UTILS_H

#include <errno.h>
#include <fcntl.h>
#include "../../lib_math/lib_math.h"
#include "../../Libft/libft.h"
#include "../../get_next_line/get_next_line.h"
#include "../../utils/utils.h"

typedef t_list t_line_node;
typedef struct s_token t_token;


bool	check_normal(t_vec normal);

bool	check_positive(double value);

bool	check_ratio(double value);

void	free_string_array(char **array);


char **read_file(const char *filename);
void free_new_node(t_line_node *list,char *line);
char	**read_lines(int fd);
char **list_to_array(t_line_node *list);

#endif 
