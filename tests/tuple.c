#include <assert.h>
#include <stdio.h>
#include "../include/rt.h"

int	main(void)
{
	tuple_t	tuple;
	tuple_t	tuple1;
	tuple_t	tuple2;

	tuple.x = 4.3;
	tuple.y = -4.2;
	tuple.z = 3.1;
	tuple.w = 1.0;
	assert(equal(tuple.x, 4.3));
	assert(equal(tuple.y, -4.2));
	assert(equal(tuple.z, 3.1));
	assert(equal(tuple.w, 1.0));
	printf("Point tuple tests passed.\n");
	tuple.w = 0.0;
	assert(equal(tuple.x, 4.3));
	assert(equal(tuple.y, -4.2));
	assert(equal(tuple.z, 3.1));
	assert(equal(tuple.w, 0.0));
	printf("Vector tuple tests passed.\n");
	tuple = point(4, -4, 3);
	assert(equal(tuple.x, 4));
	assert(equal(tuple.y, -4));
	assert(equal(tuple.z, 3));
	assert(equal(tuple.w, 1));
	printf("point() makes a point tests passed.\n");
	tuple = vector(4, -4, 3);
	assert(equal(tuple.x, 4));
	assert(equal(tuple.y, -4));
	assert(equal(tuple.z, 3));
	assert(equal(tuple.w, 0));
	printf("vector() makes a vector tests passed.\n");
	tuple.x = 3;
	tuple.y = -2;
	tuple.z = 5;
	tuple.w = 1;
	tuple1.x = -2;
	tuple1.y = 3;
	tuple1.z = 1;
	tuple1.w = 0;
	tuple2.x = 1;
	tuple2.y = 1;
	tuple2.z = 6;
	tuple2.w = 1;
	assert(equaltup(addtup(tuple, tuple1), tuple2));
	printf("addtup() returns the sum tuple of two tuples tests passed.\n");
}