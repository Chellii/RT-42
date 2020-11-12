# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 16:49:38 by cel-oiri          #+#    #+#              #
#    Updated: 2020/11/07 20:13:57 by aait-ihi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rt
SRC =	main.c \
		color.c \
		deal_key.c \
		equation.c \
		equation2.c \
		fct_help.c \
		filter.c \
		freefct.c \
		graph.c \
		graph_mb.c \
		graph_multi_thread.c \
		graph_multi_thread2.c \
		help_file.c \
		intersection.c \
		move.c \
		ray_intersection.c \
		shade.c \
		tools.c \
		hit_fct.c \
		vec_op_1.c \
		vec_op_2.c \
		intersect_neg.c \
		scene_fct.c \
		noise.c \
		noise2.c \
		raytracing_color.c \
		set_texture.c \
		refl_refr.c \
		hit_fct2.c \
		intersect_ray.c \
		phong_shading.c \
		toon_shading.c \
		spot_light.c \
		intersect_ray2.c \
		intersect_ray3.c \
		intersection2.c \
		menu.c \
		mlx_fct.c \
		motion_blur.c \
		limit_xyz.c \
		mouse_fct.c \
		xor_noise.c \
		eq.c \
		bmp.c \


SRC_DIR = ./src

PARSER_SRC =	create_tag_rule.c\
				element.c\
				make_elements.c\
				make_object.c\
				make_all.c\
				valid_rt_xml.c\
				valide_rule.c

PARSER_SRC_DIR = ./parse


OBJ_DIR = ./obj

OBJTMP = $(SRC:%.c=%.o) $(PARSER_SRC:%.c=%.o)

OBJ = $(addprefix $(OBJ_DIR)/,$(OBJTMP))

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIB = -L./libft -lft -lm -lmlx -framework OpenGL -framework AppKit

INC = -I includes -I xml -I libft/includes

HEADER = includes/rt.h includes/parse.h

all : make_libft $(NAME)

make_libft:
	make -C libft

$(NAME): libft/libft.a $(OBJ)
	$(CC) $(FLAGS) $(INC) -o $(NAME) $(OBJ) $(LIB)


$(OBJ_DIR)/%.o :src/%.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(FLAGS) -o $@ -c $< $(INC)
	
$(OBJ_DIR)/%.o : $(PARSER_SRC_DIR)/%.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(FLAGS) -o $@ -c $< $(INC)

$(OBJ_DIR):
	@-mkdir $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	@make clean -C libft

fclean: clean
	rm -f $(NAME)
	@make fclean -C libft

re: fclean all
