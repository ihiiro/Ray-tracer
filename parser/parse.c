/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:30:58 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/30 11:25:44 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data_structs/data_structs.h"
#include "../data_structs/data_funcs.h"
#include <stdlib.h>

void	parse_sphere(const char *line, t_world **world,
t_object_ **objects_list, int is_fraction)
{
	t_sphere	*sp;
	t_object_	*object;

	alloc_and_parse_pos(&sp, &object, world, &line);
	while (*line == ' ')
		line++;
	sp->radius = ft_atoi(line, &is_fraction) / (10.0 / is_fraction) / 2;
	if (sp->radius <= 0)
		exitf("sphere parse error\n");
	sp->transform = matrix_multiply(scaling(sp->radius, sp->radius, sp->radius),
			translation(sp->center.x, sp->center.y, sp->center.z), 4);
	sp->center = point(0, 0, 0);
	sp->radius = 1;
	is_fraction = 10;
	reach_for(&line, ' ', 0);
	parse_colors(sp, line);
	sp->material.ambient = (*world)->ambient_intensity;
	object->form = SPHERE;
	object->object = sp;
	object->next = NULL;
	append_objects(objects_list, object);
}

void	parse_lights(const char *line, t_light_ **lights_list, int is_fraction)
{
	t_light_	*light;

	parse_light_pos(&line, &light, 10);
	while (*line == ' ')
		line++;
	light->intensity = ft_atoi(line, &is_fraction) / (10.0 / is_fraction);
	is_fraction = 10;
	reach_for(&line, ' ', 0);
	light->color.x = ft_atoi(line, &is_fraction);
	reach_for(&line, ',', 1);
	light->color.y = ft_atoi(line, &is_fraction);
	is_fraction = 10;
	reach_for(&line, ',', 1);
	light->color.z = ft_atoi(line, &is_fraction);
	is_fraction = 10;
	if (!valid_color(light->color) || light->intensity > 1
		|| light->intensity < 0)
		exitf("lights parse error\n");
	light->next = NULL;
	append_lights(lights_list, light);
}

void	parse_light_pos(const char **line, t_light_ **light, int is_fraction)
{
	reach_for(line, ' ', 0);
	*light = malloc(sizeof(t_light_));
	(*light)->pos.x = ft_atoi(*line, &is_fraction) / (10.0 / is_fraction);
	is_fraction = 10;
	reach_for(line, ',', 1);
	(*light)->pos.y = ft_atoi(*line, &is_fraction) / (10.0 / is_fraction);
	is_fraction = 10;
	reach_for(line, ',', 1);
	(*light)->pos.z = ft_atoi(*line, &is_fraction) / (10.0 / is_fraction);
	is_fraction = 10;
	reach_for(line, ' ', 0);
}

void	parse_camera(const char *line, t_world **world, int is_fraction)
{
	reach_for(&line, ' ', 0);
	(*world)->camera.pos.x = ft_atoi(line, &is_fraction) / (10.0 / is_fraction);
	is_fraction = 10;
	reach_for(&line, ',', 1);
	(*world)->camera.pos.y = ft_atoi(line, &is_fraction) / (10.0 / is_fraction);
	is_fraction = 10;
	reach_for(&line, ',', 1);
	(*world)->camera.pos.z = ft_atoi(line, &is_fraction) / (10.0 / is_fraction);
	is_fraction = 10;
	while (*line != ' ')
		line++;
	(*world)->camera.vec.x = ft_atoi(line, &is_fraction);
	is_fraction = 10;
	reach_for(&line, ',', 1);
	(*world)->camera.vec.y = ft_atoi(line, &is_fraction);
	is_fraction = 10;
	reach_for(&line, ',', 1);
	(*world)->camera.vec.z = ft_atoi(line, &is_fraction);
	is_fraction = 10;
	reach_for(&line, ' ', 0);
	(*world)->camera.fov = ft_atoi(line, &is_fraction);
	if ((*world)->camera.fov < 0 || (*world)->camera.fov > 180
		|| !normalized_vector((*world)->camera.vec))
		exitf("camera parse error\n");
}

void	parse_ambient(const char *line, t_world **world, int is_fraction)
{
	reach_for(&line, ' ', 0);
	while (*line == ' ')
		line++;
	(*world)->ambient_intensity = ft_atoi(line, &is_fraction)
		/ (10.0 / is_fraction);
	is_fraction = 10;
	reach_for(&line, ' ', 0);
	(*world)->ambient_color.x = ft_atoi(line, &is_fraction);
	reach_for(&line, ',', 1);
	(*world)->ambient_color.y = ft_atoi(line, &is_fraction);
	is_fraction = 10;
	reach_for(&line, ',', 1);
	(*world)->ambient_color.z = ft_atoi(line, &is_fraction);
	is_fraction = 10;
	if (!valid_color((*world)->ambient_color)
		|| (*world)->ambient_intensity > 1 || (*world)->ambient_intensity < 0)
		exitf("ambience parse error\n");
}
