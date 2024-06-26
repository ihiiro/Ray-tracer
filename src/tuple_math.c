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
	return (tuple(tuple_a.x + tuple_b.x,
				  tuple_a.y + tuple_b.y,
				  tuple_a.z + tuple_b.z,
				  tuple_a.w + tuple_b.w));
}

tuple_t	subtup(tuple_t tuple_a, tuple_t tuple_b)
{
	return (tuple(tuple_a.x - tuple_b.x,
				  tuple_a.y - tuple_b.y,
				  tuple_a.z - tuple_b.z,
				  tuple_a.w - tuple_b.w));
}

tuple_t	negtup(tuple_t t)
{
	return (tuple(-t.x,
				  -t.y,
				  -t.z,
				  -t.w));
}