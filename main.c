/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:01:35 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/16 14:24:31 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs/data_funcs.h"
#include "data_structs/data_structs.h"
#include <stdlib.h>
#include <libc.h>

size_t	strlen_(const char *str)
{
	size_t	l;

	if (!str)
		exitf("usage: ./miniRT <filename>.rt\n");
	l = -1;
	while (str[++l])
		;
	return (l);
}

void	start_rt_engine(char *fn)
{
	t_world		*scene;
	t_scene		mlx;
	t_canvas	image;
	t_light_	*tmp_lights;
	t_object_	*tmp_objects;

	(1) && (mlx.i = -1, scene = parse(fn), camera(300, 300,
	&scene->camera), scene->camera.transform = view_transform(scene->camera.pos,
	scene->camera.vec, vector(0, 1, 0)));
	(1) && (mlx.mlx = mlx_init(300, 300, "scene", false),
		mlx.img = mlx_new_image(mlx.mlx,
	300, 300), image = canvas(scene->camera.hsize, scene->camera.vsize),
	render(&image, &scene->camera, scene),
	create_canvas(&image, mlx.img, mlx.mlx), mlx_image_to_window(mlx.mlx,
	mlx.img, 0, 0), mlx_loop(mlx.mlx), 0);
	while (++mlx.i < image.height)
		free(image.pixels[mlx.i]);
	(1) && (free(image.pixels), free(scene->camera.transform), 0);
	while (scene->lights_list)
		(1) && (tmp_lights = scene->lights_list->next, free(scene->lights_list),
		scene->lights_list = tmp_lights);
	while (scene->objects_list)
		(1) && (tmp_objects = scene->objects_list->next,
		free(scene->objects_list->object), free(scene->objects_list),
		scene->objects_list = tmp_objects);
}

int	main(int argc, char **argv)
{
	size_t	l;

	l = strlen_(argv[1]);
	if (argc != 2)
		exitf("usage: ./miniRT <filename>.rt\n");
	if (l < 4)
		exitf("usage: ./miniRT <filename>.rt\n");
	if (!(argv[1][l - 1] == 't' && argv[1][l - 2]
		== 'r' && argv[1][l - 3] == '.'))
		exitf("usage: ./miniRT <filename>.rt\n");
	start_rt_engine(argv[1]);
	return (EXIT_SUCCESS);
}
