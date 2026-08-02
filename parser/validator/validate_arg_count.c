
#include "validator_internal.h"


bool	validate_arg_count(t_token *tokens)
{
    t_token	*current;
    int		expected_count;
    size_t	actual_count;

    current = tokens;
    while (current)
    {
        expected_count = get_expected_arg_count(current->type);
        actual_count = count_args(current->args); 

        if (expected_count == -1 || (actual_count != (size_t) expected_count))
            return (error_msg_line(current->line_number,
	            "Invalid number of arguments."));
        current = current->next;
    }
    return (true);
}







