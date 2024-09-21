/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_invert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:47:16 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/21 13:32:27 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"
#include <stdlib.h>

double	matrix_3x3_cofactor(t_matrix *matrix, int row, int column)
{
	double minor;

	minor = matrix_3_by_3_minor(matrix, row, column);
	if (row + column % 2 != 0)
		return (-minor);
	return (minor);
}

double	matrix_4x4_cofactor(t_matrix *matrix, int row, int column)
{
	double minor;

	minor = matrix_4_by_4_minor(matrix, row, column);
	if (row + column % 2 != 0)
		return (-minor);
	return (minor);
}

double	matrix_determinant(t_matrix *m, size_t size)
{
	double	determinant;

	if (size == 2)
		return (determinant_2x2_matrix(m));
	else if (size == 3)
		determinant = m[0].x * matrix_3x3_cofactor(m, 0, 0) + m[0].y * matrix_3x3_cofactor(m, 0, 1)
		+ m[0].z * matrix_3x3_cofactor(m, 0, 2) + m[0].w * matrix_3x3_cofactor(m, 0, 3);
	else
		determinant = m[0].x * matrix_4x4_cofactor(m, 0, 0) + m[0].y * matrix_4x4_cofactor(m, 0, 1)
		+ m[0].z * matrix_4x4_cofactor(m, 0, 2) + m[0].w * matrix_4x4_cofactor(m, 0, 3);
	return (determinant);
}
