#include "lexer_internal.h"

t_token	*tokenize(char **lines)
{
    t_token *list;
    t_token *new_token;
    size_t  line_number;

    list = NULL;
    line_number = 0;
    while (lines && lines[line_number])
    {
        //! TODO: Handle empty or whitespace-only lines.
        //! Decision deferred until validator design is finalized.     
        new_token = tokenize_line(lines[line_number], line_number + 1);
        if (!new_token)
        {
            destroy_token_list(list);
            return (NULL);
        }
         append_token(&list, new_token);
        line_number++;
    }
    return (list);
}
