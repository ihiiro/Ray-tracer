/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_vectors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:46:55 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/15 16:13:08 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_funcs.h"
#include <libc.h>

double	point_or_vector(t_tuple t)
{
	return (t.w);
}

t_tuple	get_tuple(double x, double y, double z, double w)
{
	t_tuple	t;

	t.x = x;
	t.y = y;
	t.z = z;
	t.w = w;
	return (t);
}

t_tuple	point(double x, double y, double z)
{
	return (get_tuple(x, y, z, POINT));
}

t_tuple	vector(double x, double y, double z)
{
	return (get_tuple(x, y, z, VECTOR));
}
