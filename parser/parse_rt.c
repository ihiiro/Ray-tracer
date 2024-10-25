/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:26:12 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/26 00:44:02 by yel-yaqi         ###   ########.fr       */
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
t_world **world, const char **line)
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
		parse_sphere(line, world, objects_list);
	else if (line[0] == 'p' && line[1] == 'l')
		parse_plane(line, world, objects_list);
	else if (line[0] == 'c' && line[1] == 'y')
		parse_cylinder(line, world, objects_list);
	else if (line[0] == 'c' && line[1] == 'o')
		parse_cylinder(line, world, objects_list);
}

void	init_parse(t_parser *parser_)
{
	parser_->world->camera.vec = vector(0, 0, 0);
	parser_->world->ambient_intensity = -1;
	parser_->lights_list = NULL;
	parser_->objects_list = NULL;
}

t_world	*parse(const char *file)
{
	t_parser	parser_;

	parser_.world = malloc(sizeof(t_world));
	memset(parser_.world, 0, sizeof(t_world));
	init_parse(&parser_);
	parser_.fd = open(file, O_RDONLY);
	if (parser_.fd < 0)
		exit(EXIT_FAILURE);
	parser_.line = get_next_line(parser_.fd);
	while (parser_.line)
	{
		get_values(parser_.line, &parser_.lights_list,
			&parser_.objects_list, &parser_.world);
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

// int main()
// {
// 	printf("============================================================================================================\n");
// 	t_world *world = parse("s.rt");
// 	t_object_	*orig = world->objects_list;

// 	printf("world ambient intensity: [%.4f]\n", world->ambient_intensity);
// 	printf("world ambient rgb: [%.4f %.4f %.4f]\n", world->ambient_color.x, world->ambient_color.y, world->ambient_color.z);
// 	printf("world camera:\n\t3d_coords[%.4f %.4f %.4f]\n", world->camera.pos.x, world->camera.pos.y, world->camera.pos.z);
// 	printf("\torientation vector[%.4f %.4f %.4f]\n", world->camera.vec.x, world->camera.vec.y, world->camera.vec.z);
// 	printf("\tFOV[%.4f]\n", world->camera.fov);
// 	printf("world objects(spheres):\n");
// 	// spheres
// 	for (; world->objects_list; world->objects_list = world->objects_list->next)
// 	{
// 		if (world->objects_list->form == SPHERE)
// 		{
// 			t_sphere *sp = world->objects_list->object;
// 			printf("\tform[%d]\n\tcpos[%.4f %.4f %.4f]\n\tr[%.4f]\n\t&trans[%p]\n\twamb[%.4f]\n\trgb[%.4f %.4f %.4f]\n\n", world->objects_list->form, sp->center.x, sp->center.y, sp->center.z,
// 			sp->radius, sp->transform, sp->material.ambient,sp->material.color.x, sp->material.color.y, sp->material.color.z);
// 			// fprintf(stderr, "F");
// 		}
// 	}
// 	// planes
// 	world->objects_list = orig;
// 	printf("\nworld objects(planes):\n");
// 	for (; world->objects_list; world->objects_list = world->objects_list->next)
// 	{
// 		if (world->objects_list->form == PLANE)
// 		{
// 			t_plane	*pl = world->objects_list->object;
// 			printf("\tform[%d]\n\tpip[%.4f %.4f %.4f]\n\tnormal[%.4f %.4f %.4f]\n\t&trans[%p]\n\twamb[%.4f]\n\trgb[%.4f %.4f %.4f]\n\n",
// 			world->objects_list->form, pl->pip.x, pl->pip.y, pl->pip.z, pl->normal.x, pl->normal.y, pl->normal.z, pl->transform,
// 			pl->material.ambient, pl->material.color.x, pl->material.color.y, pl->material.color.z);
// 		}
// 	}
// 	// cylinders
// 	world->objects_list = orig;
// 	printf("\nworld objects(cylinders):\n");
// 	for (; world->objects_list; world->objects_list = world->objects_list->next)
// 	{
// 		if (world->objects_list->form == CYLINDER)
// 		{
// 			t_cylinder	*cy = world->objects_list->object;
// 			printf("\tform[%d]\n\tcpos[%.4f %.4f %.4f]\n\tr[%.4f]\n\th[%.4f]\n\tvec[%.4f %.4f %.4f]\n\t&trans[%p]\n\twamb[%.4f]\n\trgb[%.4f %.4f %.4f]\n\n",
// 			world->objects_list->form, cy->center.x, cy->center.y, cy->center.z, cy->radius, cy->height, cy->vec.x, cy->vec.y, cy->vec.z, cy->transform,
// 			cy->material.ambient, cy->material.color.x, cy->material.color.y, cy->material.color.z);
// 		}
// 	}
// 	printf("\nworld lights:\n");
// 	for (; world->lights_list; world->lights_list = world->lights_list->next)
// 	{
// 		printf("\tposition[%.4f %.4f %.4f]", world->lights_list->pos.x, world->lights_list->pos.y, world->lights_list->pos.z);
// 		printf("\n\trgb[%.4f %.4f %.4f]", world->lights_list->color.x, world->lights_list->color.y, world->lights_list->color.z);
// 		printf("\n\tintensity[%.4f]\n\n", world->lights_list->intensity);
// 	} 
// }


// NOTES <======================

// ATODBL OVERFLOW/UNDERFLOW ERROR CORRECTION!!
// make vector normalized or not correct !!