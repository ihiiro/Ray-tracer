/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_funcs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:25:19 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/21 21:35:16 by yel-yaqi         ###   ########.fr       */
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




