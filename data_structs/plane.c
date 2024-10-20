/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:36:48 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/20 10:16:58 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"
#include <math.h>
#include <libc.h>


/*

float denom = normal.dot(ray.direction);
if (abs(denom) > 0.0001f) // your favorite epsilon
{
    float t = (center - ray.origin).dot(normal) / denom;
    if (t >= 0) return true; // you might want to allow an epsilon here too
}
return false;

*/
#include <libc.h>
t_xs	plane_intersect(t_plane *pl, t_ray ray)
{
	t_xs 		list;
	t_matrix	*tmp_matrix;
	double		vd;

	tmp_matrix = invert_matrix(pl->transform, 4);
	ray = transform_ray(ray, tmp_matrix);
	free(tmp_matrix);
	vd = vec_dot(pl->normal, ray.direction);
	if (fabs(vd) > EPSILON)
	{
		list.t0 = vec_dot(sub_tuples(point(0, 0, 0), ray.origin), pl->normal) / vd;
		list.t1 = list.t0;
		list.count = 2;
		list.object0 = pl;
		list.object1 = pl;
	}
	else
		list.count = 0;
	return (list);
}

// t_xs	plane_intersect(t_plane *pl, t_ray ray)
// {
// 	t_xs 		list;
// 	t_matrix	*tmp_matrix;

// 	tmp_matrix = invert_matrix(pl->transform, 4);
// 	ray = transform_ray(ray, tmp_matrix);
// 	free(tmp_matrix);
// 	if (fabs(ray.direction.y) < EPSILON)
// 		return (list.count = 0, list);
// 	list.t0 = -(ray.origin.y) / ray.direction.y;
// 	list.t1 = list.t0;
// 	list.count = 2;
// 	list.object0 = pl;
// 	list.object1 = pl;
// 	return (list);
// }
