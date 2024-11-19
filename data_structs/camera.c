/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:06:28 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/19 13:47:36 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"
#include <math.h>
#include <stdlib.h>

t_matrix	*view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_cam		cam;
	t_tuple		true_up;
	t_matrix	*orientation;
	t_matrix	*orient_translate_product;
	t_matrix	*translation_matrix;

	if (to.w == POINT)
		cam.forward = normalize_vec(sub_tuples(to, from));
	else
		cam.forward = to;
	if (equal(cam.forward.y, 1) || equal(cam.forward.y, -1))
		cam.forward = normalize_vec(vector(0, cam.forward.y, NUDGE));
	cam.upn = normalize_vec(up);
	cam.left = vec_cross(cam.forward, cam.upn);
	true_up = vec_cross(cam.left, cam.forward);
	orientation = get_4_by_4_matrix(
			get_tuple(cam.left.x, cam.left.y, cam.left.z, 0),
			get_tuple(true_up.x, true_up.y, true_up.z, 0),
			get_tuple(-cam.forward.x, -cam.forward.y, -cam.forward.z, 0),
			get_tuple(0, 0, 0, 1));
	translation_matrix = translation(-from.x, -from.y, -from.z);
	orient_translate_product = matrix_multiply(orientation,
			translation_matrix, 4);
	return (free(orientation), free(translation_matrix),
		orient_translate_product);
}

void	camera(double hsize, double vsize, t_camera_ *c)
{
	double	half_view;
	double	aspect;

	c->hsize = hsize;
	c->vsize = vsize;
	c->transform = NULL;
	if (equal(c->vec.y, 1) || equal(c->vec.y, -1))
		half_view = tan(radians(c->fov * (NUDGE - .002) / 2.0));
	else
		half_view = tan(radians(c->fov / 2.0));
	aspect = c->hsize / c->vsize;
	if (aspect >= 1)
	{
		c->half_width = half_view;
		c->half_height = half_view / aspect;
	}
	else
	{
		c->half_width = half_view * aspect;
		c->half_height = half_view;
	}
	c->pixel_size = c->half_width * 2 / c->hsize;
}

t_ray	ray_for_pixel(t_camera_ *cam, double px, double py)
{
	t_camray	camray;
	t_matrix	*inversion;

	inversion = invert_matrix(cam->transform, 4);
	camray.xoffset = cam->pixel_size * (px + .5);
	camray.yoffset = cam->pixel_size * (py + .5);
	camray.world_x = cam->half_width - camray.xoffset;
	camray.world_y = cam->half_height - camray.yoffset;
	camray.pixel = multiply_matrix_by_tuple(inversion,
			point(camray.world_x, camray.world_y, -1));
	camray.origin = multiply_matrix_by_tuple(inversion, point(0, 0, 0));
	camray.direction = normalize_vec(sub_tuples(camray.pixel, camray.origin));
	if (inversion != cam->transform)
		free(inversion);
	return (get_ray(camray.origin, camray.direction));
}

void	render(t_canvas *canvas, t_camera_ *cam, t_world *world)
{
	int		x;
	int		y;
	t_ray	ray;
	t_tuple	rgb;

	y = 0;
	while (y < cam->vsize)
	{
		x = 0;
		while (x < cam->hsize)
		{
			ray = ray_for_pixel(cam, x, y);
			rgb = col_x_sc(color_at(world, ray), 255);
			write_pixel(canvas, x, y, rgb);
			x++;
		}
		y++;
	}
}
