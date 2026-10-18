#ifndef OBJECT_BUILDER_H
# define OBJECT_BUILDER_H


#include "../../lexer/token.h"
#include "../../converter/converter.h"
#include "../../../scene/scene.h"
#include "../lib_math/vector/vector.h"
#include "../lib_math/color/color.h"
#include "../../utils/parsing_utils.h"
#include "../../../Libft/libft.h"
# include "../../../utils/utils.h"


t_object	*create_object();
t_object	*build_cylinder(const t_token *token);


t_object	*create_object(void);
t_object	*build_sphere(const t_token *token);
t_object	*build_plane(const t_token *token);
t_object	*build_triangle(const t_token *token);
t_object	*build_paraboloid(const t_token *token);

void	parse_object_bonus(t_object *object,
			const t_token *token, size_t color_index);

            

#endif

