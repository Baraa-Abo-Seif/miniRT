#ifndef LEXER_INTERNAL_H
# define LEXER_INTERNAL_H


#include <stdlib.h>

#include "../../Libft/libft.h"

#include "./lexer.h"


int is_blank_line(char *line);
int is_comment(char *line);

t_token *create_token(char **args, int arg_count, int line_num);
void append_token(t_token **list, t_token *new_node);
void destroy_token(t_token *token);
t_token *process_line(char *line, int line_num);
int is_whitespace(char c);
int count_tokens(char *line);
char **split_fail(char **arr, int filled);
int	fill_args(char **args, char *line, int count);
char **split_line(char *line, int *arg_count);




#endif
