/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:20:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/16 15:00:32 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdbool.h>
#include <stddef.h>
#include "../MLX/MLX42.h"

typedef struct s_disc
{
	double	a;
	double	b;
	double	c;
	double	disc;
}	t_disc;
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
	double	x;
	double	y;
	double	z;
	double	w;
}			t_tuple;

typedef struct s_pixel
{
	int		x;
	int		y;
	t_tuple	color;
}			t_pixel;

typedef struct s_canvas
{
	int		width;
	int		height;
	t_pixel	**pixels;
}			t_canvas;

typedef struct s_ray
{
	t_tuple		origin;
	t_tuple		direction;
}	t_ray;

/* CONVENIENT ALIASES */
typedef t_tuple	t_matrix;
/* intersections */
typedef struct s_xs
{
	int		count;
	void	*object0;
	void	*object1;
	double	t0;
	double	t1;
	int		form;
}	t_xs;

/* OBJECTS */
typedef struct s_material
{
	t_tuple	color;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}		t_material;

typedef struct s_sphere
{
	t_tuple		center;
	double		radius;
	t_matrix	*transform;
	t_material	material;
}	t_sphere;

typedef struct s_plane
{
	t_tuple		pip;
	t_tuple		normal;
	t_material	material;
	t_matrix	*transform;
}		t_plane;

typedef struct s_cylinder
{
	t_tuple		center;
	t_tuple		vec;
	double		height;
	double		radius;
	double		minimum;
	double		maximum;
	t_matrix	*transform;
	t_material	material;
}	t_cylinder;
typedef struct s_intersection
{
	int			atom_count;
	double		t;
	void		*object;
}		t_intersection;

/*Point Light*/
typedef struct s_light
{
	t_tuple	intensity;
	t_tuple	position;
}		t_light;

typedef struct s_lighting
{
	t_material	m;
	t_light		light;
	t_tuple		point;
	t_tuple		eyev;
	t_tuple		normalv;
	t_tuple		am_eff_col;
	bool		in_shadow;
}		t_lighting;

typedef struct s_lighting_components
{
	t_tuple	effective_color;
	t_tuple	lightv;
	t_tuple	ambient;
	t_tuple	diffuse;
	t_tuple	specular;
	double	light_dot_normalv;
	t_tuple	reflectv;
	double	reflect_dot_eye;
	double	specular_factor;
	t_tuple	intensity;	
}		t_lighting_components;

/* CONSTANTS */
#define POINT 1.0
#define VECTOR 0.0

//objects
#define SPHERE 	0
#define PLANE  	1
#define CYLINDER 	2
#define CONE		3

//
#define MULTI  0
#define SINGLE 1

/* PARSER */
typedef struct s_light_
{
	t_tuple			pos;
	t_tuple			color;
	double			intensity;
	struct s_light_	*next;
}		t_light_;

typedef struct s_object_
{
	int					form;
	void				*object;
	struct s_object_	*next;
}		t_object_;

typedef struct s_camera_
{
	t_tuple		pos;
	t_tuple		vec;
	double		fov;
	double		hsize;
	double		vsize;
	t_matrix	*transform;
	double		pixel_size;
	double		half_width;
	double		half_height;
}		t_camera_;

typedef struct s_world
{
	t_light_	*lights_list;
	t_object_	*objects_list;
	t_tuple		ambient_color;
	double		ambient_intensity;
	t_camera_	camera;
}		t_world;

typedef struct s_parser
{
	t_light_	*lights_list;
	t_object_	*objects_list;
	t_world		*world;
	const char	*line;
	int			fd;
}		t_parser;

/* world-ray intersections */
typedef struct s_xs_list
{
	int					count;
	double				t;
	t_object_			object;
	struct s_xs_list	*next;
}		t_xs_list;

/*Precomputing the state of an intersection*/
typedef struct s_comps
{
	double		t;
	t_object_	object;
	t_tuple		point;
	t_tuple		eyev;
	t_tuple		normalv;
	int			inside;
	t_tuple		over_point;
}	t_comps;

typedef struct s_camray
{
	double	xoffset;
	double	yoffset;
	double	world_x;
	double	world_y;
	t_tuple	pixel;
	t_tuple	origin;
	t_tuple	direction;
}		t_camray;

typedef struct s_shadow
{
	bool	shadowed;
	t_tuple	v;
	double	distance;
	t_tuple	direction;
}	t_shadow;

typedef struct s_cam
{
	t_tuple	upn;
	t_tuple	forward;
	t_tuple	left;
}	t_cam;

typedef struct s_scene
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			i;

}	t_scene;

typedef struct s_rot
{
	double	magnitude;
	t_tuple	normalized_axis;
	double	x;
	double	y;
	double	z;
	double	cos_theta;
	double	sin_theta;
	double	one_minus_cos;
	t_tuple	row1;
	t_tuple	row2;
	t_tuple	row3;
	t_tuple	row4;
}	t_rot;