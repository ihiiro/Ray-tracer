/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_equality.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:37:07 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/15 16:17:54 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"
#include <math.h>

bool	equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	return (false);
}
