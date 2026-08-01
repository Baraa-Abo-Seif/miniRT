#ifndef TOKEN_H
#define TOKEN_H


#include <stddef.h>

typedef enum e_token_type
{
    TOKEN_AMBIENT,
    TOKEN_CAMERA,
    TOKEN_LIGHT,
    TOKEN_SPHERE,
    TOKEN_PLANE,
    TOKEN_CYLINDER,
    TOKEN_UNKNOWN
} t_token_type;

typedef struct s_token
{
	t_token_type	type;			// Token category.
	char			*raw_line;		// Original line (for error reporting).
	char			**args;			// Arguments extracted from the line.
	size_t			line_number;	// Original line number.
	struct s_token	*next;			// Next token in the list.
}	t_token;


#endif

