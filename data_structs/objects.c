/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:01:21 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/23 15:47:08 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"
#include <stdlib.h>
#include <math.h>

void	set_transform(t_sphere *s, t_matrix *m)
{
	s->transform = m;
}

t_sphere	sphere(int id)
{
	t_sphere	s;
	s.center = point(0, 0, 0);
	s.radius = 1;
	s.transform = identity();
	s.material = material();
	return (s);
}

t_plane	plane(void)
{
	t_plane	p;

	p.material = material();
	p.transform = identity();
	p.pip = point(0, 0, 0);
	p.normal = vector(0, 1, 0);
	return (p);
}

t_cylinder	cylinder(void)
{
	t_cylinder	c;

	c.center = point(0, 0, 0);
	c.radius = 1;
	c.height = 1;
	c.maximum = maximum_y(c.center, c.height);
	c.minimum = minimum_y(c.center, c.height);
	c.vec = point(0, 1, 0);
	c.transform = identity();
	c.material = material();
	return (c);
}
