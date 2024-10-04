/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 00:38:01 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/04 18:45:47 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"

t_comps 	prepare_computations(t_xs_list *intersection, t_ray ray)
{
	t_comps	comps;

	comps.t = intersection->t;
	comps.object.object = intersection->object.object;
	comps.object.form = intersection->object.form;
	comps.point = position(ray, comps.t);
	
	comps.eyev  = negate_tuple(ray.direction);
	
	if (intersection->object.form == SPHERE)
		comps.normalv = normal_at(*(t_sphere *)comps.object.object, comps.point);
	
	if (vec_dot(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = true;
		comps.normalv = negate_tuple(comps.normalv);
		
	}
	else
		comps.inside = false;
	return (comps);
}

t_tuple	shade_hit(t_world w, t_comps comps)
{
	t_lighting 	l;
	t_sphere	*sp;

	l.ambient_effective_color = w.ambient_color;
	if (comps.object.form == SPHERE)
	{
		sp = (t_sphere *)comps.object.object;
		l.m = sp->material;
	}
	l.light.intensity = multiply_color_by_scalar(w.lights_list->color, w.lights_list->intensity);
	l.light.position = w.lights_list->pos;
	l.point = comps.point;
	l.eyev = comps.eyev;
	l.normalv = comps.normalv;
	return (lighting(l));
}

#include <libc.h>

t_tuple	color_at(t_world *w, t_ray r)
{
	t_xs_list	*xs_list;
	t_xs_list	*xs_hit;
	t_comps		comps;

	xs_list = intersect_world(w, r);
	if (!xs_list)
		return (color(0, 0, 0));
	xs_hit = hit(xs_list);
	if (!xs_hit)
		return (color(0, 0, 0));
	comps = prepare_computations(xs_hit, r);
	return (shade_hit(*w, comps));
}
