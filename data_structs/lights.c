/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:51:33 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/18 12:28:11 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"
#include <stdlib.h>
#include <math.h>

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	return(sub_tuples(in, scale_tuple(normal, 2 * vec_dot(in, normal))));
}

t_light		point_light(t_tuple position, t_tuple intensity)
{
	t_light light;

	light.intensity = intensity;
	light.position  = position;
	return (light);
}

t_material	material(void)
{
	t_material	m;

	m.color = color(1, 1, 1);
	m.ambient = 0.1;
	m.diffuse = 0.9;
	m.specular = 0.9;
	m.shininess = 200.0;
	return (m);
}

t_tuple lighting(t_lighting l)
{
	t_lighting_components	lc;

	lc.effective_color = multiply_colors(l.m.color, l.light.intensity);
	lc.lightv = normalize_vec(sub_tuples(l.light.position, l.point));
	lc.ambient = multiply_color_by_scalar(l.ambient_effective_color, l.m.ambient);
	lc.light_dot_normalv = vec_dot(lc.lightv, l.normalv);
	if (lc.light_dot_normalv < 0 || l.in_shadow == true)
	{
		lc.diffuse = color(0, 0, 0);
		lc.specular = color(0, 0, 0);
	}
	else if (l.in_shadow == false)
	{
		lc.diffuse = multiply_color_by_scalar(lc.effective_color, l.m.diffuse * lc.light_dot_normalv);
		lc.reflectv = reflect(negate_tuple(lc.lightv), l.normalv);
		lc.reflect_dot_eye = vec_dot(lc.reflectv, l.eyev);
		if (lc.reflect_dot_eye <= 0)
			lc.specular = color(0, 0, 0);
		else
		{
			lc.specular_factor = pow(lc.reflect_dot_eye, l.m.shininess);
			lc.specular = multiply_color_by_scalar(l.light.intensity, l.m.specular * lc.specular_factor);
		}
	}
	lc.intensity = add_colors(lc.ambient, add_colors(lc.diffuse, lc.specular));
	return (lc.intensity);
}

bool	is_shadowed(t_world *w, t_tuple point)
{
	t_tuple	v;
	double	distance;
	t_tuple	direction;
	t_ray	ray;
	t_xs_list	*intersections;
	t_xs_list	*h;

	v = sub_tuples(w->lights_list->pos, point);
	distance = vector_magnitude(v);
	direction = normalize_vec(v);
	ray = return_ray(point, direction);
	intersections = intersect_world(w, ray);
	h =  hit(intersections);
	if (h != NULL && h->t < distance)
		return (true);
	else
		return (false);
}
