
#include "lexer_internal.h"



t_token_type	get_token_type(const char *identifier)
{
    if (!identifier)
        return (TOKEN_UNKNOWN);
    
    if (ft_strncmp(identifier, "A" , 2) == 0)
        return (TOKEN_AMBIENT);
    if (ft_strncmp(identifier, "C" , 2) == 0)
        return (TOKEN_CAMERA);
    if (ft_strncmp(identifier, "L" , 2 ) == 0)
        return (TOKEN_LIGHT);
    if (ft_strncmp(identifier, "sp" , 3) == 0)
        return (TOKEN_SPHERE);
    if (ft_strncmp(identifier, "pl" , 3) == 0)
        return (TOKEN_PLANE);
    if (ft_strncmp(identifier, "cy" , 3) == 0)
        return (TOKEN_CYLINDER);
        
    return (TOKEN_UNKNOWN);
}







