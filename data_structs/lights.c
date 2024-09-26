/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:51:33 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/26 18:58:43 by yel-yaqi         ###   ########.fr       */
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

t_material	material()
{
	t_material	m;

	m.color = color(1, 1, 1);
	m.ambient = 0.1;
	m.diffuse = 0.9;
	m.specular = 0.9;
	m.shininess = 200.0;
	return (m);
}

#include <libc.h>

t_tuple lighting(t_lighting l)
{
	t_lighting_components	lc;

	
	lc.effective_color = multiply_colors(l.m.color, l.light.intensity);
	lc.lightv = normalize_vec(sub_tuples(l.light.position, l.point));
	lc.ambient = lc.effective_color.x * lc.effective_color.y * lc.effective_color.z * l.m.ambient;
	lc.light_dot_normalv = vec_dot(lc.lightv, l.normalv);
	if (lc.light_dot_normalv < 0)
	{
		lc.diffuse = 0;
		lc.specular = 0;
	}
	else
	{
		lc.diffuse = lc.effective_color.x * lc.effective_color.y * lc.effective_color.z * l.m.diffuse * lc.light_dot_normalv;
		lc.reflectv = reflect(negate_tuple(lc.lightv), l.normalv);
		lc.reflect_dot_eye = vec_dot(lc.reflectv, l.eyev);
		if (lc.reflect_dot_eye <= 0)
			lc.specular = 0;
		else
		{
			lc.specular_factor = pow(lc.reflect_dot_eye, l.m.shininess);
			lc.specular = l.light.intensity.x * l.light.intensity.y * l.light.intensity.z * l.m.specular * lc.specular_factor;
		}
	}
	return (color(lc.ambient + lc.diffuse + lc.specular,
				lc.ambient + lc.diffuse + lc.specular,
				lc.ambient + lc.diffuse + lc.specular
	));
	
}
