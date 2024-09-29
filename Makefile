# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 10:41:01 by yel-yaqi          #+#    #+#              #
#    Updated: 2024/09/29 16:58:13 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = miniRT

# CFLAGS = DONT FORGET

DEPS = -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

MLX_HEADER = MLX/MLX42.h

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
		parser/parse_rt.c 

OFILES = $(CFILES:.c=.o)



data_structs/%.o: data_structs/%.c
	cc -c $< -o $@

test_fcfiles/%.o: test_fcfiles/%.c
	cc -c $<

$(TESTS): $(TEST_OFILES) $(MLX_LIB) $(OFILES)
	cc $(DEPS) $(MLX_LIB) $^ -o $@

parser_rt: $(MLX_LIB) $(OFILES)
	cc $(DEPS) $(MLX_LIB) $^ -o $@

all: $(TESTS)

clean:
	rm -f $(TEST_OFILES)
	rm -f $(OFILES)

fclean: clean
	rm -f $(TESTS)

re: fclean all