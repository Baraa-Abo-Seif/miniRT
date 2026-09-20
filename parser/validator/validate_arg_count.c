
#include "validator_internal.h"


#include "validator_internal.h"

bool	validate_arg_count(t_token *tokens)
{
	t_token	*current;
	size_t	actual_count;

	current = tokens;
	while (current)
	{
		actual_count = count_args(current->args);
		if (!is_valid_arg_count(current->type, actual_count))
			return (error_msg_line(current->line_number,
					"Invalid number of arguments."));
		current = current->next;
	}
	return (true);
}







