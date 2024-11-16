/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_tuple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:54:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/16 15:14:47 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"

t_tuple	multiply_matrix_by_tuple(t_matrix *m, t_tuple t)
{
	t_tuple	result_tuple;

	result_tuple.x = vec_dot(m[0], t);
	result_tuple.y = vec_dot(m[1], t);
	result_tuple.z = vec_dot(m[2], t);
	result_tuple.w = vec_dot(m[3], t);
	return (result_tuple);
}

t_matrix	*rotation_axis_angle(t_tuple axis, double angle)
{
	t_rot	rot;

	rot.magnitude = vector_magnitude(axis);
	rot.normalized_axis = get_tuple(axis.x / rot.magnitude, axis.y
			/ rot.magnitude, axis.z / rot.magnitude, axis.w);
	rot.x = rot.normalized_axis.x;
	rot.y = rot.normalized_axis.y;
	rot.z = rot.normalized_axis.z;
	rot.cos_theta = cos(angle);
	rot.sin_theta = sin(angle);
	rot.one_minus_cos = 1 - rot.cos_theta;
	rot.row1 = get_tuple(rot.cos_theta + rot.x * rot.x * rot.one_minus_cos,
			rot.x * rot.y * rot.one_minus_cos - rot.z * rot.sin_theta,
			rot.x * rot.z * rot.one_minus_cos + rot.y * rot.sin_theta, 0);
	rot.row2 = get_tuple(rot.y * rot.x * rot.one_minus_cos + rot.z
			* rot.sin_theta, rot.cos_theta + rot.y * rot.y * rot.one_minus_cos,
			rot.y * rot.z * rot.one_minus_cos - rot.x * rot.sin_theta, 0);
	rot.row3 = get_tuple(rot.z * rot.x * rot.one_minus_cos - rot.y
			* rot.sin_theta, rot.z * rot.y * rot.one_minus_cos + rot.x
			* rot.sin_theta, rot.cos_theta + rot.z * rot.z * rot.one_minus_cos,
			0);
	rot.row4 = get_tuple(0, 0, 0, 1);
	return (get_4_by_4_matrix(rot.row1, rot.row2, rot.row3, rot.row4));
}

t_matrix	*align_vector_to_axis(t_tuple vec, t_tuple target_axis)
{
	t_tuple	axis;
	double	angle;

	angle = acos(vec_dot(target_axis, vec));
	axis = vec_cross(target_axis, vec);
	if (vector_magnitude(axis) == 0)
		return (identity());
	return (rotation_axis_angle(axis, angle));
}
