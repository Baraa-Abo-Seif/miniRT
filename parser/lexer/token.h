#ifndef TOKEN_H
#define TOKEN_H



typedef struct s_token
{
    char            *identifier;
    char            **args;
    int             arg_count;
    int             line;
    struct s_token  *next;
} t_token;













#endif

