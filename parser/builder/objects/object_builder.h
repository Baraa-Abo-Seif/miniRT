#ifndef OBJECT_BUILDER_H
# define OBJECT_BUILDER_H


#include "../../lexer/token.h"
#include "../../converter/converter.h"
#include "../../scene/scene.h"


t_object	*create_object(void);
t_object	*build_sphere(const t_token *token);
t_object	*build_plane(const t_token *token);
t_object	*build_cylinder(const t_token *token);



#endif

