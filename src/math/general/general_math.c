#include <stdbool.h>
#include "../../../include/rt.h"

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

