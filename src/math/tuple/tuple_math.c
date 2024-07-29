#include <stdbool.h>
#include "../../../include/rt.h"

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

tuple_t	mult_by_scalar(tuple_t t, double scalar)
{
	return (tuple(t.x * scalar,
				  t.y * scalar,
				  t.z * scalar,
				  t.w * scalar));
}

tuple_t	div_by_scalar(tuple_t t, double scalar)
{
	return (tuple(t.x / scalar,
				  t.y / scalar,
				  t.z / scalar,
				  t.w / scalar));
}

tuple_t	multup(tuple_t a, tuple_t b)
{
	return (tuple(a.x * b.x,
				  a.y * b.y,
				  a.z * b.z,
				  a.w * b.w));
}
