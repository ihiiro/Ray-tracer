/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:36:54 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/15 18:22:00 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data_structs/data_structs.h"
#include "../data_structs/data_funcs.h"
#include "../maths/maths.h"

#include <libc.h>

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

// bool	normalized_vector(t_tuple v)
// {
// 	return (equal(vector_magnitude(v), 1));
// }

void	clean_w(t_world *world)
{
	t_light_	*iter;
	t_object_	*objects;

	(1) && (world->ambient_color.w = VECTOR, world->camera.pos.w
	= POINT, world->camera.vec.w = VECTOR, iter = world->lights_list);
	while (iter)
	{
		iter->color.w = VECTOR;
		iter->pos.w = POINT;
		iter = iter->next;
	}
	objects = world->objects_list;
	while (objects)
	{
		if (objects->form == CYLINDER)
			((t_cylinder *)objects->object)->material.ambient
				= world->ambient_intensity;
		else if (objects->form == SPHERE)
			((t_sphere *)objects->object)->material.ambient
				= world->ambient_intensity;
		else if (objects->form == PLANE)
			((t_plane *)objects->object)->material.ambient
				= world->ambient_intensity;
		objects = objects->next;
	}
}
