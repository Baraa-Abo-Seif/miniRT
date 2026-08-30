# **************************************************************************** #
#                                   Project                                    #
# **************************************************************************** #

NAME		= miniRT

CC			= cc
CFLAGS = -Wall -Wextra -Werror -Wno-cast-function-type

RM			= rm -f

# **************************************************************************** #
#                                  Libraries                                   #
# **************************************************************************** #

LIBFT_DIR	= Libft
LIBFT		= $(LIBFT_DIR)/libft.a

MLX_DIR		= mlx
MLX			= $(MLX_DIR)/libmlx.a

# **************************************************************************** #
#                                   Includes                                   #
# **************************************************************************** #

INCLUDES	= \
	-I. \
	-I$(LIBFT_DIR) \
	-I$(MLX_DIR) \
	-Iget_next_line

LIBS		= \
	$(LIBFT) \
	$(MLX) \
	-lXext \
	-lX11 \
	-lm
# **************************************************************************** #
#                                   Sources                                    #
# **************************************************************************** #

MAIN_SRC = \
	main.c

UTILS_SRC = \
	utils/error.c

GNL_SRC = \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c

MATH_SRC = \
	math/color/color_add.c \
	math/color/color_clamp.c \
	math/color/color_multiply.c \
	math/color/color_scale.c \
	math/color/color_to_hex.c \
	math/color/color_clamp_rgb.c \
	math/point/point_add_vec.c \
	math/point/point_sub_point.c \
	math/point/point_sub_vec.c \
	math/vector/vec_add.c \
	math/vector/vec_cross.c \
	math/vector/vec_distance.c \
	math/vector/vec_dot.c \
	math/vector/vec_length.c \
	math/vector/vec_normalize.c \
	math/vector/vec_reflect.c \
	math/vector/vec_scale.c \
	math/vector/vec_sub.c	

SCENE_SRC = \
	scene/camera/camera_build_basis.c \
	scene/camera/camera_compute_pixel_delta.c \
	scene/camera/camera_compute_viewport.c \
	scene/camera/camera_create.c \
	scene/camera/camera_destroy.c \
	scene/camera/camera_init.c \
	scene/camera/camera_ray.c \
	scene/ray/ray_at.c \
	scene/ray/ray_create.c

INTERSECTOR_SRC = \
	intersector/hit/hit_record_set_face_normal.c \
	intersector/object/object_dispatch.c \
	intersector/object/world_hit.c \
	intersector/sphere/sphere_hit.c \
	intersector/plane/plane_hit.c \
	intersector/cylinder/cylinder_body.c \
	intersector/cylinder/cylinder_caps.c

PARSER_SRC = \
	parser/parser.c \
	parser/builder/build_ambient.c \
	parser/builder/build_camera.c \
	parser/builder/build_light.c \
	parser/builder/build_object.c \
	parser/builder/build_scene.c \
	parser/builder/builder_utils.c \
	parser/builder/create_object.c \
	parser/builder/objects/build_cylinder.c \
	parser/builder/objects/build_plane.c \
	parser/builder/objects/build_sphere.c \
	parser/converter/parse_color.c \
	parser/converter/parse_double.c \
	parser/converter/parse_point.c \
	parser/converter/parse_vector.c \
	parser/converter/utils.c \
	parser/lexer/create_token.c \
	parser/lexer/destroy_token_list.c \
	parser/lexer/get_token_type.c \
	parser/lexer/lexer_utils.c \
	parser/lexer/tokenize.c \
	parser/lexer/tokenize_line.c \
	parser/reader/destroy_lines.c \
	parser/reader/list_to_array.c \
	parser/reader/read_file.c \
	parser/reader/read_lines.c \
	parser/reader/reader_utils.c \
	parser/utils/copy_args.c \
	parser/utils/free_string_array.c \
	parser/validator/validate_arg_count.c \
	parser/validator/validate_scene_rules.c \
	parser/validator/validate_token_types.c \
	parser/validator/validator.c \
	parser/validator/validator_utils.c \
	parser/Cleanup/destroy_light_list.c \
	parser/Cleanup/destroy_object_list.c \
	parser/Cleanup/destroy_scene.c \
	parser/check/check_ratio.c \
	parser/check/check_positive.c \
	parser/check/check_fov.c \
	parser/check/check_normal.c \
	parser/check/check_color.c

	
RENDERER_SRC = \
	renderer/ambient.c \
	renderer/diffuse.c \
	renderer/render.c \
	renderer/ray_color.c \
	renderer/run_renderer.c \
	renderer/is_in_shadow.c \
	renderer/shade_hit.c

MLX_ENGINE_SRC = \
	mlx_engine/Display/mlx_display_image.c \
	mlx_engine/Events/mlx_event_close.c \
	mlx_engine/Events/mlx_event_init.c \
	mlx_engine/Events/mlx_event_key.c \
	mlx_engine/Events/mlx_event_loop.c \
	mlx_engine/Image/mlx_image_create.c \
	mlx_engine/Image/mlx_image_data.c \
	mlx_engine/Image/mlx_image_destroy.c \
	mlx_engine/Pixel/mlx_image_pixel_put.c \
	mlx_engine/Window/mlx_window_create.c \
	mlx_engine/Window/mlx_window_destroy.c

SRC = \
	$(MAIN_SRC) \
	$(UTILS_SRC) \
	$(GNL_SRC) \
	$(MATH_SRC) \
	$(SCENE_SRC) \
	$(INTERSECTOR_SRC) \
	$(PARSER_SRC) \
	$(RENDERER_SRC) \
	$(MLX_ENGINE_SRC)

OBJ = $(SRC:.c=.o)

# **************************************************************************** #
#                                    Rules                                     #
# **************************************************************************** #

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


# **************************************************************************** #
#                                   Cleaning                                   #
# **************************************************************************** #

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re	