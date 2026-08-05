#ifndef BUILDER_H
# define BUILDER_H

# include <stdbool.h>

# include "../validator/validator.h"
# include "../../scene/scene.h"

t_scene	*build_scene(t_token *tokens);

#endif

