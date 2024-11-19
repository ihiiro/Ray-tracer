/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:51:33 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/19 13:20:27 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"
#include <stdlib.h>
#include <math.h>

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	return (sub_tuples(in, scale_tuple(normal, 2 * vec_dot(in, normal))));
}

t_light	point_light(t_tuple position, t_tuple intensity)
{
	t_light	light;

	light.intensity = intensity;
	light.position = position;
	return (light);
}

t_material	material(void)
{
	t_material	m;

	m.color = color(1, 1, 1);
	m.ambient = 0.1;
	m.diffuse = DIFFUSE;
	m.specular = SPECULAR;
	m.shininess = 200.0;
	return (m);
}

t_tuple	lighting(t_lighting l)
{
	t_lighting_components	lc;

	lc.effective_color = multiply_colors(l.m.color, l.light.intensity);
	lc.lightv = normalize_vec(sub_tuples(l.light.position, l.point));
	lc.ambient = col_x_sc(l.am_eff_col,
			l.m.ambient);
	lc.light_dot_normalv = vec_dot(lc.lightv, l.normalv);
	if (lc.light_dot_normalv < 0 || l.in_shadow == true)
		(1) && (lc.diffuse = color(0, 0, 0), lc.specular = color(0, 0, 0), 0);
	else if (l.in_shadow == false)
	{
		lc.diffuse = col_x_sc(lc.effective_color,
				l.m.diffuse * lc.light_dot_normalv);
		lc.reflectv = reflect(negate_tuple(lc.lightv), l.normalv);
		lc.reflect_dot_eye = vec_dot(lc.reflectv, l.eyev);
		if (lc.reflect_dot_eye <= 0)
			lc.specular = color(0, 0, 0);
		else
			(1) && (lc.specular_factor = pow(lc.reflect_dot_eye, l.m.shininess),
				lc.specular = col_x_sc(l.light.intensity,
					l.m.specular * lc.specular_factor), 0);
	}
	lc.intensity = add_colors(lc.ambient, add_colors(lc.diffuse, lc.specular));
	return (lc.intensity);
}

bool	is_shadowed(t_world *w, t_light_ *light, t_tuple point)
{
	t_shadow	shadow;
	t_ray		ray;
	t_xs_list	*intersections;
	t_xs_list	*h;
	t_xs_list	*tmp;

	shadow.v = sub_tuples(light->pos, point);
	shadow.distance = vector_magnitude(shadow.v);
	shadow.direction = normalize_vec(shadow.v);
	ray = get_ray(point, shadow.direction);
	intersections = intersect_world(w, ray);
	h = hit(intersections);
	if (h != NULL && h->t < shadow.distance)
		shadow.shadowed = true;
	else
		shadow.shadowed = false;
	while (intersections)
	{
		tmp = intersections->next;
		free(intersections);
		intersections = tmp;
	}
	return (shadow.shadowed);
}
