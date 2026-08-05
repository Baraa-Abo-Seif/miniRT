#ifndef BUILDER_INTERNAL_H
# define BUILDER_INTERNAL_H

# include "../../Libft/libft.h"
#include "../../scene/scene.h"
#include "./objects/object_builder.h"

t_scene	*create_scene(void);

void	append_light(t_scene *scene, t_light *light);
void	append_object(t_scene *scene, t_object *object);
t_ambient	build_ambient(const t_token *token);
t_camera	build_camera(const t_token *token);
t_light	*build_light(const t_token *token);
t_object	*create_object();
t_object	*build_object(const t_token *token);
bool	add_light_to_scene(t_scene *scene, const t_token *token);
bool	add_object_to_scene(t_scene *scene, const t_token *token);


#endif
