/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 19:00:39 by babo-sai          #+#    #+#             */
/*   Updated: 2026/11/03 19:11:32 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "../intersector/hit/hit_record.h"
# include "../mlx_engine/mlx_api.h"
# include "../texture/texture.h"
# include "../utils/utils.h"
# include "./camera/renderer_camera.h"

t_color	render_ambient(t_color object_color, t_ambient ambient);
bool	is_in_shadow(t_hit_record *record, t_scene *scene, t_light *light);
t_color	render_diffuse(t_color object_color, t_hit_record *record,
			t_scene *scene, t_light *light);
t_color	ray_color(t_ray ray, t_scene *scene);

t_color	shade_with_lights(t_object *object, t_hit_record *record,
			t_scene *scene, t_color base_color);
t_color	get_checker_color(t_object *object, t_point local_p);
t_point	pattern_point(t_object *object, t_point point);
t_uv	get_object_uv(t_object *object, t_point point);
t_color	shade_hit(t_hit_record *record, t_scene *scene);

t_color	render_specular(t_object *object, t_hit_record *record, t_scene *scene,
			t_light *light);

void	render(t_scene *scene, t_image *image);

t_image	*init_renderer_image(t_window *window);
int		destroy_renderer(t_window *window, t_scene *scene);
int		load_scene_textures(t_window *window, t_scene *scene);
int		run_renderer(t_scene *scene);

#endif
