/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:47:12 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/20 11:12:13 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <libc.h>
#include "../data_structs/data_structs.h"
#include "../data_structs/data_funcs.h"
#include "../maths/maths.h"
#include <math.h>
#include "../MLX/MLX42.h"

int main()
{
	/* TUPLES TESTS */
	t_tuple a = return_tuple(4.3, -4.2, 3.1, POINT);
	assert(a.x == 4.3);
	assert(a.y == -4.2);
	assert(a.z == 3.1);
	assert(a.w == POINT);
	assert(point_or_vector(a) == POINT);
	a = return_tuple(4.3, -4.2, 3.1, VECTOR);
	assert(point_or_vector(a) == VECTOR);
	/* VECTOR/POINT TESTS */
	a = point(4.3, -4.2, 3.1);
	assert(a.x == 4.3);
	assert(a.y == -4.2);
	assert(a.z == 3.1);
	assert(a.w == POINT);
	a = vector(4.3, -4.2, 3.1);
	assert(a.x == 4.3);
	assert(a.y == -4.2);
	assert(a.z == 3.1);
	assert(a.w == VECTOR);
	/* TUPLE ARITHMETIC TESTS */
	a = vector(3, -2, 5); // addition
	t_tuple b = point(-2, 3, 1);
	t_tuple sum_a_b = add_tuples(a, b);
	assert(equal_tuple(sum_a_b, point(1, 1, 6)));
	a = point(3, 2, 1); // subtraction
	b = point(5, 6, 7);
	t_tuple diff_a_b = sub_tuples(a, b);
	assert(equal_tuple(diff_a_b, vector(-2, -4, -6)));
	b = vector(5, 6, 7);
	diff_a_b = sub_tuples(a, b);
	assert(equal_tuple(diff_a_b, point(-2, -4, -6)));
	a = vector(3, 2, 1);
	b = vector(5, 6, 7);
	diff_a_b = sub_tuples(a, b);
	assert(equal_tuple(diff_a_b, vector(-2, -4, -6)));
	a = vector(1, -2, 3);
	assert(equal_tuple(negate_tuple(a), return_tuple(-1, 2, -3, VECTOR)));
	a = return_tuple(1, -2, 3, -4);
	assert(equal_tuple(scale_tuple(a, 3.5), return_tuple(3.5, -7, 10.5, -14)));
	assert(equal_tuple(scale_tuple(a, 0.5), return_tuple(0.5, -1, 1.5, -2)));
	/* VECTOR MATH TESTS */
	/*Magnitude TESTS*/
	a = vector(1, 0, 0);
	assert(vector_magnitude(a) == 1);
	a = vector(0, 1, 0);
	assert(vector_magnitude(a) == 1);
	a = vector(0, 0, 1);
	assert(vector_magnitude(a) == 1);
	a = vector(1, 2, 3);
	assert(vector_magnitude(a) == sqrt(14));
	a = vector(-1, -2, -3);
	assert(vector_magnitude(a) == sqrt(14));
	/* NORM TESTS */
	a = vector(4, 0, 0);
	assert(equal_tuple(normalize_vec(a), vector(1, 0, 0)));
	a = vector(1, 2, 3);
	assert(equal_tuple(normalize_vec(a), vector(1/sqrt(14), 2/sqrt(14), 3/sqrt(14))));
	assert(vector_magnitude(normalize_vec(a)) == 1);
	/* DOT PRODUCT TESTS */
	a = vector(1, 2, 3);
	b = vector(2, 3, 4);
	assert(vec_dot(a, b) == 20);
	/* CROSS PRODUCT TESTS */
	assert(equal_tuple(vec_cross(a, b), vector(-1, 2, -1)));
	assert(equal_tuple(vec_cross(b, a), vector(1, -2, 1)));
	/* COLOR TESTS */
	a = color(-0.5, 0.4, 1.7);
	assert(equal_tuple(a, vector(-0.5, 0.4, 1.7)));
	/* COLOR ARITHMETIC TESTS */ 
	a = color(0.9, 0.6, 0.75);
	b = color(0.7, 0.1, 0.25);
	assert(equal_tuple(add_colors(a, b), color(1.6, 0.7, 1.0)));
	assert(equal_tuple(sub_colors(a, b), color(0.2, 0.5, 0.5)));
	a = color(0.2, 0.3, 0.4);
	assert(equal_tuple(multiply_color_by_scalar(a, 2), color(0.4, 0.6, 0.8)));
	a = color(1, 0.2, 0.4);
	b = color(0.9, 1, 0.1);
	assert(equal_tuple(multiply_colors(a, b), color(0.9, 0.2, 0.04)));
	/* CANVAS TESTS */
	t_canvas	c = canvas(200, 200);
	assert(c.width == 200 && c.height == 200);
	for (int x = 0; x < 200; x++)
		for (int y = 0; y < 200; y++)
			assert(equal_tuple(c.pixels[x][y].color, color(255, 255, 255)));
	write_pixel(&c, 2, 3, color(255, 0, 0));
	assert(equal_tuple(*pixel_at(&c, 2, 3), color(255, 0, 0)));
}