/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:18:50 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/21 13:03:37 by yel-yaqi         ###   ########.fr       */
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
t_matrix	*submatrix(t_matrix *matrix, int row, int column, int size)
{
	t_matrix	*m;
	size_t		i;
	size_t		j;

	m = malloc(sizeof(t_matrix) * (size -1));
	(!m || size == 2) && (exit(EXIT_FAILURE), 0);
	(i = -1, j = -1);
	while(++i < size)
	{
		if (i != row)
			m[++j] = return_tuple(matrix[i].x, matrix[i].y,
				matrix[i].z, matrix[i].w);
	}
	(i = -1);
	while(++i < size - 1)
	{
		(column == 0) && (m[i] = return_tuple(m[i].y, m[i].z, m[i].w, 0), 0);
		if (column == 1)
			m[i] = return_tuple(m[i].x, m[i].z, m[i].w, 0);
		else if (column == 2)
			m[i] = return_tuple(m[i].x, m[i].y, m[i].w, 0);
		else if (column == 3)
			m[i] = return_tuple(m[i].x, m[i].y, m[i].z, 0);
	}
	return (m);
}

double	matrix_3_by_3_minor(t_matrix *matrix, int row, int column)
{
	t_matrix *submatrix_2_by_2;

	submatrix_2_by_2 = submatrix(matrix, row, column, 3);
	return (determinant_2x2_matrix(submatrix_2_by_2));
}

double	matrix_cofactor(t_matrix *matrix, int row, int column)
{
	double minor;

	minor = matrix_3_by_3_minor(matrix, row, column);
	if (row + column % 2 != 0)
		return (-minor);
	return (minor);
}
