/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:45:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/21 18:51:29 by yel-yaqi         ###   ########.fr       */
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
