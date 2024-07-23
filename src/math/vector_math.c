#include <math.h>
#include "../../include/rt.h"

double	vec_magnitude(tuple_t v)
{
	return (sqrt(pow(v.x, 2)
			   + pow(v.y, 2)
			   + pow(v.z, 2)
			   + pow(v.w, 2)));
}

tuple_t	vec_normalize(tuple_t v)
{
	double	magnitude;

	magnitude = vec_magnitude(v);
	if (!magnitude)
		magnitude = 1;
	return (vector(v.x / magnitude,
				   v.y / magnitude,
				   v.z / magnitude));
}

double	vec_dot(tuple_t va, tuple_t vb)
{
	return (va.x * vb.x
		  + va.y * vb.y
		  + va.z * vb.z
		  + va.w * vb.w);
}

tuple_t	vec_cross(tuple_t va, tuple_t vb)
{
	return (vector(va.y * vb.z - va.z * vb.y,
				   va.z * vb.x - va.x * vb.z,
				   va.x * vb.y - va.y * vb.x));
}
