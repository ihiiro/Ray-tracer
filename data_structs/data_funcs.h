/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_funcs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:25:19 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/18 13:06:48 by yel-yaqi         ###   ########.fr       */
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

t_tuple add_tuples(t_tuple a, t_tuple b);