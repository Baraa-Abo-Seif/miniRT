/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 19:15:59 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/22 19:16:00 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "./builder/builder.h"
#include "./converter/converter.h"
#include "./lexer/lexer_token.h"
#include "./parsering_utils/parsing_utils.h"
#include "./validator/validator.h"

t_scene	*parse_scene(const char *filename);

#endif
