/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:01:35 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/28 14:57:14 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs/data_funcs.h"
#include "data_structs/data_structs.h"
#include <stdlib.h>

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
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_canvas	image;

	scene = parse(fn);
	camera(300, 300, &scene->camera);
	scene->camera.transform = view_transform(scene->camera.pos,
		scene->camera.vec, vector(0,1,0));
	mlx = mlx_init(300, 300, "scene", false);
	img = mlx_new_image(mlx, 300, 300);
	image = canvas(scene->camera.hsize, scene->camera.vsize);
	render(&image, &scene->camera, scene);
	create_canvas(&image, img, mlx);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
}

int	main(int argc, char **argv)
{
	size_t	l;

	l = strlen_(argv[1]);
	if (argc != 2)
		exitf("usage: ./miniRT <filename>.rt\n");
	if (l < 4)
		exitf("usage: ./miniRT <filename>.rt\n");
	if (!(argv[1][l - 1] == 't' && argv[1][l - 2] == 'r' && argv[1][l - 3] == '.'))
		exitf("usage: ./miniRT <filename>.rt\n");
	start_rt_engine(argv[1]);
	return (EXIT_SUCCESS);
}
