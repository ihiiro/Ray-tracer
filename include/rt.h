#ifndef RT_H
# define RT_H
# include <stdbool.h>

/* MATH MACROS */
# define EPSILON 0.00001

typedef struct tuple_s
{
	double	x;
	double	y;
	double	z;
	double	w;
}		tuple_t;

tuple_t	tuple(double x, double y, double z, double w);
tuple_t	addtup(tuple_t tuple_a, tuple_t tuple_b);
tuple_t	subtup(tuple_t tuple_a, tuple_t tuple_b);
tuple_t	mult_by_scalar(tuple_t t, double scalar);
tuple_t	div_by_scalar(tuple_t t, double scalar);
tuple_t	vector(double x, double y, double z);
tuple_t	point(double x, double y, double z);
tuple_t	vec_normalize(tuple_t v);
tuple_t	negtup(tuple_t t);

double	vec_magnitude(tuple_t v);

bool 	equaltup(tuple_t a, tuple_t b);
bool	equal(double a, double b);

#endif
