/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:54:52 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/20 16:55:16 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"
#include <stdlib.h>
#include <stdbool.h>

t_matrix *return_4_by_4_matrix(t_tuple a, t_tuple b, t_tuple c, t_tuple d)
{
	t_matrix *matrix;

	matrix = malloc(sizeof(t_tuple) * 4);
	matrix[0] = a;
	matrix[1] = b;
	matrix[2] = c;
	matrix[3] = d;
	return (matrix);
}

t_matrix *return_2_by_2_matrix(t_tuple a, t_tuple b)
{
	t_matrix *matrix;

	matrix = malloc(sizeof(t_tuple) * 2);
	matrix[0] = a;
	matrix[1] = b;
	return (matrix);
}

t_matrix *return_3_by_3_matrix(t_tuple a, t_tuple b, t_tuple c)
{
	t_matrix *matrix;

	matrix = malloc(sizeof(t_tuple) * 3);
	matrix[0] = a;
	matrix[1] = b;
	matrix[2] = c;
	return (matrix);
}

bool	equal_matrices(t_matrix *a, t_matrix *b, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (equal_tuple(a[i], b[i]))
			i++;
		else
			return (false);
	}
	return (true);
}

t_matrix	*matrix_multiply(t_matrix *A, t_matrix *B, size_t size)
{
	t_matrix	*M;
	size_t	i;

	i = 0;
	if (size == 2)
		M = return_2_by_2_matrix(return_tuple(0, 0, 0, 0), return_tuple(0, 0, 0, 0));
	else if (size == 3)
	{
		M = return_3_by_3_matrix(return_tuple(0, 0, 0, 0), return_tuple(0, 0, 0, 0),
			return_tuple(0, 0, 0, 0));
	}
	else if (size == 4)
	{
		M = return_4_by_4_matrix(return_tuple(0, 0, 0, 0), return_tuple(0, 0, 0, 0),
			return_tuple(0, 0, 0, 0), return_tuple(0, 0, 0, 0));
	}
	while (i < size)
	{
		M[i].x = A[i].x * B[0].x + A[i].y * B[1].x + A[i].z * B[2].x + A[i].w * B[3].x;
		M[i].y = A[i].x * B[0].y + A[i].y * B[1].y + A[i].z * B[2].y + A[i].w * B[3].y;
		M[i].z = A[i].x * B[0].z + A[i].y * B[1].z + A[i].z * B[2].z + A[i].w * B[3].z;
		M[i].w = A[i].x * B[0].w + A[i].y * B[1].w + A[i].z * B[2].w + A[i].w * B[3].w;
		i++;
	}
	return (M);
}