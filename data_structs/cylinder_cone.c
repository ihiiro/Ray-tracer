/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_cone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:07:37 by aboulakr          #+#    #+#             */
/*   Updated: 2024/11/15 14:37:03 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_funcs.h"
#include "data_structs.h"
#include "../maths/maths.h"
#include <math.h>
#include <stdlib.h>

void	calculations(t_xs	*list, t_disc *disc, t_cylinder *cy, t_ray *ray)
{
	double		y0;
	double		y1;
	double		tmp;

	(1) && (list->count = 2, list->object0 = cy, list->object1 = cy,
		list->t0 = (-disc->b - sqrt(disc->disc)) / (2 * disc->a), list->t1
			= (-disc->b + sqrt(disc->disc)) / (2 * disc->a));
	(list->t0 > list->t1) && (tmp = list->t0, list->t0 = list->t1,
	list->t1 = tmp);
	y0 = ray->origin.y + list->t0 * ray->direction.y;
	y1 = ray->origin.y + list->t1 * ray->direction.y;
	if ((cy->minimum >= y0 || y0 >= cy->maximum)
		&& (cy->minimum < y1 && y1 < cy->maximum))
	{
		list->count = 2;
		list->t0 = list->t1;
	}
	else if ((cy->minimum >= y1 || y1 >= cy->maximum)
		&& (cy->minimum < y0 && y0 < cy->maximum))
		(1) && (list->count = 2, list->t1 = list->t0);
	else if ((cy->minimum >= y1 || y1 >= cy->maximum)
		&& (cy->minimum >= y0 || y0 >= cy->maximum))
		list->count = 0;
}

void	cone_intersect(t_xs *cone, t_cylinder *cy, t_ray ray)
{
	t_disc		disc;

	cy->maximum = maximum_y(cy->center, cy->height);
	cy->minimum = minimum_y(cy->center, cy->height);
	disc.a = pow(ray.direction.x, 2) - pow(ray.direction.y, 2)
		+ pow(ray.direction.z, 2);
	disc.b = 2 * (ray.origin.x * ray.direction.x) - 2 * (ray.origin.y
			* ray.direction.y) + 2 * (ray.origin.z * ray.direction.z);
	disc.c = pow(ray.origin.x, 2) - pow(ray.origin.y, 2) + pow(ray.origin.z, 2);
	if (disc.a == 0 && disc.b == 0)
		cone->count = 0;
	else if (disc.a == 0 && disc.b != 0)
	{
		(1) && (cone->count = 2, cone->object0 = cy, cone->object1 = cy,
		cone->t0 = -disc.c / (2 * disc.b), cone->t1 = -disc.c / (2 * disc.b));
	}
	else
		disc.disc = pow(disc.b, 2) - 4 * disc.a * disc.c;
	if (disc.disc < 0)
		cone->count = 0;
	else
		calculations(cone, &disc, cy, &ray);
}

t_xs	cylinder_intersect(t_cylinder *cy, t_ray ray, int form)
{
	t_disc		discr;
	t_xs		list;
	t_matrix	*tmp_matrix;

	cy->maximum = maximum_y(cy->center, cy->height);
	cy->minimum = minimum_y(cy->center, cy->height);
	tmp_matrix = invert_matrix(cy->transform, 4);
	ray = transform_ray(ray, tmp_matrix);
	free(tmp_matrix);
	if (form == CYLINDER)
	{
		discr.a = pow(ray.direction.x, 2) + pow(ray.direction.z, 2);
		discr.b = 2 * (ray.origin.x * ray.direction.x
				+ ray.origin.z * ray.direction.z);
		discr.c = pow(ray.origin.x, 2) + pow(ray.origin.z, 2) - 1;
		discr.disc = pow(discr.b, 2) - 4 * discr.a * discr.c;
		if (discr.disc < 0 || fabs(discr.a) < EPSILON)
			list.count = 0;
		else
			calculations(&list, &discr, cy, &ray);
	}
	else
		cone_intersect(&list, cy, ray);
	return (list);
}

t_tuple	normal_at_cylinder(t_cylinder cy, t_tuple point)
{
	t_tuple		object_point;
	t_tuple		object_normal;
	t_tuple		world_normal;

	object_point = multiply_matrix_by_tuple(invert_matrix(cy.transform, 4),
			point);
	object_normal = vector(object_point.x, 0, object_point.z);
	world_normal = multiply_matrix_by_tuple(matrix_transpose(invert_matrix(
					cy.transform, 4), 4), object_normal);
	world_normal.w = VECTOR;
	return (normalize_vec(world_normal));
}
