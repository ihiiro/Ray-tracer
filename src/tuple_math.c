#include <stdbool.h>
#include "../include/rt.h"

bool	equaltup(tuple_t a, tuple_t b)
{
	if (equal(a.x, b.x) && equal(a.y, b.y) && equal(a.z, b.z) && equal(a.w, b.w))
		return (true);
	return (false);
}

tuple_t	addtup(tuple_t tuple_a, tuple_t tuple_b)
{
	tuple_t	sum_tuple;

	sum_tuple.x = tuple_a.x + tuple_b.x;
	sum_tuple.y = tuple_a.y + tuple_b.y;
	sum_tuple.z = tuple_a.z + tuple_b.z;
	sum_tuple.w = tuple_a.w + tuple_b.w;
	return (sum_tuple);
}