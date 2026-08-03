#ifndef BUILDER_H
# define BUILDER_H

# include <stdbool.h>

# include "../lexer/lexer.h"
# include "../../scene/scence.h"

bool	build_scene(t_token *tokens, t_scene *scene);

#endif
