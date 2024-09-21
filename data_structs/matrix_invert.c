/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_invert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:47:16 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/21 13:16:21 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"
#include <stdlib.h>

double	matrix_determinant(t_matrix *m)
{
	double	determinant;

	determinant = m[0].x * matrix_cofactor(m, 0, 0) + m[0].y * matrix_cofactor(m, 0, 1)
		+ m[0].z * matrix_cofactor(m, 0, 2) + m[0].w * matrix_cofactor(m, 0, 3);
	return (determinant);
}

double	matrix_4x4_determinant(t_matrix *m)
{
	double	determinant;

	determinant = m[0].x * matrix_cofactor(m, 0, 0) + m[0].y * matrix_cofactor(m, 0, 1)
		+ m[0].z * matrix_cofactor(m, 0, 2) + m[0].w * matrix_cofactor(m, 0, 3);
	return (determinant);
}
