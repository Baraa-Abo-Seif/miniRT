
#include "validator_internal.h"


bool	validate_scene_rules(t_token *tokens)
{
    t_scene_counts	counts;
    t_token		*current;

    init_scene_counts(&counts);
    current = tokens;
    while (current)
    {
        if (!update_scene_counts(&counts, current))
            return (false);
        current = current->next;
    }
    if (!validate_required_scene_objects(&counts))
        return (false);

    return (true);
}


