/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:52:35 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/22 20:01:27 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"
#include <stdlib.h>
#include <math.h>

t_ray	return_ray(t_tuple org, t_tuple dir)
{
	t_ray ray;

	ray.origin = org;
	ray.direction = dir;
	return (ray);
}
t_tuple position(t_ray ray, double t)
{
	return (add_tuples(ray.origin, scale_tuple(ray.direction, t)));
}
