/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_funcs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:25:19 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/19 11:11:56 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "data_structs.h"
#include <stdbool.h>
#include "/Users/aboulakr/Desktop/MLX42.h"
#include <libc.h>

/* CANVAS */
void		create_canvas(t_canvas *c, mlx_image_t *img, mlx_t *mlx);
t_canvas	canvas(int width, int height);
void		write_pixel(t_canvas *canvas, int x, int y, t_tuple rgb);
t_tuple		*pixel_at(t_canvas *canvas, int x, int y);

t_tuple		get_tuple(double x, double y, double z, double w);
double		point_or_vector(t_tuple t);
t_tuple		point(double x, double y, double z);
t_tuple		vector(double x, double y, double z);
bool		equal_tuple(t_tuple a, t_tuple b);
bool		equal(double a, double b);

/* TUPLE ARITHMETIC */
t_tuple		add_tuples(t_tuple a, t_tuple b);
t_tuple		sub_tuples(t_tuple a, t_tuple b);
t_tuple		negate_tuple(t_tuple t);
t_tuple		scale_tuple(t_tuple t, double scalar);
double		radians(double angle);

/* COLORS */
t_tuple		color(double red, double green, double blue);
t_tuple		add_colors(t_tuple a, t_tuple b);
t_tuple		sub_colors(t_tuple a, t_tuple b);
t_tuple		multiply_colors(t_tuple a, t_tuple b);
t_tuple		col_x_sc(t_tuple t, double scalar);

/* MATRICES */
t_matrix	*get_4_by_4_matrix(t_tuple a, t_tuple b, t_tuple c, t_tuple d);
t_matrix	*get_2_by_2_matrix(t_tuple a, t_tuple b);
t_matrix	*get_3_by_3_matrix(t_tuple a, t_tuple b, t_tuple c);
bool		equal_matrices(t_matrix *a, t_matrix *b, size_t size);
t_matrix	*matrix_multiply(t_matrix *A, t_matrix *B, size_t size);
t_tuple		multiply_matrix_by_tuple(t_matrix *m, t_tuple t);
t_matrix	*matrix_transpose(t_matrix *m, size_t size);
double		determinant_2x2_matrix(t_matrix *matrix);
t_matrix	*submatrix(t_matrix *matrix, int row, int column, int size);
double		matrix_3_by_3_minor(t_matrix *matrix, int row, int column);
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
t_matrix	*identity(void);

/*RAY - TRACER*/
t_ray		get_ray(t_tuple org, t_tuple dir);
t_tuple		position(t_ray ray, double t);

/* INTERSECTION TESTING */
// t_intersection	hit(t_intersection *intersections);
t_xs_list	*hit(t_xs_list *xs_list);

/* OBJECTS */
t_sphere	sphere(int id);
t_plane		plane(void);
t_cylinder	cylinder(void);
t_xs		sphere_intersect(t_sphere *s, t_ray r);
t_ray		transform_ray(t_ray r, t_matrix *m);
void		set_transform(t_sphere *s, t_matrix *m);

/*From World space to Object space*/
t_tuple		normal_at(t_sphere s, t_tuple point);
/*Reflection*/
t_tuple		reflect(t_tuple in, t_tuple normal);
/*Phong Model*/
/*Point Light*/
t_light		point_light(t_tuple position, t_tuple intensity);

/* lights */
t_material	material(void);
t_tuple		lighting(t_lighting l);

/* PARSER */
void		reach_for(const char **line, char end, int skip);
void		parse_ambient(const char *line, t_world **world);
void		parse_camera(const char *line, t_world **world);
void		parse_lights(const char *line, t_light_ **lights_list);
void		clean_w(t_world *world);
void		parse_sphere(const char *line, t_object_ **objects_list);
void		parse_plane(const char *line, t_object_ **objects_list);
void		parse_cylinder(const char *line, t_object_ **objects_list);
void		alloc_and_parse_pos(t_sphere **sp, t_object_ **object,
				const char **line);
bool		valid_color(t_tuple color);
void		exitf(const char *msg);
void		append_objects(t_object_ **lst, t_object_ *new);
void		parse_light_pos(const char **line, t_light_ **light);
void		append_lights(t_light_ **lst, t_light_ *new);
bool		normalized_vector(t_tuple v);
void		parse_colors(t_tuple *primitive_rgb, const char *line);
t_world		*parse(char *file);
void		validate_line(char *line);
void		validate_a(char *line);
void		validate_c(char *line);
void		validate_l(char *line);
void		validate_sp(char *line);
void		validate_field(char **line, bool type);
void		validate_pl(char *line);
void		validate_cy(char *line);

/* WORLD */
t_xs_list	*intersect_world(t_world *world, t_ray ray);
t_comps		prepare_computations(t_xs_list *intersection, t_ray ray);

/* shading */
t_tuple		shade_hit(t_world w, t_comps comps);
t_tuple		color_at(t_world *w, t_ray r);

/* fraction reader */
double		atodbl(const char *str);
/*view transformation*/
t_matrix	*view_transform(t_tuple from, t_tuple to, t_tuple up);
/*Camera*/
void		camera(double hsize, double vsize, t_camera_ *c);
t_ray		ray_for_pixel(t_camera_ *cam, double px, double py);
void		render(t_canvas *canvas, t_camera_ *cam, t_world *world);
/*Shadows*/
bool		is_shadowed(t_world *w, t_light_ *light, t_tuple point);
t_xs		plane_intersect(t_plane *pl, t_ray ray);

/*Cylinder intersect*/
t_xs		cylinder_intersect(t_cylinder *cy, t_ray ray, int form);
t_tuple		normal_at_cylinder(t_cylinder cy, t_tuple world_point);
double		maximum_y(t_tuple center, double heigh);
double		minimum_y(t_tuple center, double heigh);

/* misc */
t_tuple		checker_board(t_tuple p);

/* bump-mapping presets (procedural) */
t_tuple		preset_sinewave_groove(t_tuple normal);
/*Rotation and Alignement*/
t_matrix	*align_vector_to_axis(t_tuple vec, t_tuple target_axis);
t_matrix	*rotation_axis_angle(t_tuple axis, double angle);
void		set_trans(int shape, t_cylinder *cy, t_matrix *rotation_matrix);