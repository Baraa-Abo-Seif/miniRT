#ifndef BUILDER_INTERNAL_H
# define BUILDER_INTERNAL_H

# include <stdlib.h>

# include "../../Libft/libft.h"
# include "../utils/parsing_utils.h"

# include "builder.h"

bool	build_ambient(t_scene *scene, t_token *token);
bool	build_camera(t_scene *scene, t_token *token);
bool	build_light(t_scene *scene, t_token *token);
bool	build_object(t_scene *scene, t_token *token);
bool	build_sphere(t_scene *scene, t_token *token);
bool	build_plane(t_scene *scene, t_token *token);
bool	build_cylinder(t_scene *scene, t_token *token);
t_object	*create_object(t_object_type type);
t_light	*create_light(void);
void	append_object(t_object **list, t_object *new_object);
void	append_light(t_light **list, t_light *new_light);
t_point	parse_point(char *str);
t_vec	parse_vec(char *str);
t_color	parse_color(char *str);

#endif
