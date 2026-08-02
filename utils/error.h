#ifndef ERROR_H
# define ERROR_H


# include <stdbool.h>
# include <stddef.h>
#include "../Libft/libft.h"



bool	error_msg( char *msg);
bool	error_msg_line(size_t line,  char *msg);



#endif