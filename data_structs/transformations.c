/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:45:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/21 19:14:56 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"
#include <stdlib.h>

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