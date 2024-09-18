# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 10:41:01 by yel-yaqi          #+#    #+#              #
#    Updated: 2024/09/18 18:51:50 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = miniRT

# MLX = 

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

$(TESTS): $(TEST_OFILES) $(OFILES)
	cc $^ -o $@

all: $(TESTS)

clean:
	rm -f $(TEST_OFILES)
	rm -f $(OFILES)

fclean: clean
	rm -f $(TESTS)

re: fclean all