/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:47:12 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/18 18:52:11 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <libc.h>
#include "../data_structs/data_structs.h"
#include "../data_structs/data_funcs.h"
#include "../maths/maths.h"
#include <math.h>

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
	/*Magnitude*/
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
	/* NORM */
	a = vector(4, 0, 0);
	assert(equal_tuple(normalize_vec(a), vector(1, 0, 0)));
	a = vector(1, 2, 3);
	assert(equal_tuple(normalize_vec(a), vector(1/sqrt(14), 2/sqrt(14), 3/sqrt(14))));
	assert(vector_magnitude(normalize_vec(a)) == 1);
	/* DOT PRODUCT */
	a = vector(1, 2, 3);
	b = vector(2, 3, 4);
	assert(vec_dot(a, b) == 20);
	/* CROSS PRODUCT */
	assert(equal_tuple(vec_cross(a, b), vector(-1, 2, -1)));
	assert(equal_tuple(vec_cross(b, a), vector(1, -2, 1)));
	/* COLOR TESTS */
	a = color(-0.5, 0.4, 1.7);
	assert(equal_tuple(a, point(-0.5, 0.4, 1.7)));
}