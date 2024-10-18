/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_primitive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:50:07 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/18 13:41:52 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data_structs/data_structs.h"
#include "../data_structs/data_funcs.h"
#include <stdlib.h>

void	parse_plane(const char *line, t_world **world,
t_object_ **objects_list)
{
	t_plane		*pl;
	t_object_	*object;

	pl = malloc(sizeof(t_plane));
	object = malloc(sizeof(t_object_));
	*pl = plane();
	pl->material.ambient = (*world)->ambient_intensity;
	validate_line((char *)line);
	reach_for(&line, ' ', 0);
	pl->pip.x = atodbl(line);
	reach_for(&line, ',', 1);
	pl->pip.y = atodbl(line);
	reach_for(&line, ',', 1);
	pl->pip.z = atodbl(line);
	reach_for(&line, ' ', 1);

	while (*line == ' ')
		line++;
	reach_for(&line, ' ', 0);
	pl->normal.x = atodbl(line);
	reach_for(&line, ',', 1);
	pl->normal.y = atodbl(line);
	reach_for(&line, ',', 1);
	pl->normal.z = atodbl(line);
	reach_for(&line, ' ', 1);

	pl->transform = translation(pl->pip.x, pl->pip.y, pl->pip.z);
	pl->pip = point(0, 0, 0);
	parse_colors(&pl->material.color, line);
	object->form = PLANE;
	object->object = pl;
	object->next = NULL;
	append_objects(objects_list, object);
}
