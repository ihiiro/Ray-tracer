# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 10:41:01 by yel-yaqi          #+#    #+#              #
#    Updated: 2024/09/19 13:13:48 by aboulakr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = miniRT

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
		 data_structs/colors.c

OFILES = $(CFILES:.c=.o)

data_structs/%.o: data_structs/%.c
	cc -c $< -o $@

test_fcfiles/%.o: test_fcfiles/%.c
	cc -c $<

$(TESTS): $(TEST_OFILES) $(MLX_LIB) $(OFILES)
	cc $(DEPS) $(MLX_LIB) $^ -o $@

all: $(TESTS)

clean:
	rm -f $(TEST_OFILES)
	rm -f $(OFILES)

fclean: clean
	rm -f $(TESTS)

re: fclean all