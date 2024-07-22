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
	return (vector(v.x / vec_magnitude(v),
				   v.y / vec_magnitude(v),
				   v.z / vec_magnitude(v)));
}
