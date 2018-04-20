# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/09 20:49:49 by rqueverd          #+#    #+#              #
#    Updated: 2017/06/21 11:53:59 by rqueverd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RT

C_FILES = main.c \
		  color_maths.c \
		  color_tools.c \
		  csg_diff.c \
		  csg_inter.c \
		  csg_add.c \
		  display.c \
		  display_names.c \
		  display_scene_tmb.c \
		  events_menu.c \
		  events_scene.c \
		  events_scene_look.c \
		  events_scene_movement.c \
		  events_scene_movement_up_down.c \
		  free_functions.c \
		  ft_error.c\
		  get_obj_color.c \
		  get_obj_color_bis.c \
		  get_obj_normal.c \
		  get_obj_normal_bis.c \
		  get_obj_tf_list.c \
		  get_obj_tf_list_complex.c \
		  get_list_from_page.c \
		  init_camera.c \
		  init_env.c \
		  init_cut_condition.c \
		  init_function.c \
		  init_img.c \
		  init_light.c \
		  init_obj_cone.c \
		  init_obj_cube.c \
		  init_obj_cylinder.c \
		  init_obj_hyperboloid.c \
		  init_obj_paraboloid.c \
		  init_obj_plane.c \
		  init_obj_prism.c \
		  init_obj_sphere.c \
		  init_obj_triangle.c \
		  init_obj_triangle_bis.c \
		  init_scenes.c \
		  init_obj_csg.c \
		  init_solid.c \
		  init_vector.c \
		  list_light_manage.c \
		  list_obj_cone.c \
		  list_obj_cube.c \
		  list_obj_cylinder.c \
		  list_obj_hyperboloid.c \
		  list_obj_paraboloid.c \
		  list_obj_plane.c \
		  list_obj_prism.c \
		  list_obj_sphere.c \
		  list_obj_triangle.c \
		  list_obj_csg.c \
		  list_scene.c \
		  maths_matrix.c \
		  maths_matrix_rotation.c \
		  maths_matrix_scale.c \
		  maths_matrix_translation.c \
		  maths_obj_cone.c \
		  maths_obj_cube.c \
		  maths_obj_cylinder.c \
		  maths_obj_hyperboloid.c \
		  maths_obj_paraboloid.c \
		  maths_obj_plane.c \
		  maths_obj_prism.c \
		  maths_obj_sphere.c \
		  maths_obj_triangle.c \
		  maths_vector_calc.c \
		  maths_vector_op.c \
		  obj_apply_parameters.c\
		  light_cam_apply_parameters.c\
		  obj_apply_parameters_basic.c\
		  obj_apply_parameters_complex.c\
		  obj_parameter_parser.c\
		  light_cam_populators.c\
		  objects_populators_basic.c\
		  objects_populators_complex.c\
		  parameter_input_testers.c \
		  parser.c\
		  parser_check.c\
		  parser_lexer.c \
		  parser_line_identifier.c\
		  post_pro_eblouissement.c \
		  post_pro_hub.c \
		  post_pro_img_anaglyph.c \
		  post_pro_recolor.c \
		  putpixel.c \
		  init_ray.c \
		  record_tools.c \
		  rt_calculate_ray.c \
		  rt_find_n.c \
		  rt_get_color_at.c \
		  rt_get_pixel_color.c \
		  rt_raytracer.c \
		  rt_reflection.c \
		  rt_shadow.c \
		  specular.c \
		  texture_getter.c \
		  texture_modifiers.c \
		  texture_manager.c \
		  tf_add.c \
		  tf_apply.c \
		  tf_free.c \
		  tf_push.c \
		  tools.c\
		  events_select_scene.c \
		  cut_object.c \
		  cut_save.c \
		  cut_select_negative.c \
		  cut_select_positive.c \
		  cut_select_special.c \
		  cut_select_neg_or_pos.c \
		  cut_keep.c \
		  cut_research_in_cone.c \
		  init_button.c \
		  events_redirect.c \
		  maths_obj_csg.c \

INC_NAME = rt.h \
		   mlx.h \
		   libft.h \
		   parser.h\
		   keys.h

CC = gcc -Wextra -Werror -Wall -o3
MLX_FLAGS = -lft -lmlx -framework OpenGL -framework Appkit
LIBFT = libft.a
LIBMLX = libmlx.a
LIBFT_DIR = libft/
LIB_DIR = lib/
INC_DIR = inc/
EXEC_NAME = RT

INC = $(addprefix inc/,$(INC_NAME))
OBJ = $(addprefix $(O_PATH), $(C_FILES:.c=.o))
SRC = $(addprefix $(C_PATH), $(C_FILES))

######

C_PATH = ./src/
O_PATH = ./obj/

$(addprefix $(O_PATH),%.o): $(addprefix $(C_PATH),%.c)
	@mkdir -p $(O_PATH)
	@$(CC) -o $@ -c $^ -I inc/
	@echo -n .

all: $(NAME)

$(NAME): create_libft obj_comp $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) -Llib $(MLX_FLAGS)
	@echo "\n\x1b[32m-- COMPILING SUCCESSFULL --"

create_libft:
	@echo "\x1b[31mMaking LIBFT ...\033[0m"
	@make -s -C $(LIBFT_DIR)
	@mkdir -p lib
	@cp $(LIBFT_DIR)$(LIBFT) $(LIB_DIR)$(LIBFT)
	@cp $(LIBFT_DIR)/includes/libft.h $(INC_DIR)libft.h

obj_comp:
	@echo "\x1b[33m-- COMPILING ... --\033[0m"

norminette:
	@echo "----------NORMINETTE------------"
	@echo "\x1b[37m"
	@norminette ./libft/*.h
	@norminette ./libft/*.c
	@norminette ./inc/*.h
	@norminette ./src/*.c

welcome:
	@echo "Welcome to our project."
	@echo "To launch the program, please use both following commands"
	@echo "> make\n> ./RT"

clean:
	@make fclean -C $(LIBFT_DIR)
	@echo "libft cleaned"
	@rm -f $(INC_DIR)libft.h
	@rm -f $(INC_DIR)mlx.h
	@rm -rf ./obj
	@rm -rf ./lib
	@echo ".o cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "exec deleted"
	@echo "Project Cleaned."

re: fclean all

fcleanlibft:
	make fclean -C $(LIBFT_DIR)
