/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:29:47 by aboulakr          #+#    #+#             */
/*   Updated: 2024/09/29 10:23:44 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../MLX/MLX42.h"
#include <stdlib.h>
#include <stdio.h>


int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
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
	int			surface_area;

    c.width = width;
    c.height = height;
    c.pixels = malloc(sizeof(t_pixel *) * height);
    if (!c.pixels)
        exit(EXIT_FAILURE);
	y = 0;
	while (y < height)
	
	{
		c.pixels[y] = malloc(sizeof(t_pixel) * width);
        if (!c.pixels[y])
            exit(EXIT_FAILURE);
		y++;
	}
	y = 0;
    while (y < c.height)
	{
		x = 0;
		while (x < c.width)
		{
			c.pixels[y][x].color = color(255, 255, 255);	
			c.pixels[y][x].x = x;
			c.pixels[y][x].y = y;
			x++;
		}
		y++;
	}
    return (c);
}

void    create_canvas(t_canvas *c, mlx_image_t *img, mlx_t *mlx)
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
				ft_pixel(c->pixels[y][x].color.x, c->pixels[y][x].color.y, c->pixels[y][x].color.z,
				255));
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

t_tuple *pixel_at(t_canvas *canvas, int x, int y)
{
	return (&canvas->pixels[y][x].color);
}
