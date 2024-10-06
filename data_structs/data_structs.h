/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:20:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/06 18:20:34 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <stdbool.h>

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
	int		form;
}	t_xs;

/* OBJECTS */
typedef struct s_material
{
	t_tuple color;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}		t_material;

typedef struct s_sphere
{
	int			id;
	t_tuple 	center;
	double		radius;
	t_matrix 	*transform;
	t_material	material;
}	t_sphere;

typedef struct s_intersection
{
	int			atom_count;
	double		t;
	void		*object;
}		t_intersection;

/*Point Light*/
typedef struct s_light
{
	t_tuple intensity;
	t_tuple	position;
}		t_light;

typedef struct s_lighting
{
	t_material	m;
	t_light		light;
	t_tuple		point;
	t_tuple		eyev;
	t_tuple		normalv;
	t_tuple		ambient_effective_color;
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
# define POINT 1.0
# define VECTOR 0.0
# define SPHERE 0


/* PARSER */
typedef struct s_light_
{
	t_tuple	pos;
	t_tuple	color;
	double	intensity;
	struct s_light_	*next;
}		t_light_;

typedef struct s_object_
{
	int		form;
	void	*object;
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
	t_light_ 	*lights_list;
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
typedef	struct s_comps
{
	double		t;
	t_object_	object;
	t_tuple		point;
	t_tuple		eyev;
	t_tuple		normalv;
	int 		inside;
	t_tuple	over_point;
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
