
#include "validator_internal.h"

bool	validate_token_types(t_token *tokens)
{
    t_token	*current;

    current = tokens;
    while (current)
    {
        if (current->type == TOKEN_UNKNOWN)
                return (error_msg_line(current->line_number, "Unknown object type."));
        current = current->next;
    }
    return (true);
}
