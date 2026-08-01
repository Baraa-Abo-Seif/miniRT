
#include "parsing_utils.h"



void	free_string_array(char **array)
{
    size_t i;

    i = 0;
    if (!array)
	    return ;
    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}



