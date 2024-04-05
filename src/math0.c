#include <stdbool.h>
#include "../include/rt.h"

double	absd(double a)
{
	if (a < 0)
		return (-a);
	return (a);
}

bool	equal(double a, double b)
{
	if (absd(a - b) < EPSILON)
		return (true);
	return (false);
}

bool	equaltup(tuple_t a, tuple_t b)
{
	if (equal(a.x, b.x) && equal(a.y, b.y) && equal(a.z, b.z) && equal(a.w, b.w))
		return (true);
	return (false);
}