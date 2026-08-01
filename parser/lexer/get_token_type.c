
#include "lexer_internal.h"



t_token_type	get_token_type(const char *identifier)
{
    if (!identifier)
        return (TOKEN_UNKNOWN);
    
    if (ft_strcmp(identifier, "A") == 0)
        return (TOKEN_AMBIENT);
    if (ft_strcmp(identifier, "C") == 0)
        return (TOKEN_CAMERA);
    if (ft_strcmp(identifier, "L") == 0)
        return (TOKEN_LIGHT);
    if (ft_strcmp(identifier, "sp") == 0)
        return (TOKEN_SPHERE);
    if (ft_strcmp(identifier, "pl") == 0)
        return (TOKEN_PLANE);
    if (ft_strcmp(identifier, "cy") == 0)
        return (TOKEN_CYLINDER);
        
    return (TOKEN_UNKNOWN);
}







