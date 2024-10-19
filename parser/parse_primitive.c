/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_primitive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:50:07 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/19 11:27:50 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data_structs/data_structs.h"
#include "../data_structs/data_funcs.h"
#include <stdlib.h>

void	init_parse_plane(t_plane **pl, t_object_ **object, t_world *world)
{
	*pl = malloc(sizeof(t_plane));
	*object = malloc(sizeof(t_object_));
	**pl = plane();
	(*pl)->material.ambient = world->ambient_intensity;
}

void	parse_plane(const char *line, t_world **world,
t_object_ **objects_list)
{
	t_plane		*pl;
	t_object_	*object;

	init_parse_plane(&pl, &object, *world);
	validate_line((char *)line);
	reach_for(&line, ' ', 0);
	pl->pip.x = atodbl(line);
	reach_for(&line, ',', 1);
	pl->pip.y = atodbl(line);
	reach_for(&line, ',', 1);
	pl->pip.z = atodbl(line);
	reach_for(&line, ' ', 0);
	pl->normal.x = atodbl(line);
	reach_for(&line, ',', 1);
	pl->normal.y = atodbl(line);
	reach_for(&line, ',', 1);
	pl->normal.z = atodbl(line);
	reach_for(&line, ' ', 0);
	pl->transform = matrix_multiply(translation(pl->pip.x, pl->pip.y, pl->pip.z), rotation_x(radians(-45)), 4);
	// pl->transform = );
	pl->pip = point(0, 0, 0);
	parse_colors(&pl->material.color, line);
	object->form = PLANE;
	object->object = pl;
	object->next = NULL;
	append_objects(objects_list, object);
}



/*

0 1 0 \\ for ray-plane intersection
1 0 0 \\ from file

rotation_x z

rotation_y y

rotation_z x





*/