/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:29:47 by aboulakr          #+#    #+#             */
/*   Updated: 2024/09/19 16:25:06 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../MLX/MLX42.h"
#include <stdlib.h>
#include <stdio.h>


int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

t_canvas	*canvas(int width, int height)
{
    t_canvas	*c;
    int			x;
	int			y;
	int			surface_area;

	c = malloc(sizeof(t_canvas));
    c->width = width;
    c->height = height;
    c->pixels = malloc(sizeof(t_pixel *) * height);
    if (!c->pixels)
        exit(EXIT_FAILURE);
	y = 0;
	while (y < height)
	{
		c->pixels[y] = malloc(sizeof(t_pixel) * width);
        if (!c->pixels[y])
            exit(EXIT_FAILURE);
		y++;
	}
	y = 0;
    while (y < c->height)
	{
		x = 0;
		while (x < c->width)
		{
			c->pixels[x][y].color = color(255, 0, 0);	
			c->pixels[x][y].x = x;
			c->pixels[x][y].y = y;
			x++;
		}
		y++;
	}
    return (c);
}

void    create_canvas(t_canvas *c)
{
    mlx_t       *mlx;
    mlx_image_t *img;
	int			x;
	int			y;

    mlx = mlx_init(c->width, c->height, "Canvas", false);
    img = mlx_new_image(mlx, c->width, c->height);
	y = 0;
    while (y < c->height)
	{
		x = 0;
		while (x < c->width)
		{
			mlx_put_pixel(img, c->pixels[x][y].x, c->pixels[x][y].y,
				ft_pixel(c->pixels[x][y].color.x, c->pixels[x][y].color.y, c->pixels[x][y].color.z,
				255));
			x++;
		}
		y++;
	}
    mlx_image_to_window(mlx, img, 0, 0);
    mlx_loop(mlx);
}