/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:45:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/15 16:17:18 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"
#include <stdlib.h>
#include <math.h>

t_matrix	*translation(double x, double y, double z)
{
	return (get_4_by_4_matrix(
			get_tuple(1, 0, 0, x),
			get_tuple(0, 1, 0, y),
			get_tuple(0, 0, 1, z),
			get_tuple(0, 0, 0, 1)));
}

t_matrix	*scaling(double x, double y, double z)
{
	return (get_4_by_4_matrix(
			get_tuple(x, 0, 0, 0),
			get_tuple(0, y, 0, 0),
			get_tuple(0, 0, z, 0),
			get_tuple(0, 0, 0, 1)));
}

t_matrix	*rotation_x(double r)
{
	return (get_4_by_4_matrix(
			get_tuple(1, 0, 0, 0),
			get_tuple(0, cos(r), -sin(r), 0),
			get_tuple(0, sin(r), cos(r), 0),
			get_tuple(0, 0, 0, 1)));
}

t_matrix	*rotation_y(double r)
{
	return (get_4_by_4_matrix(
			get_tuple(cos(r), 0, sin(r), 0),
			get_tuple(0, 1, 0, 0),
			get_tuple(-sin(r), 0, cos(r), 0),
			get_tuple(0, 0, 0, 1)));
}

t_matrix	*rotation_z(double r)
{
	return (get_4_by_4_matrix(
			get_tuple(cos(r), -sin(r), 0, 0),
			get_tuple(sin(r), cos(r), 0, 0),
			get_tuple(0, 0, 1, 0),
			get_tuple(0, 0, 0, 1)));
}
