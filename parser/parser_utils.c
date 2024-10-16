/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:36:54 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/08 18:26:13 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data_structs/data_structs.h"
#include "../data_structs/data_funcs.h"

void	reach_for(const char **line, char end, int skip)
{
	while (**line && **line != end)
		(*line)++;
	if (skip)
		(*line)++;
}

bool	valid_color(t_tuple color)
{
	if (color.x > 1 || color.x < 0
		|| color.y > 1 || color.y < 0
		|| color.z > 1 || color.z < 0)
		return (false);
	return (true);
}

bool	normalized_vector(t_tuple v) // maybe wrong
{
	v.w = VECTOR;
	if (!equal_tuple(vector(1, 0, 0), v)
		&& !equal_tuple(vector(0, 1, 0), v)
		&& !equal_tuple(vector(0, 0, 1), v)
		&& !equal_tuple(vector(0, 0, 0), v)
		&& !equal_tuple(vector(-1, 0, 0), v)
		&& !equal_tuple(vector(0, -1, 0), v)
		&& !equal_tuple(vector(0, 0, -1), v))
		return (false);
	return (true);
}

void	clean_w(t_world *world)
{
	t_light_	*iter;

	world->ambient_color.w = VECTOR;
	world->camera.pos.w = POINT;
	world->camera.vec.w = VECTOR;
	iter = world->lights_list;
	while (iter)
	{
		iter->color.w = VECTOR;
		iter->pos.w = POINT;
		iter = iter->next;
	}
}
