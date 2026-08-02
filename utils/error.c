
#include "error.h"


bool	error_msg( char *msg)
{
    ft_putendl_fd("Error", STDERR_FILENO);
    ft_putendl_fd(msg, STDERR_FILENO);
    return (false);
}
bool	error_msg_line(size_t line,  char *msg)
{
    ft_putendl_fd("Error", STDERR_FILENO);
    ft_putstr_fd("Line ", STDERR_FILENO);
    ft_putnbr_fd((int)line, STDERR_FILENO);
    ft_putstr_fd(": ", STDERR_FILENO);
    ft_putendl_fd(msg, STDERR_FILENO);
    return (false);
}
