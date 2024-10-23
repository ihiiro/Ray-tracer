/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:36:48 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/23 21:45:54 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"
#include <math.h>
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

#include <libc.h>

t_xs	cylinder_intersect(t_cylinder *cy, t_ray ray)
{
	double	a;
	double	b;
	double	c;
	double	disc;
	double	y0;
	double	y1;
	t_xs	list;
	t_matrix	*tmp_matrix;

	cy->maximum = maximum_y(cy->center, cy->height);
	cy->minimum = minimum_y(cy->center, cy->height);
	tmp_matrix = invert_matrix(cy->transform, 4);
	ray = transform_ray(ray, tmp_matrix);
	free(tmp_matrix);
	a = pow(ray.direction.x, 2)+ pow(ray.direction.z, 2);
	b = 2 * (ray.origin.x * ray.direction.x + ray.origin.z * ray.direction.z);
	c = pow(ray.origin.x, 2)+ pow(ray.origin.z, 2) - 1;
	disc = pow(b, 2) - 4 * a * c;
	if (disc < 0 || fabs(a) < EPSILON)
		list.count = 0;
	else
	{
		list.count = 2;
		list.object0 = cy;
		list.object1 = cy;
		list.t0 = (-b - sqrt(disc)) / (2 * a);
		list.t1 = (-b + sqrt(disc)) / (2 * a);
		if (list.t0 > list.t1)
		{
			double tmp = list.t0;
			list.t0 = list.t1;
			list.t1 = tmp;
		}
		y0 = ray.origin.y + list.t0 * ray.direction.y;
		y1 = ray.origin.y + list.t1 * ray.direction.y;
		if ((cy->minimum >= y0 || y0 >= cy->maximum) && (cy->minimum < y1 && y1 < cy->maximum))
		{
			list.count = 2;
			list.t0 = list.t1;
		}
		else if ((cy->minimum >= y1 || y1 >= cy->maximum) && (cy->minimum < y0 && y0 < cy->maximum))	
		{
			list.count = 2;
			list.t1 = list.t0;
		}
		else if ((cy->minimum >= y1 || y1 >= cy->maximum) && (cy->minimum >= y0 || y0 >= cy->maximum))
			list.count = 0;
	}
	return (list);
}
t_tuple		normal_at_cylinder(t_cylinder cy, t_tuple point)
{
	t_tuple		object_point;
	t_tuple		object_normal;
	t_tuple		world_normal;

	object_point = multiply_matrix_by_tuple(invert_matrix(cy.transform, 4), point);
	object_normal = vector(object_point.x, 0, object_point.z);
	world_normal = multiply_matrix_by_tuple(matrix_transpose(invert_matrix(cy.transform, 4), 4), object_normal);
	world_normal.w = VECTOR;
	return (normalize_vec(world_normal));
}

/*detrmine the maximum and minimum y for a cylinder*/

double	maximum_y(t_tuple center, double	heigh)
{
	return (center.y + heigh / 2);
}

double	minimum_y(t_tuple	center, double heigh)
{
	return (center.y - heigh / 2);
}