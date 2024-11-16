/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:47:49 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/15 16:19:09 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data_structs/data_funcs.h"

#include <libc.h>

bool	equal_tuple(t_tuple a, t_tuple b)
{
	if (equal(a.x, b.x) && equal(a.y, b.y)
		&& equal(a.z, b.z) && equal(a.w, b.w))
		return (true);
	return (false);
}

t_tuple	add_tuples(t_tuple a, t_tuple b)
{
	return (get_tuple(
			a.x + b.x,
			a.y + b.y,
			a.z + b.z,
			a.w + b.w
		));
}

t_tuple	sub_tuples(t_tuple a, t_tuple b)
{
	return (get_tuple(
			a.x - b.x,
			a.y - b.y,
			a.z - b.z,
			a.w - b.w
		));
}

t_tuple	negate_tuple(t_tuple t)
{
	return (get_tuple(-t.x, -t.y, -t.z, -t.w));
}

t_tuple	scale_tuple(t_tuple a, double scalar)
{
	return (get_tuple(a.x * scalar,
			a.y * scalar,
			a.z * scalar,
			a.w * scalar
		));
}
