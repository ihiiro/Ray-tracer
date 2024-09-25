/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:30:17 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/25 18:58:17 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#include <libc.h>

void	set_transform(t_sphere *s, t_matrix *m)
{
	s->transform = m;
}

t_tuple	normal_at(t_sphere s, t_tuple world_point)
{
	t_tuple	object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;

	object_point = multiply_matrix_by_tuple(invert_matrix(s.transform, 4), world_point);
	object_normal = vector(object_point.x, object_point.y, object_point.z);
	world_normal = multiply_matrix_by_tuple(matrix_transpose(invert_matrix(s.transform, 4), 4), object_normal);
	world_normal.w = VECTOR;
	return (normalize_vec(world_normal));
}
