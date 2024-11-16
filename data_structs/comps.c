/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 00:38:01 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/16 12:55:43 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"
#include <math.h>
#include <stdlib.h>

t_comps	prepare_computations(t_xs_list *intersection, t_ray ray)
{
	t_comps	comps;

	comps.t = intersection->t;
	comps.object.object = intersection->object.object;
	comps.object.form = intersection->object.form;
	comps.point = position(ray, comps.t);
	comps.eyev = negate_tuple(ray.direction);
	if (intersection->object.form == SPHERE)
		comps.normalv = normal_at(*(t_sphere *)comps.object.object,
				comps.point);
	else if (intersection->object.form == PLANE)
		comps.normalv = ((t_plane *)intersection->object.object)->normal;
	else if (intersection->object.form == CYLINDER
		|| intersection->object.form == CONE)
		comps.normalv = normal_at_cylinder(*(t_cylinder *)comps.object.object,
				comps.point);
	if (vec_dot(comps.normalv, comps.eyev) < 0)
		(1) && (comps.inside = true,
			comps.normalv = negate_tuple(comps.normalv), 0);
	else
		comps.inside = false;
	comps.over_point = add_tuples(comps.point,
			scale_tuple(comps.normalv, EPSILON));
	return (comps);
}

t_tuple	checker_board(t_tuple p)
{
	if (equal(fmod(floor(p.x) + floor(p.y) + floor(p.z), 2), 0))
		return (color(0, 0, 0));
	return (color(1, 1, 1));
}

t_tuple	shade_hit(t_world w, t_comps comps)
{
	t_lighting	l;
	t_light_	*lights;
	t_tuple		final_color;

	(1) && (lights = w.lights_list, l.am_eff_col = color(0, 0, 0), 0);
	if (comps.object.form == SPHERE)
		l.m = ((t_sphere *)comps.object.object)->material;
	else if (comps.object.form == PLANE)
		l.m = ((t_plane *)comps.object.object)->material;
	else if (comps.object.form == CYLINDER || comps.object.form == CONE)
		l.m = ((t_cylinder *)comps.object.object)->material;
	(1) && (l.eyev = comps.eyev, l.normalv = comps.normalv,
		l.point = comps.over_point, final_color = color(0, 0, 0), 0);
	if (comps.object.form == PLANE && CHECKER != 0)
		l.m.color = checker_board(l.point);
	while (lights)
	{
		(1) && (l.in_shadow = is_shadowed(&w, lights, l.point),
		l.light.intensity = col_x_sc(lights->color, lights->intensity),
		l.light.position = lights->pos, 0);
		(!lights->next) && (l.am_eff_col = w.ambient_color, 0);
		final_color = add_colors(final_color, lighting(l));
		lights = lights->next;
	}
	return (final_color);
}

t_tuple	color_at(t_world *w, t_ray r)
{
	t_xs_list	*xs_list;
	t_xs_list	*xs_hit;
	t_comps		comps;
	t_tuple		final_color;
	t_xs_list	*tmp;

	final_color = color(0, 0, 0);
	xs_list = intersect_world(w, r);
	xs_hit = hit(xs_list);
	if (xs_hit)
	{
		comps = prepare_computations(xs_hit, r);
		final_color = shade_hit(*w, comps);
	}
	else
		final_color = color(0, 0, 0);
	while (xs_list)
	{
		tmp = xs_list->next;
		free(xs_list);
		xs_list = tmp;
	}
	return (final_color);
}
