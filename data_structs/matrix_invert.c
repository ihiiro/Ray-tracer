/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_invert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:47:16 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/19 13:46:19 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"
#include <stdlib.h>
#include <math.h>

double	matrix_cofactor(t_matrix *matrix, int row, int column, size_t size)
{
	double	minor;

	if (size == 3)
		minor = matrix_3_by_3_minor(matrix, row, column);
	else
		minor = matrix_4_by_4_minor(matrix, row, column);
	return (minor * pow(-1, row + column));
}

double	matrix_determinant(t_matrix *m, size_t size)
{
	double	determinant;

	if (size == 2)
		return (determinant_2x2_matrix(m));
	else if (size == 3)
		determinant = m[0].x * matrix_cofactor(m, 0, 0, size)
			+ m[0].y * matrix_cofactor(m, 0, 1, size)
			+ m[0].z * matrix_cofactor(m, 0, 2, size)
			+ m[0].w * matrix_cofactor(m, 0, 3, size);
	else
		determinant = m[0].x * matrix_cofactor(m, 0, 0, size)
			+ m[0].y * matrix_cofactor(m, 0, 1, size)
			+ m[0].z * matrix_cofactor(m, 0, 2, size)
			+ m[0].w * matrix_cofactor(m, 0, 3, size);
	return (determinant);
}

t_matrix	*invert_matrix(t_matrix *m0, size_t size)
{
	size_t		i;
	double		det;
	t_matrix	*mt;
	t_matrix	*mt_tmp;

	(1) && (i = -1, det = matrix_determinant(m0, size), 0);
	if (equal(det, 0))
		return (m0);
	mt = malloc(sizeof(t_tuple) * size);
	(!mt) && (exitf("malloc\n"), 0);
	while (++i < size)
	{
		mt[i].x = matrix_cofactor(m0, i, 0, size);
		mt[i].y = matrix_cofactor(m0, i, 1, size);
		mt[i].z = matrix_cofactor(m0, i, 2, size);
		mt[i].w = matrix_cofactor(m0, i, 3, size);
	}
	(1) && (mt_tmp = mt, i = -1,
		mt = matrix_transpose(mt, size), free(mt_tmp), 0);
	while (++i < size)
	{
		(1) && (mt[i].x = mt[i].x / det, mt[i].y = mt[i].y / det,
			mt[i].z = mt[i].z / det, mt[i].w = mt[i].w / det);
	}
	return (mt);
}
