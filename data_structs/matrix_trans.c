/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_trans.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:18:50 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/20 18:44:08 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"
#include <stdlib.h>

t_matrix *matrix_transpose(t_matrix *m, size_t size)
{
	t_matrix	*transposed_matrix;

	transposed_matrix = malloc(sizeof(t_matrix) * size);
	if (size == 2)
	{
		transposed_matrix[0] = return_tuple(m[0].x, m[1].x, 0, 0);
		transposed_matrix[1] = return_tuple(m[1].x, m[0].y, 0, 0);
	}
	else if (size == 3)
	{
		transposed_matrix[0] = return_tuple(m[0].x, m[1].x, m[2].x, 0);
		transposed_matrix[1] = return_tuple(m[0].y, m[1].y, m[2].y, 0);
		transposed_matrix[2] = return_tuple(m[0].z, m[1].z, m[2].z, 0);
	}
	else if (size == 4)
	{
		transposed_matrix[0] = return_tuple(m[0].x, m[1].x, m[2].x, m[3].x);
		transposed_matrix[1] = return_tuple(m[0].y, m[1].y, m[2].y, m[3].y);
		transposed_matrix[2] = return_tuple(m[0].z, m[1].z, m[2].z, m[3].z);
		transposed_matrix[3] = return_tuple(m[0].w, m[1].w, m[2].w, m[3].w);
	}
	return (transposed_matrix);
}
double	determinant_2x2_matrix(t_matrix *matrix)
{
	double	determinant;

	determinant = (matrix[0].x * matrix[1].y) - (matrix[0].y * matrix[1].x);
	return (determinant);  
}