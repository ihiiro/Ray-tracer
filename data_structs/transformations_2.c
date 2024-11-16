/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:37:17 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/15 16:17:24 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"
#include <stdlib.h>
#include <math.h>

t_matrix	*identity(void)
{
	return (translation(0, 0, 0));
}

t_shear	fill_shear(t_tuple t1, t_tuple t2)
{
	t_shear	shear;

	shear.xy = t1.x;
	shear.xz = t1.y;
	shear.yx = t1.z;
	shear.yz = t2.x;
	shear.zx = t2.y;
	shear.zy = t2.z;
	return (shear);
}

t_matrix	*shearing(t_shear shear)
{
	return (get_4_by_4_matrix(
			get_tuple(1, shear.xy, shear.xz, 0),
			get_tuple(shear.yx, 1, shear.yz, 0),
			get_tuple(shear.zx, shear.zy, 1, 0),
			get_tuple(0, 0, 0, 1)));
}
