/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_tuple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:54:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/28 18:08:16 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"

t_tuple multiply_matrix_by_tuple(t_matrix *m, t_tuple t)
{
	t_tuple result_tuple;

	result_tuple.x = vec_dot(m[0], t);
	result_tuple.y = vec_dot(m[1], t);
	result_tuple.z = vec_dot(m[2], t);
	result_tuple.w = vec_dot(m[3], t);
	return (result_tuple);
}
