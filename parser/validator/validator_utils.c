#include "validator_internal.h"



int	get_expected_arg_count(t_token_type type)
{
	if (type == TOKEN_AMBIENT)
		return (2);
	if (type == TOKEN_CAMERA)
		return (3);
	if (type == TOKEN_LIGHT)
		return (3);
	if (type == TOKEN_SPHERE)
		return (3);
	if (type == TOKEN_PLANE)
		return (3);
	if (type == TOKEN_CYLINDER)
		return (5);
	return (-1);
}



size_t	count_args(char **args)
{
    size_t	count;
    
    count = 0;
    while (args && args[count])
        count++;

    return (count);
}


 void	init_scene_counts(t_scene_counts *counts)
{
    counts->ambient = 0;
    counts->camera = 0;
    counts->light = 0;
}

bool	update_scene_counts( t_scene_counts *counts, t_token *token)
{
    if (token->type == TOKEN_AMBIENT)
    {
        counts->ambient++;
        if (counts->ambient > 1)
            return (error_msg_line(token->line_number,
	            "Multiple ambient lights are not allowed."));
    }
    if (token->type == TOKEN_CAMERA)
    {
        counts->camera++;
        if (counts->camera > 1)
            return (error_msg_line(token->line_number,
	            "Multiple cameras are not allowed."));
    }
    if (token->type == TOKEN_LIGHT)
    {
        counts->light++;
        if (counts->light > 1)
            return (error_msg_line(token->line_number,
	            "Multiple lights are not allowed."));
    }
    return (true);
}



 bool	validate_required_scene_objects( t_scene_counts *counts)
{
    if (counts->ambient == 0)
        return error_msg("Scene must contain at least one ambient light.");
    if (counts->camera == 0)
        return error_msg("Scene must contain at least one camera.");
    if (counts->light == 0)
        return error_msg("Scene must contain at least one light.");

    return (true);
}






