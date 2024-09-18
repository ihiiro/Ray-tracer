/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_equality.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:37:07 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/18 12:43:27 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"
#include <math.h>

bool equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	return (false);
}