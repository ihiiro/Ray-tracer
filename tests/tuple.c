#include <assert.h>
#include <stdio.h>
#include "../include/rt.h"

int	main(void)
{
	tuple_t	tuple;

	tuple.x = 4.3;
	tuple.y = -4.2;
	tuple.z = 3.1;
	tuple.w = 1.0;
	assert(tuple.x == 4.3);
	assert(tuple.y == -4.2);
	assert(tuple.z == 3.1);
	assert(tuple.w == 1.0);
	printf("Point tuple tests passed.\n");
	tuple.w = 0.0;
	assert(tuple.x == 4.3);
	assert(tuple.y == -4.2);
	assert(tuple.z == 3.1);
	assert(tuple.w == 0.0);
	printf("Vector tuple tests passed.\n");
	tuple = point(4, -4, 3);
	assert(tuple.x == 4);
	assert(tuple.y == -4);
	assert(tuple.z == 3);
	assert(tuple.w == 1.0);
	printf("point() makes a point tests passed.\n");
	tuple = vector(4, -4, 3);
	assert(tuple.x == 4);
	assert(tuple.y == -4);
	assert(tuple.z == 3);
	assert(tuple.w == 0.0);
	printf("vector() makes a vector tests passed.\n");
}