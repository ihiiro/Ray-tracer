/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:30:17 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/27 18:52:41 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

/////////////////////////////////////////////////////////////////////////////////////////////////////////

t_tuple preset_sinewave_groove(t_tuple normal)
{
    double	wave_amplitude;
    double	frequency;
    double	wave;

	wave_amplitude = .6;
	frequency = 20;
	wave = sin((normal.x + normal.y + normal.z) * frequency) * wave_amplitude;
    normal.x -= wave;
    normal.y -= wave;
    normal.z -= wave;
    return (normal);
}

t_tuple preset_sinewave(t_tuple normal)
{
    double	wave_amplitude;
    double	frequency;
    double	wave;

	wave_amplitude = .6;
	frequency = 40;
	wave = sin((normal.x + normal.y + normal.z) * frequency) * wave_amplitude;
    normal.x += wave;
    normal.y += wave;
    normal.z += wave;
    return (normal);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

t_tuple	normal_at(t_sphere s, t_tuple world_point)
{
	t_tuple	object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;

	object_point = multiply_matrix_by_tuple(invert_matrix(s.transform, 4), world_point);
	object_normal = vector(object_point.x, object_point.y, object_point.z);
	object_normal = preset_sinewave_groove(object_normal); // sine wave preset
	world_normal = multiply_matrix_by_tuple(matrix_transpose(invert_matrix(s.transform, 4), 4), object_normal);
	world_normal.w = VECTOR;
	return (normalize_vec(world_normal));
}
