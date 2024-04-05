#include "../include/rt.h"

tuple_t	point(double x, double y, double z)
{
	tuple_t	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = 1.0;
	return (tuple);
}

tuple_t	vector(double x, double y, double z)
{
	tuple_t	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = 0.0;
	return (tuple);
}