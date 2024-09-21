/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:45:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/21 21:36:15 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"
#include <stdlib.h>
#include <math.h>


t_matrix	*identity()
{
	return (translation(0, 0, 0));
}
t_matrix	*translation(double x, double y, double z)
{
	return (return_4_by_4_matrix(
		return_tuple(1, 0, 0, x),
		return_tuple(0, 1, 0, y),
		return_tuple(0, 0, 1, z),
		return_tuple(0, 0, 0, 1)));
}
t_matrix	*scaling(double x, double y, double z)
{
	return (return_4_by_4_matrix(
		return_tuple(x, 0, 0, 0),
		return_tuple(0, y, 0, 0),
		return_tuple(0, 0, z, 0),
		return_tuple(0, 0, 0, 1)));
}
t_matrix	*rotation_x(double r)
{
	return (return_4_by_4_matrix(
		return_tuple(1, 0, 0, 0),
		return_tuple(0, cos(r), -sin(r), 0),
		return_tuple(0, sin(r), cos(r), 0),
		return_tuple(0, 0, 0, 1)));
}

t_matrix	*rotation_y(double r)
{
	return (return_4_by_4_matrix(
		return_tuple(cos(r), 0, sin(r), 0),
		return_tuple(0, 1, 0, 0),
		return_tuple(-sin(r), 0, cos(r), 0),
		return_tuple(0, 0, 0, 1)));
}
t_matrix	*rotation_z(double r)
{
	return (return_4_by_4_matrix(
		return_tuple(cos(r), -sin(r), 0, 0),
		return_tuple(sin(r), cos(r), 0, 0),
		return_tuple(0, 0, 1, 0),
		return_tuple(0, 0, 0, 1)));
}