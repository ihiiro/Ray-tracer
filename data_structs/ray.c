/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:52:35 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/15 16:15:45 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"
#include <stdlib.h>
#include <math.h>

t_ray	get_ray(t_tuple org, t_tuple dir)
{
	t_ray	ray;

	ray.origin = org;
	ray.direction = dir;
	return (ray);
}

t_tuple	position(t_ray ray, double t)
{
	return (add_tuples(ray.origin, scale_tuple(ray.direction, t)));
}

t_xs	sphere_intersect(t_sphere *s, t_ray r)
{
	t_tuple		sphere_to_ray;
	t_xs		xs;
	t_disc		disc;
	double		discriminant;
	t_matrix	*tmp_matrix;

	tmp_matrix = invert_matrix(s->transform, 4);
	r = transform_ray(r, tmp_matrix);
	free(tmp_matrix);
	sphere_to_ray = sub_tuples(r.origin, s->center);
	disc.a = vec_dot(r.direction, r.direction);
	disc.b = 2 * vec_dot(r.direction, sphere_to_ray);
	disc.c = vec_dot(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = pow(disc.b, 2) - 4 * disc.a * disc.c;
	if (discriminant < 0)
		return (xs.count = 0, xs.t0 = 0, xs.t1 = 0,
			xs.object0 = NULL, xs.object1 = NULL, xs);
	xs.count = 2;
	xs.object0 = s;
	xs.object1 = s;
	xs.t0 = (-disc.b - sqrt(discriminant)) / (2 * disc.a);
	xs.t1 = (-disc.b + sqrt(discriminant)) / (2 * disc.a);
	return (xs);
}

t_xs_list	*hit(t_xs_list *xs_list)
{
	while (xs_list)
	{
		if (xs_list->t >= 0)
			return (xs_list);
		xs_list = xs_list->next;
	}
	return (NULL);
}

t_ray	transform_ray(t_ray r, t_matrix *m)
{
	t_ray	ray;

	ray.origin = multiply_matrix_by_tuple(m, r.origin);
	ray.direction = multiply_matrix_by_tuple(m, r.direction);
	return (ray);
}
