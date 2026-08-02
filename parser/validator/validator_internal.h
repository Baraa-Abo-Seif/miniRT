#ifndef VALIDATOR_INTERNAL_H
# define VALIDATOR_INTERNAL_H


# include "validator.h"
#include <stdbool.h>

typedef struct s_scene_counts
{
	int	ambient;
	int	camera;
	int	light;
}	t_scene_counts;



bool	validate_token_types(t_token *tokens);
int	get_expected_arg_count(t_token_type type);
size_t	count_args(char **args);
bool	validate_arg_count(t_token *tokens);
void	init_scene_counts(t_scene_counts *counts);
bool	update_scene_counts( t_scene_counts *counts, t_token *token);
bool	validate_required_scene_objects( t_scene_counts *counts);
bool	validate_scene_rules(t_token *tokens);






#endif
