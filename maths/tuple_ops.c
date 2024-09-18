/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:47:49 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/18 13:06:07 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data_structs/data_funcs.h"

bool	equal_tuple(t_tuple a, t_tuple b)
{
	if (a.x != b.x || a.y != b.y || a.z != b.z || a.w != b.w )
		return (false);
	return (true);
}

t_tuple add_tuples(t_tuple a, t_tuple b)
{
	return (return_tuple(
		a.x + b.x,
		a.y + b.y,
		a.z + b.z,
		a.w + b.w
	));
}