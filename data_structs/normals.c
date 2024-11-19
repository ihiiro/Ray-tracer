/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:30:17 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/19 13:20:27 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

t_tuple	preset_sinewave_groove(t_tuple normal)
{
	double	wave_amplitude;
	double	frequency;
	double	wave;

	wave_amplitude = AMP;
	frequency = FREQ;
	wave = sin((normal.x + normal.y + normal.z) * frequency) * wave_amplitude;
	normal.x -= wave;
	normal.y -= wave;
	normal.z -= wave;
	return (normal);
}

t_tuple	normal_at(t_sphere s, t_tuple world_point)
{
	t_tuple		object_point;
	t_tuple		object_normal;
	t_tuple		world_normal;
	t_matrix	*inversion;
	t_matrix	*inverse_transpose;

	inversion = invert_matrix(s.transform, 4);
	inverse_transpose = matrix_transpose(inversion, 4);
	object_point = multiply_matrix_by_tuple(inversion, world_point);
	free(inversion);
	object_normal = vector(object_point.x, object_point.y, object_point.z);
	object_normal = preset_sinewave_groove(object_normal);
	world_normal = multiply_matrix_by_tuple(inverse_transpose, object_normal);
	free(inverse_transpose);
	world_normal.w = VECTOR;
	return (normalize_vec(world_normal));
}

void	set_trans(int shape, t_cylinder *cy, t_matrix *rotation_matrix)
{
	t_matrix	*scale;
	t_matrix	*translate;
	t_matrix	*rot_scale;

	translate = translation(cy->center.x, cy->center.y, cy->center.z);
	scale = scaling(2 * cy->radius / cy->height, 1,
			2 * cy->radius / cy->height);
	rot_scale = matrix_multiply(rotation_matrix, scale, 4);
	(shape == CONE) && (cy->transform = matrix_multiply(translate,
	rot_scale, 4));
	free(scale);
	free(rot_scale);
	scale = scaling(cy->radius, 1, cy->radius);
	rot_scale = matrix_multiply(rotation_matrix, scale, 4);
	(shape == CYLINDER) && (cy->transform = matrix_multiply(translate,
	rot_scale, 4), 0);
	free(scale);
	free(rot_scale);
	free(translate);
	free(rotation_matrix);
}
