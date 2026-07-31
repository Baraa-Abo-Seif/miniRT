#include "lexer_internal.h"

t_token *process_line(char *line, int line_num)
{
    t_token *new_token;
    char    **args;
    int     arg_count;

    args = split_line(line, &arg_count);
    if (!args)
        return (NULL);
    new_token = create_token(args, arg_count, line_num);
    if (!new_token)
    {
        while (arg_count > 0)
            free(args[--arg_count]);
        free(args);
    }
    return (new_token);
}

t_token *lexer_tokenize(char **lines)
{
    t_token *list;
    t_token *new_token;
    int     line_num;

    list = NULL;
    line_num = 0;
    while (lines && lines[line_num])
    {
        if (is_blank_line(lines[line_num]) || is_comment(lines[line_num]))
        {
            line_num++;
            continue ;
        }
        new_token = process_line(lines[line_num], line_num);
        if (!new_token)
        {
            lexer_destroy_tokens(list);
            return (NULL);
        }
        append_token(&list, new_token);
        line_num++;
    }
    return (list);
}
