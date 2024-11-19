/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:48:27 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/19 13:20:46 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_funcs.h"

t_tuple	color(double red, double green, double blue)
{
	return (vector(red, green, blue));
}

t_tuple	add_colors(t_tuple a, t_tuple b)
{
	return (add_tuples(a, b));
}

t_tuple	sub_colors(t_tuple a, t_tuple b)
{
	return (sub_tuples(a, b));
}

t_tuple	col_x_sc(t_tuple t, double scalar)
{
	return (scale_tuple(t, scalar));
}

t_tuple	multiply_colors(t_tuple a, t_tuple b)
{
	return (get_tuple(a.x * b.x,
			a.y * b.y,
			a.z * b.z,
			a.w * b.w));
}
