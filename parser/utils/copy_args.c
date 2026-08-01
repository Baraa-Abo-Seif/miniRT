

#include "parsing_utils.h"

char	**copy_args(char **words)
{
    size_t args_count;
    char **copy;
    size_t index;

    if (!words || !words[0])
        return (NULL);
    index = 1;
    args_count = 1;
    while (words[args_count])
        args_count++;
    copy = ft_calloc((args_count) * sizeof(char *));
    if (!copy)
        return (NULL);
    while (words[index])
    {
        copy[index - 1] = ft_strdup(words[index]);
        if (!copy[index - 1])
        {
            free_string_array(copy);
            return (NULL);
        }
        index++;
    }
    copy[args_count - 1] = NULL;
    return (copy);
}


