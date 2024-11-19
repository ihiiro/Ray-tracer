/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:26:12 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/19 13:20:27 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data_structs/data_structs.h"
#include "../data_structs/data_funcs.h"
#include "get_next_line/get_next_line.h"
#include <libc.h>

void	parse_colors(t_tuple *primitive_rgb, const char *line)
{
	primitive_rgb->x = atodbl(line) / 255.0;
	reach_for(&line, ',', 1);
	primitive_rgb->y = atodbl(line) / 255.0;
	reach_for(&line, ',', 1);
	primitive_rgb->z = atodbl(line) / 255.0;
	if (!valid_color(*primitive_rgb))
		exitf("color parse error\n");
}

void	alloc_and_parse_pos(t_sphere **sp, t_object_ **object,
	const char **line)
{
	*sp = malloc(sizeof(t_sphere));
	*object = malloc(sizeof(t_object_));
	**sp = sphere(0);
	validate_line((char *)*line);
	reach_for(line, ' ', 0);
	(*sp)->center.x = atodbl(*line);
	reach_for(line, ',', 1);
	(*sp)->center.y = atodbl(*line);
	reach_for(line, ',', 1);
	(*sp)->center.z = atodbl(*line);
	reach_for(line, ' ', 0);
}

void	get_values(const char *line, t_light_ **lights_list,
t_object_ **objects_list, t_world **world)
{
	if (line[0] == 'A')
		parse_ambient(line, world);
	else if (line[0] == 'C')
		parse_camera(line, world);
	else if (line[0] == 'L')
		parse_lights(line, lights_list);
	else if (line[0] == 's' && line[1] == 'p')
		parse_sphere(line, objects_list);
	else if (line[0] == 'p' && line[1] == 'l')
		parse_plane(line, objects_list);
	else if (line[0] == 'c' && line[1] == 'y')
		parse_cylinder(line, objects_list);
	else if (line[0] == 'c' && line[1] == 'o')
		parse_cylinder(line, objects_list);
}

void	init_parse(t_parser *parser_)
{
	parser_->world->camera.vec = vector(0, 0, 0);
	parser_->world->ambient_intensity = -1;
	parser_->lights_list = NULL;
	parser_->objects_list = NULL;
}

t_world	*parse(char *file)
{
	t_parser	parser_;

	parser_.world = malloc(sizeof(t_world));
	memset(parser_.world, 0, sizeof(t_world));
	init_parse(&parser_);
	parser_.fd = open(file, O_RDONLY);
	(parser_.fd < 0) && (exitf("file invalid\n"), 0);
	parser_.line = get_next_line(parser_.fd);
	while (parser_.line)
	{
		get_values(parser_.line, &parser_.lights_list,
			&parser_.objects_list, &parser_.world);
		free((char *)parser_.line);
		parser_.line = get_next_line(parser_.fd);
	}
	if (!parser_.lights_list || !parser_.objects_list)
		exitf("world: no objects and/or no lights\n");
	parser_.world->lights_list = parser_.lights_list;
	parser_.world->objects_list = parser_.objects_list;
	clean_w(parser_.world);
	if (equal_tuple(parser_.world->camera.vec, vector(0, 0, 0)))
		exitf("world: no camera\n");
	if (equal(-1, parser_.world->ambient_intensity))
		exitf("world: no ambient defined\n");
	return (parser_.world);
}
