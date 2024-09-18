/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:00:02 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/18 18:12:27 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data_structs/data_funcs.h"
#include <math.h>

double	vector_magnitude(t_tuple t)
{
	return (sqrt(pow(t.x, 2) + pow(t.y, 2) + pow(t.z, 2) + pow(t.w, 2)));
}

t_tuple	normalize_vec(t_tuple t)
{
	double	magnitude;

	magnitude = vector_magnitude(t);
	return (scale_tuple(t, 1 / magnitude));
}

double	vec_dot(t_tuple a, t_tuple b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}

t_tuple	vec_cross(t_tuple a, t_tuple b)
{
	return (vector(a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x));
}

double	angle_between_2vectors(t_tuple a, t_tuple b)
{
	double	angle;

	angle = acos(vec_dot(a, b)/(vector_magnitude(a) * vector_magnitude(b)));
	return (angle * 180 / M_PI);
}
