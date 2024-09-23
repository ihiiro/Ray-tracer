/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:20:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/23 22:19:18 by yel-yaqi         ###   ########.fr       */
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

/* intersections */
typedef struct s_xs
{
	int		count;
	void	*object0;
	void	*object1;
	double	t0;
	double	t1;
}	t_xs;

/* OBJECTS */
typedef struct s_sphere
{
	int		id;
	t_tuple center;
	double	radius;
	t_matrix *transform;
}	t_sphere;

// typedef struct s_object
// {
// 	int form;
// 	t_sphere	*sphere;
// 	t_sphere	*cylinder;
// }		t_object;

typedef struct s_intersection
{
	int			atom_count;
	double		t;
	void		*object;
}		t_intersection;