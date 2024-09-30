/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_funcs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:25:19 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/30 11:24:57 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "data_structs.h"
#include <stdbool.h>
#include "../MLX/MLX42.h"

t_tuple	return_tuple(double x, double y, double z, double w);
double	point_or_vector(t_tuple t);
t_tuple	point(double x, double y, double z);
t_tuple	vector(double x, double y, double z);
bool	equal_tuple(t_tuple a, t_tuple b);
bool	equal(double a, double b);

/* TUPLE ARITHMETIC */
t_tuple add_tuples(t_tuple a, t_tuple b);
t_tuple sub_tuples(t_tuple a, t_tuple b);
t_tuple	negate_tuple(t_tuple t);
t_tuple scale_tuple(t_tuple t, double scalar);
double	radians(double angle);

/* COLORS */
t_tuple color(double red, double green, double blue);
t_tuple	add_colors(t_tuple a, t_tuple b);
t_tuple	sub_colors(t_tuple a, t_tuple b);
t_tuple	multiply_colors(t_tuple a, t_tuple b);
t_tuple	multiply_color_by_scalar(t_tuple t, double scalar);

/* CANVAS */
void		create_canvas(t_canvas *c, mlx_image_t *img, mlx_t *mlx);
t_canvas	canvas(int width, int height);
void		write_pixel(t_canvas *canvas, int x, int y, t_tuple rgb);
t_tuple 	*pixel_at(t_canvas *canvas, int x, int y);

/* MATRICES */
t_matrix	*return_4_by_4_matrix(t_tuple a, t_tuple b, t_tuple c, t_tuple d);
t_matrix	*return_2_by_2_matrix(t_tuple a, t_tuple b);
t_matrix	*return_3_by_3_matrix(t_tuple a, t_tuple b, t_tuple c);
bool		equal_matrices(t_matrix *a, t_matrix *b, size_t size);
t_matrix	*matrix_multiply(t_matrix *A, t_matrix *B, size_t size);
t_tuple		multiply_matrix_by_tuple(t_matrix *m, t_tuple t);
t_matrix	*matrix_transpose(t_matrix *m, size_t size);
double		determinant_2x2_matrix(t_matrix *matrix);
t_matrix	*submatrix(t_matrix *matrix, int row, int column, int size);
double 		matrix_3_by_3_minor(t_matrix *matrix, int row, int column);
double		matrix_4_by_4_minor(t_matrix *matrix, int row, int column);
double		matrix_cofactor(t_matrix *matrix, int row, int column, size_t size);
double		matrix_determinant(t_matrix *m, size_t size);
t_matrix	*invert_matrix(t_matrix *m, size_t size);

/* TRANSFORMATIONS */
t_matrix	*translation(double x, double y, double z);
t_matrix	*scaling(double x, double y, double z);
t_matrix	*rotation_x(double r);
t_matrix	*rotation_y(double r);
t_matrix	*rotation_z(double r);
t_matrix	*shearing(t_shear shear);
t_shear		fill_shear(t_tuple t1, t_tuple t2);
t_matrix	*identity();

/*RAY - TRACER*/
t_ray			return_ray(t_tuple org, t_tuple dir);
t_tuple 		position(t_ray ray, double t);

/* INTERSECTION TESTING */
t_intersection	hit(t_intersection *intersections);

/* OBJECTS */
t_sphere	sphere(int id);
t_xs		sphere_intersect(t_sphere *s, t_ray r);
t_ray		transform_ray(t_ray r, t_matrix *m);
void		set_transform(t_sphere *s, t_matrix *m);


/*From World space to Object space*/
t_tuple		normal_at(t_sphere s, t_tuple point);
/*Reflection*/
t_tuple	reflect(t_tuple in, t_tuple normal);
/*Phong Model*/
/*Point Light*/
t_light		point_light(t_tuple position, t_tuple intensity);

/* lights */
t_material	material();
t_tuple 	lighting(t_lighting l);

/* PARSER */
void	reach_for(const char **line, char end, int skip);
void	parse_ambient(const char *line, t_world **world, int is_fraction);
void	parse_camera(const char *line, t_world **world, int is_fraction);
void	parse_lights(const char *line, t_light_ **lights_list, int is_fraction);
void	clean_w(t_world *world);
void	parse_sphere(const char *line, t_world **world, t_object_ **objects_list, int is_fraction);
void	alloc_and_parse_pos(t_sphere **sp, t_object_ **object, t_world **world, const char **line);
int		ft_atoi(const char *str, int *is_fraction);
bool	valid_color(t_tuple color);
void	exitf(char *msg);
void	append_objects(t_object_ **lst, t_object_ *new);
void	parse_light_pos(const char **line, t_light_ **light, int is_fraction);
void	append_lights(t_light_ **lst, t_light_ *new);
bool	normalized_vector(t_tuple v);
void	parse_colors(t_sphere *sp, const char *line);