
#include "validator_internal.h"

bool	validate_tokens(t_token *tokens)
{

    if (!validate_token_types(tokens))
	return (false);

    if (!validate_arg_count(tokens))
        return (false);

    if (!validate_scene_rules(tokens))
        return (false);

    return (true);
}

