/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_vectors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:46:55 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/18 12:05:20 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_funcs.h"
#include <libc.h>

double	point_or_vector(t_tuple t)
{
	return (t.w);
}

t_tuple	return_tuple(double x, double y, double z, double w)
{
	t_tuple t;

	if (w != POINT && w != VECTOR)
	{
		printf("return_tuple(): w not POINT and w not VECTOR\n");
		exit(EXIT_FAILURE);
	}
	t.x = x;
	t.y = y;
	t.z = z;
	t.w = w;
	return (t);
}

t_tuple	point(double x, double y, double z)
{
	return (return_tuple(x, y, z, POINT));
}

t_tuple	vector(double x, double y, double z)
{
	return (return_tuple(x, y, z, VECTOR));
}
