/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:06:28 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/04 19:50:50 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"
#include <math.h>

#include <libc.h>

t_matrix	*view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple		forward;
	t_tuple		upn;
	t_tuple		left;
	t_tuple		true_up;
	t_matrix	*orientation;

	if (to.w == POINT)
		forward = normalize_vec(sub_tuples(to, from));
	else
		forward = normalize_vec(to);
	upn = normalize_vec(up);
	left = vec_cross(forward, upn);
	true_up = vec_cross(left, forward);
	orientation = return_4_by_4_matrix(
	return_tuple(left.x, left.y, left.z, 0),
	return_tuple(true_up.x, true_up.y, true_up.z, 0),
	return_tuple(-forward.x, -forward.y, -forward.z, 0),
	return_tuple(0, 0, 0, 1));
	return (matrix_multiply(orientation, translation(-from.x, -from.y,
	-from.z), 4));
}
void	camera(double hsize, double vsize, t_camera_ *c)
{
	double	half_view;
	double	aspect;

	c->hsize = hsize;
	c->vsize = vsize;
	c->transform = identity();
	half_view = tan(c->fov / 2.0);
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

	camray.xoffset = (px + .5) * cam->pixel_size;
	camray.yoffset = (py + .5) * cam->pixel_size;
	camray.world_x = cam->half_width - camray.xoffset;
	camray.world_y = cam->half_height - camray.yoffset;
	camray.pixel = multiply_matrix_by_tuple(invert_matrix(cam->transform, 4),
	point(camray.world_x, camray.world_y, -1));
	camray.origin = multiply_matrix_by_tuple(invert_matrix(cam->transform, 4), point(0, 0, 0));
	camray.direction = normalize_vec(sub_tuples(camray.pixel, camray.origin));
	return (return_ray(camray.origin, camray.direction));
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
			rgb = color_at(world, ray);
			write_pixel(canvas, x, y, rgb);
			x++;
		}
		y++;
	}
}
