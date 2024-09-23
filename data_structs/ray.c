/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:52:35 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/23 20:40:36 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"
#include <stdlib.h>
#include <math.h>

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
