/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:36:54 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/19 12:12:22 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data_structs/data_structs.h"
#include "../data_structs/data_funcs.h"
#include "../maths/maths.h"

void	reach_for(const char **line, char end, int skip)
{
	while (**line && **line != end)
		(*line)++;
	if (skip && **line)
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

bool	normalized_vector(t_tuple v)
{
	// v.w = VECTOR;
	// if (!equal_tuple(vector(1, 0, 0), v)
	// 	&& !equal_tuple(vector(0, 1, 0), v)
	// 	&& !equal_tuple(vector(0, 0, 1), v)
	// 	&& !equal_tuple(vector(0, 0, 0), v)
	// 	&& !equal_tuple(vector(-1, 0, 0), v)
	// 	&& !equal_tuple(vector(0, -1, 0), v)
	// 	&& !equal_tuple(vector(0, 0, -1), v))
	// 	return (false); // replace with calcing the actual magnitude (shoould be 1) and range in [-1,1]
	// return (true);
	return (equal(vector_magnitude(v), 1));
}

void	clean_w(t_world *world)
{
	t_light_	*iter;
	t_object_	*iter_obj;

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
	iter_obj = world->objects_list;
	while (iter_obj)
	{
		if (iter_obj->form == PLANE)
			((t_plane *)iter_obj->object)->normal.w = VECTOR;
		iter_obj = iter_obj->next;
	}
}
