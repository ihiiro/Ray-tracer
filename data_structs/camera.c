/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:06:28 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/03 19:56:05 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"

#include <libc.h>

t_matrix	*view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple		forward;
	t_tuple		upn;
	t_tuple		left;
	t_tuple		true_up;
	t_matrix	*orientation;

	forward = normalize_vec(sub_tuples(to, from));
	upn = normalize_vec(up);
	left = vec_cross(forward, upn);
	true_up = vec_cross(left, forward);
	orientation = return_4_by_4_matrix(
	return_tuple(left.x, left.y, left.z, 0),
	return_tuple(true_up.x, true_up.y, true_up.z, 0),
	return_tuple(-forward.x, -forward.y, -forward.z, 0),
	return_tuple(0, 0, 0, 1));
	return (matrix_multiply(orientation, translation(-from.x, -from.y,
	-from.z), 4));
}
