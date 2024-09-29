/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:36:54 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/29 20:11:16 by yel-yaqi         ###   ########.fr       */
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
	if (color.x > 255 || color.x < 0
		|| color.y > 255 || color.y < 0
		|| color.z > 255 || color.z < 0)
		return (false);
	return (true);
}

bool	normalized_vector(t_tuple v)
{
	v.w = VECTOR;
	if (!equal_tuple(vector(1, 0, 0), v)
		&& !equal_tuple(vector(0, 1, 0), v)
		&& !equal_tuple(vector(0, 0, 1), v)
		&& !equal_tuple(vector(0, 0, 0), v))
		return (false);
	return (true);
}

void	clean_w(t_world *world)
{
	t_light_	*iter;

	world->ambient_color.w = POINT;
	world->camera.pos.w = POINT;
	world->camera.vec.w = VECTOR;
	iter = world->lights_list;
	while (iter)
	{
		iter->color.w = POINT;
		iter->pos.w = POINT;
		iter = iter->next;
	}
}
