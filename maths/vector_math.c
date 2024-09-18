/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:00:02 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/18 15:44:08 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data_structs/data_funcs.h"
#include <math.h>

double	vector_magnitude(t_tuple t)
{
	return (sqrt(pow(t.x, 2) + pow(t.y, 2) + pow(t.z, 2) + pow(t.w, 2)));
}
t_tuple	normalize_vec(t_tuple t)
{
	double	magnitude;

	magnitude = vector_magnitude(t);
	return (scale_tuple(t, 1/magnitude));
}
