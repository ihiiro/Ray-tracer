/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:54:52 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/20 12:15:21 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data_structs/data_structs.h"
#include <stdlib.h>

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
