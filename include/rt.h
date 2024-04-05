#ifndef RT_H
# define RT_H

typedef struct tuple_s
{
	double	x;
	double	y;
	double	z;
	double	w;
}		tuple_t;

tuple_t	point(double x, double y, double z);
tuple_t	vector(double x, double y, double z);

#endif