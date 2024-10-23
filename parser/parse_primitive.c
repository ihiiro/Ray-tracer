/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_primitive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:50:07 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/23 22:12:41 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data_structs/data_structs.h"
#include "../data_structs/data_funcs.h"
#include "../maths/maths.h"
#include <stdlib.h>
#include <math.h>

void	init_parse_plane(t_plane **pl, t_object_ **object, t_world *world)
{
	*pl = malloc(sizeof(t_plane));
	*object = malloc(sizeof(t_object_));
	**pl = plane();
	(*pl)->material.ambient = world->ambient_intensity;
}

void	parse_pip(t_plane *pl, const char **line)
{
	pl->pip.x = atodbl(*line);
	reach_for(line, ',', 1);
	pl->pip.y = atodbl(*line);
	reach_for(line, ',', 1);
	pl->pip.z = atodbl(*line);
}

void	parse_plane(const char *line, t_world **world,
t_object_ **objects_list)
{
	t_plane		*pl;
	t_object_	*object;

	init_parse_plane(&pl, &object, *world);
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
	reach_for(&line, ' ', 0);
	pl->transform = translation(pl->pip.x, pl->pip.y, pl->pip.z);
	pl->pip = point(0, 0, 0);
	parse_colors(&pl->material.color, line);
	object->form = PLANE;
	object->object = pl;
	object->next = NULL;
	append_objects(objects_list, object);
}

void	parse_cylinder_center_and_vector(t_cylinder **cy, t_world **world,
const char **line, t_object_ **object)
{
	*cy = malloc(sizeof(t_cylinder));
	*object = malloc(sizeof(t_object_));
	**cy = cylinder();
	(*cy)->material.ambient = (*world)->ambient_intensity;
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
}

#include <stdio.h>

void	parse_cylinder(const char *line, t_world **world,
t_object_ **objects_list)
{
	t_cylinder	*cy;
	t_object_	*object;
	t_tuple	    direction;
	t_matrix	*rotation_matrix;
	double 		angle_z;
	double 		angle_x;

	parse_cylinder_center_and_vector(&cy, world, &line, &object);
	while (*line == ' ')
		line++;
	cy->radius = atodbl(line) / 2;
	reach_for(&line, ' ', 0);
	while (*line == ' ')
		line++;
	cy->height = atodbl(line);
	reach_for(&line, ' ', 0);
	if (cy->height <= 0 || cy->radius <= 0)
		exitf("cy: height or radius <= 0\n");
	direction = normalize_vec(cy->vec);
	double angle_x = atan2(direction.z, direction.y); // Rotate around X-axis
    double angle_z = atan2(direction.x, direction.y); // Rotate around Z-axis
   	rotation_matrix = matrix_multiply(rotation_x(angle_x), rotation_z(angle_z), 4);
	cy->transform = matrix_multiply(translation(cy->center.x,
				cy->center.y, cy->center.z), matrix_multiply(rotation_matrix,
			scaling(cy->radius, 1, cy->radius), 4), 4);
	cy->center = point(0, 0, 0);
	parse_colors(&cy->material.color, line);
	object->form = CYLINDER;
	object->object = cy;
	object->next = NULL;
	append_objects(objects_list, object);
}
