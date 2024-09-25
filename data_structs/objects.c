/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:01:21 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/25 13:54:09 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"
#include <stdlib.h>
#include <math.h>

t_sphere	sphere(int id)
{
	t_sphere	s;
	s.id = id;
	s.center = point(0, 0, 0);
	s.radius = 1;
	s.transform = identity();
	return (s);
}
