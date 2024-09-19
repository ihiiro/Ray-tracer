/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_funcs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:25:19 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/19 16:06:13 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "data_structs.h"
#include <stdbool.h>

t_tuple	return_tuple(double x, double y, double z, double w);
double	point_or_vector(t_tuple t);
t_tuple	point(double x, double y, double z);
t_tuple	vector(double x, double y, double z);
bool	equal_tuple(t_tuple a, t_tuple b);
bool	equal(double a, double b);


/* TUPLE ARITHMETIC */
t_tuple add_tuples(t_tuple a, t_tuple b);
t_tuple sub_tuples(t_tuple a, t_tuple b);
t_tuple	negate_tuple(t_tuple t);
t_tuple scale_tuple(t_tuple t, double scalar);
double	angle_between_2vectors(t_tuple a, t_tuple b);

/* COLORS */
t_tuple color(double red, double green, double blue);
t_tuple	add_colors(t_tuple a, t_tuple b);
t_tuple	sub_colors(t_tuple a, t_tuple b);
t_tuple	multiply_colors(t_tuple a, t_tuple b);
t_tuple	multiply_color_by_scalar(t_tuple t, double scalar);

/* CANVAS */
void        create_canvas(t_canvas *c);
t_canvas	*canvas(int width, int height);