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

tuple_t	point(double x, double y, double z);
tuple_t	vector(double x, double y, double z);

bool	equal(double a, double b);

#endif