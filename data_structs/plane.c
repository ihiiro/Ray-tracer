/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:36:48 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/19 13:20:27 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"
#include <math.h>
#include <stdlib.h>

t_xs	plane_intersect(t_plane *pl, t_ray ray)
{
	t_xs		list;
	t_matrix	*tmp_matrix;
	double		vd;

	tmp_matrix = invert_matrix(pl->transform, 4);
	ray = transform_ray(ray, tmp_matrix);
	free(tmp_matrix);
	vd = vec_dot(pl->normal, ray.direction);
	if (fabs(vd) > EPSILON)
	{
		list.t0 = vec_dot(sub_tuples(point(0, 0, 0),
					ray.origin), pl->normal) / vd;
		list.t1 = list.t0;
		list.count = 2;
		list.object0 = pl;
		list.object1 = pl;
	}
	else
		list.count = 0;
	return (list);
}

double	maximum_y(t_tuple center, double heigh)
{
	return (center.y + heigh / 2);
}

double	minimum_y(t_tuple	center, double heigh)
{
	return (center.y - heigh / 2);
}
