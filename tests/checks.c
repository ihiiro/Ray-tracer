#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "../include/rt.h"

int	main(void)
{
	tuple_t	t;
	tuple_t	tuple1;
	tuple_t	tuple2;
	tuple_t	tuple3;
	double	m;

	t.x = 4.3;
	t.y = -4.2;
	t.z = 3.1;
	t.w = 1.0;
	assert(equal(t.x, 4.3));
	assert(equal(t.y, -4.2));
	assert(equal(t.z, 3.1));
	assert(equal(t.w, 1.0));
	printf("Point tuple\n");

	t.w = 0.0;
	assert(equal(t.x, 4.3));
	assert(equal(t.y, -4.2));
	assert(equal(t.z, 3.1));
	assert(equal(t.w, 0.0));
	printf("Vector tuple\n");

	t = point(4, -4, 3);
	assert(equal(t.x, 4));
	assert(equal(t.y, -4));
	assert(equal(t.z, 3));
	assert(equal(t.w, 1));
	printf("point() makes a point\n");

	t = vector(4, -4, 3);
	assert(equal(t.x, 4));
	assert(equal(t.y, -4));
	assert(equal(t.z, 3));
	assert(equal(t.w, 0));
	printf("vector() makes a vector\n");

	t.x = 3;
	t.y = -2;
	t.z = 5;
	t.w = 1;
	tuple1.x = -2;
	tuple1.y = 3;
	tuple1.z = 1;
	tuple1.w = 0;
	tuple2.x = 1;
	tuple2.y = 1;
	tuple2.z = 6;
	tuple2.w = 1;
	assert(equaltup(addtup(t, tuple1), tuple2));
	printf("addtup() returns the sum tuple of two tuples\n");

	t = point(3, 2 ,1);
	tuple1 = point(5, 6, 7);
	tuple3 = vector(-2, -4, -6);
	tuple2 = subtup(t, tuple1);
	assert(equaltup(tuple2, tuple3));
	printf("\n");
	printf("subtup() {point - point = vector}\n");

	t = point(3, 2, 1);
	tuple1 = vector(5, 6, 7);
	tuple2 = subtup(t, tuple1);
	tuple3 = point(-2, -4, -6);
	assert(equaltup(tuple2, tuple3));
	printf("subtup() {point - vector = point}\n");
	t = vector(3, 2, 1);
	tuple1 = vector(5, 6, 7);
	tuple2 = subtup(t, tuple1);
	tuple3 = vector(-2, -4, -6);
	assert(equaltup(tuple2, tuple3));
	printf("subtup() {vector - vector = vector}\n");

	t = vector(0, 0, 0);
	tuple1 = vector(1, -2, 3);
	tuple2 = subtup(t, tuple1);
	tuple3 = vector(-1, 2, -3);
	assert(equaltup(tuple2, tuple3));
	printf("subtup() {zero vector - vector = vector opposite}\n\n");

	t = tuple(1, -2, 3, -4);
	tuple1 = negtup(t);
	tuple2 = tuple(-1, 2, -3, 4);
	assert(equaltup(tuple1, tuple2));
	printf("negtup() returns the negation tuple of a tuple\n");

	t = tuple(1, -2, 3, -4);
	
	tuple1 = mult_by_scalar(t, 3.5);
	tuple3 = tuple(3.5, -7, 10.5, -14);
	assert(equaltup(tuple3, tuple1));
	tuple2 = mult_by_scalar(t, .5);
	tuple3 = tuple(.5, -1, 1.5, -2);
	assert(equaltup(tuple3, tuple2));
	printf("mult_by_scalar() returns the result of a scalar multiplication\n");

	tuple1 = div_by_scalar(t, 2);
	assert(equaltup(tuple1, tuple3));
	printf("div_by_scalar() returns the result of division by scalar\n");

	m = vec_magnitude(vector(0, 1, 0));
	assert(equal(m, 1.0));
	m = vec_magnitude(vector(0, 0, 1));
	assert(equal(m, 1.0));
	m = vec_magnitude(vector(1, 2, 3));
	assert(equal(m, sqrt(14)));
	m = vec_magnitude(vector(-1, -2, -3));
	assert(equal(m, sqrt(14)));
	printf("vec_magnitude() returns the magnitude of a vector\n");

	assert(equaltup(vec_normalize(vector(4, 0, 0)), vector(1, 0, 0)));
	assert(equaltup(vec_normalize(vector(1, 2, 3)), vector(1/sqrt(14),
		2/sqrt(14), 3/sqrt(14))));
	assert(equal(vec_magnitude(vec_normalize(vector(1, 2, 3))), 1));
	printf("vec_normalize() divides vector components by its magnitude\n");

	tuple1 = vector(1, 2, 3);
	tuple2 = vector(2, 3, 4);
	assert(equal(vec_dot(tuple1, tuple2), 20));
	printf("vec_dot() computes dot product of two vectors\n");

	tuple3 = vec_cross(tuple1, tuple2);
	assert(equaltup(tuple3, vector(-1, 2, -1)));
	tuple3 = vec_cross(tuple2, tuple1);
	assert(equaltup(tuple3, vector(1, -2, 1)));
	printf("vec_cross() returns a perpendicular vector to the two input vectors\n");
}
