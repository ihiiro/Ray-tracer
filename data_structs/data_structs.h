/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:20:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/22 20:00:56 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


typedef struct s_shear
{
	double	xy;
	double	xz;
	double	yx;
	double	yz;
	double	zx;
	double	zy;
}		t_shear;

typedef struct s_tuple
{
	double x;
	double y;
	double z;
	double w;
}			t_tuple;

typedef struct s_pixel
{
	int x;
	int y;
	t_tuple color;
}			t_pixel;

typedef struct s_canvas
{
	int 	width;
	int 	height;
	t_pixel **pixels;
}			t_canvas;

typedef struct s_ray
{
	t_tuple 	origin;
	t_tuple		direction;
}	t_ray;

/* CONSTANTS */
# define POINT 1.0
# define VECTOR 0.0

/* CONVENIENT ALIASES */
typedef t_tuple t_matrix;

/*Not 100%*/
typedef struct s_sphere
{
	int		id;
	t_tuple center;
	double	radius;
	t_matrix *transform;
}	t_sphere;
