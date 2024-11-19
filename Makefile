# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 10:41:01 by yel-yaqi          #+#    #+#              #
#    Updated: 2024/11/19 11:11:22 by aboulakr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CFLAGS = -Wall -Wextra -Werror

FREQ = 0

AMP = 0

CHECKER = 0

DIFFUSE = .9

SPECULAR = .9

DEPS = -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

MLX_HEADER = /Users/aboulakr/Desktop/MLX42.h

MLX_LIB = MLX/libmlx42.a

TESTS = rt_tests

TEST_CFILES = test_cfiles/test.c

TEST_OFILES = $(TEST_CFILES:.c=.o)

CFILES = data_structs/points_vectors.c \
		 maths/double_equality.c \
		 maths/tuple_ops.c \
		 maths/vector_math.c \
		 data_structs/colors.c \
		 data_structs/canvas.c \
		 data_structs/matrix.c \
		 data_structs/matrix_tuple.c \
		 data_structs/matrix_transform.c \
		 data_structs/matrix_invert.c \
		 data_structs/transformations.c \
		 data_structs/transformations_2.c \
		 data_structs/ray.c \
		 data_structs/objects.c \
		 data_structs/normals.c \
		 data_structs/lights.c \
		parser/get_next_line/get_next_line.c \
		parser/parse_rt.c \
		parser/parse.c \
		parser/parser_linked_lists.c \
		parser/parser_utils.c \
		parser/validate_line.c \
		parser/exitf.c \
		parser/atodbl.c \
		parser/validate_objects.c \
		parser/validate_envi.c \
		parser/parse_primitive.c \
		data_structs/world.c \
		data_structs/comps.c \
		data_structs/camera.c \
		data_structs/plane.c \
		data_structs/cylinder_cone.c \
		main.c
		

OFILES = $(CFILES:.c=.o)

maths/%.o: maths/%.c
	cc -g $(CFLAGS)  -c $< -o $@

data_structs/%.o: data_structs/%.c
	cc -g $(CFLAGS) -DAMP=$(AMP) -DFREQ=$(FREQ) -DCHECKER=$(CHECKER) -DDIFFUSE=$(DIFFUSE) -DSPECULAR=$(SPECULAR) -c $< -o $@

$(NAME): $(OFILES) $(MLX_LIB) Makefile
	cc $(DEPS) $(MLX_LIB) $(OFILES) -o $@

# $(TESTS): $(TEST_OFILES) $(MLX_LIB) $(OFILES)
# 	cc -g $(DEPS) $(MLX_LIB) $^ -o $@

parser_rt: $(MLX_LIB) $(OFILES)
	cc $(DEPS) $(MLX_LIB) $^ -o $@

all: $(NAME)

clean:
	rm -f $(TEST_OFILES)
	rm -f $(OFILES)

fclean: clean
	rm -f $(TESTS)
	rm -f parser_rt
	rm -f $(NAME)

re: fclean all