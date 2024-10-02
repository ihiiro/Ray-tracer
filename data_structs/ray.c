/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:52:35 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/02 00:29:30 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"
#include <stdlib.h>
#include <math.h>
#include <limits.h>

t_ray	return_ray(t_tuple org, t_tuple dir)
{
	t_ray ray;

	ray.origin = org;
	ray.direction = dir;
	return (ray);
}
t_tuple position(t_ray ray, double t)
{
	return (add_tuples(ray.origin, scale_tuple(ray.direction, t)));
}

t_xs	sphere_intersect(t_sphere *s, t_ray r)
{
	t_tuple sphere_to_ray;
	t_xs	xs;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	t_matrix *tmp_matrix = invert_matrix(s->transform, 4);
	r = transform_ray(r, tmp_matrix);
	free(tmp_matrix);
	sphere_to_ray = sub_tuples(r.origin, s->center);
	a = vec_dot(r.direction, r.direction);
	b = 2 * vec_dot(r.direction, sphere_to_ray);
	c = vec_dot(sphere_to_ray, sphere_to_ray) -1;
	discriminant = pow(b, 2) - 4 * a * c;
	if (discriminant < 0)
		return (xs.count = 0, xs.t0 = 0, xs.t1 = 0, xs.object0 = NULL, xs.object1 = NULL, xs);
	xs.count = 2;
	xs.object0 = s;
	xs.object1 = s;
	xs.t0 = (-b - sqrt(discriminant)) / (2 * a);
	xs.t1 = (-b + sqrt(discriminant)) / (2 * a);
	
	return (xs);
}

// t_intersection	hit(t_intersection *intersections)
// {
// 	int				n;
// 	int				i;
// 	t_intersection	hit_intersection;

// 	n = intersections[0].atom_count;
// 	hit_intersection.t = INT_MAX;
// 	hit_intersection.object = intersections[0].object;
// 	i = 0;
// 	while (i < n)
// 	{
// 		if (intersections[i].t >= 0 && intersections[i].t < hit_intersection.t)
// 			hit_intersection = intersections[i];
// 		i++;
// 	}
// 	return (hit_intersection);
// }

t_xs_list	*hit(t_xs_list *xs_list)
{
	while (xs_list)
	{
		if (xs_list->t >= 0)
			return (xs_list);
		xs_list = xs_list->next;
	}
	return (xs_list);
}


t_ray		transform_ray(t_ray r, t_matrix *m)
{
	t_ray	ray;

	ray.origin = multiply_matrix_by_tuple(m, r.origin);
	ray.direction = multiply_matrix_by_tuple(m, r.direction);
	return (ray);
}


// 2 4 2 2

// 2