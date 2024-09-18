/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:47:12 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/18 13:52:39 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <libc.h>
#include "../data_structs/data_structs.h"
#include "../data_structs/data_funcs.h"

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
	a = vector(3, -2, 5);
	t_tuple b = point(-2, 3, 1);
	t_tuple sum_a_b = add_tuples(a, b);
	assert(equal_tuple(sum_a_b, point(1, 1, 6)));
	
}