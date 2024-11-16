/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_primitive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:50:07 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/16 15:43:20 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data_structs/data_structs.h"
#include "../data_structs/data_funcs.h"
#include "../maths/maths.h"
#include <stdlib.h>
#include <math.h>

void	init_parse_plane(t_plane **pl, t_object_ **object)
{
	*pl = malloc(sizeof(t_plane));
	*object = malloc(sizeof(t_object_));
	**pl = plane();
}

void	parse_pip(t_plane *pl, const char **line)
{
	pl->pip.x = atodbl(*line);
	reach_for(line, ',', 1);
	pl->pip.y = atodbl(*line);
	reach_for(line, ',', 1);
	pl->pip.z = atodbl(*line);
}

void	parse_plane(const char *line, t_object_ **objects_list)
{
	t_plane		*pl;
	t_object_	*object;

	init_parse_plane(&pl, &object);
	validate_line((char *)line);
	reach_for(&line, ' ', 0);
	parse_pip(pl, &line);
	reach_for(&line, ' ', 0);
	pl->normal.x = atodbl(line);
	reach_for(&line, ',', 1);
	pl->normal.y = atodbl(line);
	reach_for(&line, ',', 1);
	pl->normal.z = atodbl(line);
	pl->normal.w = VECTOR;
	pl->normal = normalize_vec(pl->normal);
	reach_for(&line, ' ', 0);
	pl->transform = translation(pl->pip.x, pl->pip.y, pl->pip.z);
	pl->pip = point(0, 0, 0);
	parse_colors(&pl->material.color, line);
	object->form = PLANE;
	object->object = pl;
	object->next = NULL;
	append_objects(objects_list, object);
}

void	parse_cylinder_center_and_vector(t_cylinder **cy,
const char **line, t_object_ **object)
{
	*cy = malloc(sizeof(t_cylinder));
	*object = malloc(sizeof(t_object_));
	**cy = cylinder();
	validate_line(*(char **)line);
	reach_for(line, ' ', 0);
	(*cy)->center.x = atodbl(*line);
	reach_for(line, ',', 1);
	(*cy)->center.y = atodbl(*line);
	reach_for(line, ',', 1);
	(*cy)->center.z = atodbl(*line);
	reach_for(line, ' ', 0);
	(*cy)->vec.x = atodbl(*line);
	reach_for(line, ',', 1);
	(*cy)->vec.y = atodbl(*line);
	reach_for(line, ',', 1);
	(*cy)->vec.z = atodbl(*line);
	reach_for(line, ' ', 0);
	(*cy)->vec.w = VECTOR;
	(*cy)->vec = normalize_vec((*cy)->vec);
}

void	parse_cylinder(const char *line, t_object_ **objects_list)
{
	t_cylinder	*cy;
	t_object_	*object;
	t_tuple		direction;
	t_matrix	*rotation_matrix;
	int			shape;

	(line[1] == 'o') && (shape = CONE);
	(line[1] != 'o') && (shape = CYLINDER);
	parse_cylinder_center_and_vector(&cy, &line, &object);
	while (*line == ' ')
		line++;
	(1) && (cy->radius = atodbl(line) / 2, reach_for(&line, ' ', 0), 0);
	while (*line == ' ')
		line++;
	(1) && (cy->height = atodbl(line), reach_for(&line, ' ', 0), 0);
	(cy->height <= 0 || cy->radius <= 0) && (exitf("cy:H or R <= 0\n"), 0);
	(1) && (direction = cy->vec, rotation_matrix = align_vector_to_axis(
	direction, vector(0, 1, 0)), 0);
	set_trans(shape, cy, rotation_matrix);
	(1) && (cy->center = point(0, 0, 0), parse_colors(&cy->material.color,
	line), object->form = shape, object->object = cy, object->next = NULL,
	append_objects(objects_list, object), 0);
}
