#include "../include/rt.h"

tuple_t	tuple(double x, double y, double z, double w)
{
	tuple_t	t;

	t.x = x;
	t.y = y;
	t.z = z;
	t.w = w;
	return (t);
}

tuple_t	point(double x, double y, double z)
{
	return (tuple(x, y, z, 1.0));
}

tuple_t	vector(double x, double y, double z)
{
	return (tuple(x, y, z, 0.0));
}

tuple_t	color(double r, double g, double b)
{
	return (tuple(r, g, b, 1));
}
