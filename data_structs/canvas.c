/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:29:47 by aboulakr          #+#    #+#             */
/*   Updated: 2024/11/19 11:11:37 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "/Users/aboulakr/Desktop/MLX42.h"
#include <stdlib.h>
#include <stdio.h>

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return (r << 24 | g << 16 | b << 8 | a);
}

t_canvas	canvas(int width, int height)
{
	t_canvas	c;
	int			x;
	int			y;

	(1) && (c.width = width, c.height = height, y = -1);
	c.pixels = malloc(sizeof(t_pixel *) * height);
	(!c.pixels) && (exitf("malloc\n"), 0);
	while (++y < height)
	{
		c.pixels[y] = malloc(sizeof(t_pixel) * width);
		(!c.pixels[y]) && (exitf("malloc\n"), 0);
	}
	y = -1;
	while (++y < c.height)
	{
		x = 0;
		while (x < c.width)
		{
			c.pixels[y][x].color = color(255, 255, 255);
			c.pixels[y][x].x = x;
			c.pixels[y][x].y = y;
			x++;
		}
	}
	return (c);
}

void	create_canvas(t_canvas *c, mlx_image_t *img, mlx_t *mlx)
{
	int			x;
	int			y;

	y = 0;
	while (y < c->height)
	{
		x = 0;
		while (x < c->width)
		{
			mlx_put_pixel(img, c->pixels[y][x].x, c->pixels[y][x].y,
				ft_pixel(c->pixels[y][x].color.x,
					c->pixels[y][x].color.y, c->pixels[y][x].color.z, 255));
			x++;
		}
		y++;
	}
	mlx_image_to_window(mlx, img, 0, 0);
}

void	write_pixel(t_canvas *canvas, int x, int y, t_tuple rgb)
{
	canvas->pixels[y][x].color = color(rgb.x, rgb.y, rgb.z);
}

t_tuple	*pixel_at(t_canvas *canvas, int x, int y)
{
	return (&canvas->pixels[y][x].color);
}
