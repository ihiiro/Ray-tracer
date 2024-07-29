#ifndef RT_H
# define RT_H
# include <stdbool.h>
# include <libc.h>
# include <mlx.h>
# include "structs.h"

/* MATH MACROS */
# define EPSILON 0.00001

/*  										*/
			/*   T   U   P   L   E  */
/* 											*/

tuple_t	tuple(double x, double y, double z, double w);
tuple_t	addtup(tuple_t tuple_a, tuple_t tuple_b);
tuple_t	subtup(tuple_t tuple_a, tuple_t tuple_b);
tuple_t	mult_by_scalar(tuple_t t, double scalar);
tuple_t	div_by_scalar(tuple_t t, double scalar);
bool 	equaltup(tuple_t a, tuple_t b);
tuple_t	multup(tuple_t a, tuple_t b);
tuple_t	negtup(tuple_t t);

/*  										*/
			/*  V   E   C  T   O   R  */
/* 											*/

tuple_t	vector(double x, double y, double z);
tuple_t	vec_cross(tuple_t va, tuple_t vb);
tuple_t	vec_normalize(tuple_t v);

double 	vec_dot(tuple_t va, tuple_t vb);
double	vec_magnitude(tuple_t v);

/*  										*/
			/*  P   O   I   N   T  */
/* 											*/

tuple_t	point(double x, double y, double z);

/*  										*/
			/*  C   O   L   O   R  */
/* 											*/

color_t	hadamard_product(color_t rgb0, color_t rgb1);
color_t	scale_color(color_t rgb, double scalar);
color_t	diff_color(color_t rgb0, color_t rgb1);
color_t	color(double r, double g, double b);

/*  										*/
			/*  M   I   S   C  */
/* 											*/

bool	equal(double a, double b);

#endif
