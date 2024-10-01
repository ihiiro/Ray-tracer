/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:47:12 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/01 20:39:50 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <libc.h>
#include "../data_structs/data_structs.h"
#include "../data_structs/data_funcs.h"
#include "../maths/maths.h"
#include <math.h>
#include "../MLX/MLX42.h"
#include <limits.h>

#define WIDTH 400
#define HEIGHT 400

int main()
{
	/* TUPLES TESTS */
	t_tuple a = return_tuple(4.3, -4.2, 3.1, POINT);
	assert(a.x == 4.3);
	assert(a.y == -4.2);
	assert(a.z == 3.1);
	assert(a.w == POINT);
	assert(point_or_vector(a) == POINT);
	a = return_tuple(4.3, -4.2, 3.1, VECTOR);
	assert(point_or_vector(a) == VECTOR);
	/* VECTOR/POINT TESTS */
	a = point(4.3, -4.2, 3.1);
	assert(a.x == 4.3);
	assert(a.y == -4.2);
	assert(a.z == 3.1);
	assert(a.w == POINT);
	a = vector(4.3, -4.2, 3.1);
	assert(a.x == 4.3);
	assert(a.y == -4.2);
	assert(a.z == 3.1);
	assert(a.w == VECTOR);
	/* TUPLE ARITHMETIC TESTS */
	a = vector(3, -2, 5); // addition
	t_tuple b = point(-2, 3, 1);
	t_tuple sum_a_b = add_tuples(a, b);
	assert(equal_tuple(sum_a_b, point(1, 1, 6)));
	a = point(3, 2, 1); // subtraction
	b = point(5, 6, 7);
	t_tuple diff_a_b = sub_tuples(a, b);
	assert(equal_tuple(diff_a_b, vector(-2, -4, -6)));
	b = vector(5, 6, 7);
	diff_a_b = sub_tuples(a, b);
	assert(equal_tuple(diff_a_b, point(-2, -4, -6)));
	a = vector(3, 2, 1);
	b = vector(5, 6, 7);
	diff_a_b = sub_tuples(a, b);
	assert(equal_tuple(diff_a_b, vector(-2, -4, -6)));
	a = vector(1, -2, 3);
	assert(equal_tuple(negate_tuple(a), return_tuple(-1, 2, -3, VECTOR)));
	a = return_tuple(1, -2, 3, -4);
	assert(equal_tuple(scale_tuple(a, 3.5), return_tuple(3.5, -7, 10.5, -14)));
	assert(equal_tuple(scale_tuple(a, 0.5), return_tuple(0.5, -1, 1.5, -2)));
	/* VECTOR MATH TESTS */
	/*Magnitude TESTS*/
	a = vector(1, 0, 0);
	assert(vector_magnitude(a) == 1);
	a = vector(0, 1, 0);
	assert(vector_magnitude(a) == 1);
	a = vector(0, 0, 1);
	assert(vector_magnitude(a) == 1);
	a = vector(1, 2, 3);
	assert(vector_magnitude(a) == sqrt(14));
	a = vector(-1, -2, -3);
	assert(vector_magnitude(a) == sqrt(14));
	/* NORM TESTS */
	a = vector(4, 0, 0);
	assert(equal_tuple(normalize_vec(a), vector(1, 0, 0)));
	a = vector(1, 2, 3);
	assert(equal_tuple(normalize_vec(a), vector(1/sqrt(14), 2/sqrt(14), 3/sqrt(14))));
	assert(vector_magnitude(normalize_vec(a)) == 1);
	/* DOT PRODUCT TESTS */
	a = vector(1, 2, 3);
	b = vector(2, 3, 4);
	assert(vec_dot(a, b) == 20);
	/* CROSS PRODUCT TESTS */
	assert(equal_tuple(vec_cross(a, b), vector(-1, 2, -1)));
	assert(equal_tuple(vec_cross(b, a), vector(1, -2, 1)));
	/* COLOR TESTS */
	a = color(-0.5, 0.4, 1.7);
	assert(equal_tuple(a, vector(-0.5, 0.4, 1.7)));
	/* COLOR ARITHMETIC TESTS */ 
	a = color(0.9, 0.6, 0.75);
	b = color(0.7, 0.1, 0.25);
	assert(equal_tuple(add_colors(a, b), color(1.6, 0.7, 1.0)));
	assert(equal_tuple(sub_colors(a, b), color(0.2, 0.5, 0.5)));
	a = color(0.2, 0.3, 0.4);
	assert(equal_tuple(multiply_color_by_scalar(a, 2), color(0.4, 0.6, 0.8)));
	a = color(1, 0.2, 0.4);
	b = color(0.9, 1, 0.1);
	assert(equal_tuple(multiply_colors(a, b), color(0.9, 0.2, 0.04)));
	/* CANVAS TESTS */
	t_canvas	c = canvas(200, 200);
	assert(c.width == 200 && c.height == 200);
	for (int x = 0; x < 200; x++)
		for (int y = 0; y < 200; y++)
			assert(equal_tuple(c.pixels[x][y].color, color(255, 255, 255)));
	write_pixel(&c, 2, 3, color(255, 0, 0));
	// assert(equal_tuple(*pixel_at(&c, 2, 3), color(255, 0, 0)));
	/* MATRICES TESTS */
	/* 4 by 4 */
	t_matrix *matrix = return_4_by_4_matrix(
		return_tuple(1, 2, 3, 4),
		return_tuple(5.5, 6.5, 7.5, 8.5),
		return_tuple(9, 10, 11, 12),
		return_tuple(13.5, 14.5, 15.5, 16.5)
	);
	assert(matrix[0].x == 1);
	assert(matrix[0].w == 4);
	assert(matrix[1].x == 5.5);
	assert(matrix[1].z == 7.5);
	assert(matrix[2].z == 11);
	assert(matrix[3].x == 13.5);
	assert(matrix[3].z == 15.5);
	/* 2 by 2 */
	matrix = return_2_by_2_matrix(
		return_tuple(-3, 5, 0, 0),
		return_tuple(1, -2, 0, 0)
	);
	assert(matrix[0].x == -3);
	assert(matrix[0].y == 5);
	assert(matrix[1].x == 1);
	assert(matrix[1].y == -2);
	/* 3 by 3 */
	matrix = return_3_by_3_matrix(
		return_tuple(-3, 5, 0, 0),
		return_tuple(1, -2, -7, 0),	
		return_tuple(0, 1, 1, 0)
	);
	assert(matrix[0].x == -3);
	assert(matrix[1].y == -2);
	assert(matrix[2].z == 1);
	/* matrix comparison */
	t_matrix *m0 = return_4_by_4_matrix(
		return_tuple(1, 2, 3, 4),
		return_tuple(5.5, 6.5, 7.5, 8.5),
		return_tuple(9, 10, 12, 12),
		return_tuple(13.5, 14.5, 15.5, 16.5)
	);
	t_matrix *m1 = return_4_by_4_matrix(
		return_tuple(1, 2, 3, 4),
		return_tuple(5.5, 6.5, 7.53, 8.5),
		return_tuple(9, 10, 12, 12),
		return_tuple(13.5, 14.5, 15.5, 16.5)
	);
	assert(equal_matrices(m0, m1, 4) == 0);
	assert(equal_matrices(m1, m1, 4) == 1);
	matrix = return_2_by_2_matrix(
		return_tuple(-3, 5, 0, 0),
		return_tuple(1, -2, 0, 0)
	);
	/* MATRIX MULTIPLICATION */
	matrix = matrix_multiply(m0, m0, 4);
	assert(matrix[0].x == 93 && matrix[0].y == 103 && matrix[0].z == 116 && matrix[0].w == 123);
	assert(matrix[1].x == 223.5 && matrix[1].y == 251.5 && matrix[1].z == 287 && matrix[1].w == 307.5);
	assert(matrix[2].x == 334 && matrix[2].y == 377 && matrix[2].z == 432 && matrix[2].w == 463);
	assert(matrix[3].x == 455.5 && matrix[3].y == 515.5 && matrix[3].z == 591 && matrix[3].w == 635.5);
	/* MATRIX * TUPLE */
	m1 = return_4_by_4_matrix(
		return_tuple(1, 2, 3, 4),
		return_tuple(2, 4, 4, 2),
		return_tuple(8, 6, 4, 1),
		return_tuple(0, 0, 0, 1)
	);
	t_tuple t = multiply_matrix_by_tuple(m1, return_tuple(1, 2, 3, 1));
	assert(t.x == 18 && t.y == 24 && t.z == 33 && t.w == 1);
	/* IDENTITY MATRIX */
	/* matrix * id matrix */
	m0 = return_4_by_4_matrix(
		return_tuple(1, 0, 0, 0),
		return_tuple(0, 1, 0, 0),
		return_tuple(0, 0, 1, 0),
		return_tuple(0, 0, 0, 1)
	);
	matrix = matrix_multiply(m1, m0, 4);
	assert(matrix[0].x == 1 && matrix[0].y == 2 && matrix[0].z == 3 && matrix[0].w == 4);
	assert(matrix[1].x == 2 && matrix[1].y == 4 && matrix[1].z == 4 && matrix[1].w == 2);
	assert(matrix[2].x == 8 && matrix[2].y == 6 && matrix[2].z == 4 && matrix[2].w == 1);
	assert(matrix[3].x == 0 && matrix[3].y == 0 && matrix[3].z == 0 && matrix[3].w == 1);
	/* matrix * tuple */
	t = return_tuple(1, 2, 3, 4);
	t = multiply_matrix_by_tuple(m0, t);
	assert(t.x == 1 && t.y == 2 && t.z == 3 && t.w == 4);
	/* TRANSPOSING MATRICES */
	m1 = matrix_transpose(m1, 4);
	assert(m1[0].x == 1 && m1[0].y == 2 && m1[0].z == 8 && m1[0].w == 0);
	assert(m1[1].x == 2 && m1[1].y == 4 && m1[1].z == 6 && m1[1].w == 0);
	assert(m1[2].x == 3 && m1[2].y == 4 && m1[2].z == 4 && m1[2].w == 0);
	assert(m1[3].x == 4 && m1[3].y == 2 && m1[3].z == 1 && m1[3].w == 1);
	/* transpose id matrix */
	m0 = matrix_transpose(m0, 4);
	assert(m0[0].x == 1 && m0[0].y == 0 && m0[0].z == 0 && m0[0].w == 0);
	assert(m0[1].x == 0 && m0[1].y == 1 && m0[1].z == 0 && m0[1].w == 0);
	assert(m0[2].x == 0 && m0[2].y == 0 && m0[2].z == 1 && m0[2].w == 0);
	assert(m0[3].x == 0 && m0[3].y == 0 && m0[3].z == 0 && m0[3].w == 1);
	/* INVERTING MATRICES */
	matrix = return_2_by_2_matrix(return_tuple(1, 5, 0, 0), return_tuple(-3, 2, 0, 0));
	assert(determinant_2x2_matrix(matrix) == 17);
	/* SUBMATRIX TESTS */
	matrix = return_3_by_3_matrix(
		return_tuple(1, 5, 0, 0),
		return_tuple(-3, 2, 7, 0),	
		return_tuple(0, 6, -3, 0)
	);
	matrix = submatrix(matrix, 0, 2, 3);
	assert(matrix[0].x == -3 && matrix[0].y == 2 && matrix[0].z == 0 && matrix[0].w == 0);
	assert(matrix[1].x == 0 && matrix[1].y == 6  && matrix[1].z == 0 && matrix[1].w == 0);
	m0 = return_4_by_4_matrix(
		return_tuple(-6, 1, 1, 6),
		return_tuple(-8, 5, 8, 6),
		return_tuple(-1, 0, 8, 2),
		return_tuple(-7, 1, -1, 1)
	);
	m0 = submatrix(m0, 2, 1, 4);
	assert(m0[0].x == -6 && m0[0].y == 1 && m0[0].z == 6 && m0[0].w == 0);
	assert(m0[1].x == -8 && m0[1].y == 8 && m0[1].z == 6 && m0[1].w == 0);
	assert(m0[2].x == -7 && m0[2].y == -1 && m0[2].z == 1 && m0[2].w == 0);
	/* MATRIX MINOR TESTS */
	matrix = return_3_by_3_matrix(
		return_tuple(3, 5, 0, 0),
		return_tuple(2, -1, -7, 0),
		return_tuple(6, -1, 5, 0)
	);
	double MINOR = matrix_3_by_3_minor(matrix, 1, 0);
	assert(MINOR == 25);
	double COFACTOR = matrix_3_by_3_minor(matrix, 0, 0);
	assert(COFACTOR == -12);
	COFACTOR = matrix_cofactor(matrix, 1, 0, 3);
	assert(COFACTOR == -25);
	/* 3 by 3 determinant */
	matrix = return_3_by_3_matrix(
		return_tuple(1, 2, 6, 0),
		return_tuple(-5, 8, -4, 0),
		return_tuple(2, 6, 4, 0)
	);
	double DETERMINANT_3_BY_3 = matrix_determinant(matrix, 3);
	assert(DETERMINANT_3_BY_3 == -196);
	/* 4 by 4 determinant */
	matrix = return_4_by_4_matrix(
		return_tuple(-2, -8, 3, 5),
		return_tuple(-3, 1, 7, 3),
		return_tuple(1, 2, -9, 6),
		return_tuple(-6, 7, 7, -9)
	);
	double DETERMINANT_4X4 = matrix_determinant(matrix, 4);
	assert(DETERMINANT_4X4 == -4071);

	/* 5 * 2 = 10 => 10 * 1/5 = 2 but for matrices */
	matrix = return_4_by_4_matrix(
		return_tuple(-5, 2, 6, -8),
		return_tuple(1, -5, 1, 8),
		return_tuple(7, 7, -6, -7),
		return_tuple(1, -3, 7, 4)
	);
	// matrix = invert_matrix(matrix, 4); tested before OK (omitted because of precision errors)
	t_matrix *A = return_4_by_4_matrix(
		return_tuple(3, -9, 7, 3),
		return_tuple(3, -8, 2, -9),
		return_tuple(-4, 4, 4, 1),
		return_tuple(-6, 5, -1, 1)
	);
	t_matrix *B = return_4_by_4_matrix(
		return_tuple(8, 2, 2, 2),
		return_tuple(3, -1, 7, 0),
		return_tuple(7, 0, 5, 4),
		return_tuple(6, -2, 0, 5)
	);
	t_matrix *C = matrix_multiply(A, B, 4);
	t_matrix *SHOULD_BE_A = matrix_multiply(C, invert_matrix(B, 4), 4);
	assert(equal(SHOULD_BE_A[0].x , 3) && equal(SHOULD_BE_A[0].y , -9) && equal(SHOULD_BE_A[0].z , 7) && equal(SHOULD_BE_A[0].w , 3));
	assert(equal(SHOULD_BE_A[1].x , 3) && equal(SHOULD_BE_A[1].y , -8) && equal(SHOULD_BE_A[1].z , 2) && equal(SHOULD_BE_A[1].w , -9));
	assert(equal(SHOULD_BE_A[2].x , -4) && equal(SHOULD_BE_A[2].y , 4) && equal(SHOULD_BE_A[2].z , 4) && equal(SHOULD_BE_A[2].w , 1));
	assert(equal(SHOULD_BE_A[3].x , -6) && equal(SHOULD_BE_A[3].y , 5) && equal(SHOULD_BE_A[3].z , -1) && equal(SHOULD_BE_A[3].w , 1));
	/* MATRIX TRANSFORMATION (TRANSLATION) */
	/* points */
	a = return_tuple(-3, 4, 5, POINT);
	A = translation(5, -3, 2);
	b = multiply_matrix_by_tuple(A, a);
	t_tuple result = return_tuple(2, 1, 7, POINT);
	assert(equal_tuple(b, result));
	a = return_tuple(-3, 4, 5, POINT);
	A = translation(5, -3, 2);
	b = multiply_matrix_by_tuple(invert_matrix(A, 4), a);
	result = return_tuple(-8, 7, 3, POINT);
	assert(equal_tuple(b, result));
	/* vectors */
	a = return_tuple(-3, 4, 5, VECTOR);
	A = translation(5, -3, 2);
	b = multiply_matrix_by_tuple(A, a);
	assert(equal_tuple(a, b));
	/*scaling */
	/* points */
	a = return_tuple(-4, 6, 8, POINT);
	A = scaling(2, 3, 4);
	b = multiply_matrix_by_tuple(A, a);
	result = return_tuple(-8, 18, 32, POINT);
	assert(equal_tuple(b, result));
	/* vectors */
	a = return_tuple(-4, 6, 8, VECTOR);
	A = scaling(2, 3, 4);
	b = multiply_matrix_by_tuple(A, a);
	result = return_tuple(-8, 18, 32, VECTOR);
	assert(equal_tuple(b, result));
	/*inverse*/
	a = return_tuple(-4, 6, 8, VECTOR);
	A = scaling(2, 3, 4);
	b = multiply_matrix_by_tuple(invert_matrix(A, 4), a);
	result = return_tuple(-2, 2, 2, VECTOR);
	assert(equal_tuple(b, result));
	/*negative scalingL: Reflection */
	a = return_tuple(2, 3, 4, POINT);
	A = scaling(-1, 1, 1);
	b = multiply_matrix_by_tuple(A, a);
	result = return_tuple(-2, 3, 4, POINT);
	assert(equal_tuple(b, result));
	/*Rotaion On X axis*/
	t_tuple p = return_tuple(0, 1, 0, POINT);
	t_matrix *half_quarter = rotation_x(M_PI/4);
	t_matrix *full_quarter = rotation_x(M_PI/2);
	t_tuple point2 = multiply_matrix_by_tuple(half_quarter, p);
	assert(equal_tuple(point2, return_tuple(0, sqrt(2)/2, sqrt(2)/2, POINT)));
	point2 = multiply_matrix_by_tuple(full_quarter, p);
	assert(equal_tuple(point2, return_tuple(0, 0, 1, POINT)));
	/*Inverse Rotaion On X axis*/
	p = return_tuple(0, 1, 0, POINT);
	half_quarter = rotation_x(M_PI/4);
	t_matrix *inv = invert_matrix(half_quarter, 4);
	point2 = multiply_matrix_by_tuple(inv, p);
	assert(equal_tuple(point2, return_tuple(0, sqrt(2)/2, -sqrt(2)/2, POINT)));
	/*Rotaion On Y axis*/
	p = return_tuple(0, 0, 1, POINT);
	half_quarter = rotation_y(M_PI/4);
	full_quarter = rotation_y(M_PI/2);
	point2 = multiply_matrix_by_tuple(half_quarter, p);
	assert(equal_tuple(point2, return_tuple(sqrt(2)/2, 0, sqrt(2)/2, POINT)));
	point2 = multiply_matrix_by_tuple(full_quarter, p);
	assert(equal_tuple(point2, return_tuple(1, 0, 0, POINT)));
	/*Rotaion On Z axis*/
	p = return_tuple(0, 1, 0, POINT);
	half_quarter = rotation_z(M_PI/4);
	full_quarter = rotation_z(M_PI/2);
	point2 = multiply_matrix_by_tuple(half_quarter, p);
	assert(equal_tuple(point2, return_tuple(-sqrt(2)/2, sqrt(2)/2, 0, POINT)));
	point2 = multiply_matrix_by_tuple(full_quarter, p);
	assert(equal_tuple(point2, return_tuple(-1, 0, 0, POINT)));
	/*Shearing*/
	t_shear shear = fill_shear(return_tuple(0, 0, 0, 0), return_tuple(0, 0, 1, 0));
	t_matrix	*transform = shearing(shear);
	p = return_tuple(2, 3, 4, POINT);
	point2 = multiply_matrix_by_tuple(transform, p);
	assert(equal_tuple(point2, return_tuple(2, 3, 7, POINT)));
	/*Chaining Transformations*/
	/* individually */
	p = return_tuple(1, 0, 1, POINT);
	A = rotation_x(M_PI/2);
	B = scaling(5, 5, 5);
	C = translation(10, 5, 7);
	p = multiply_matrix_by_tuple(A, p);
	assert(equal_tuple(p, return_tuple(1, -1, 0, POINT)));
	p = multiply_matrix_by_tuple(B, p);
	assert(equal_tuple(p, return_tuple(5, -5, 0, POINT)));
	p = multiply_matrix_by_tuple(C, p);
	assert(equal_tuple(p, return_tuple(15, 0, 7, POINT)));
	/* chained */
	p = return_tuple(1, 0, 1, POINT);
	matrix = matrix_multiply(matrix_multiply(C, B, 4), A, 4);
	p = multiply_matrix_by_tuple(matrix, p);
	assert(equal_tuple(p, return_tuple(15, 0, 7, POINT)));
	/* RAY CASTING */
	t_ray r;
	r = return_ray(point(1, 2, 3), vector(4, 5, 6));
	assert(equal_tuple(r.origin, point(1, 2, 3)) && equal_tuple(r.direction, vector(4, 5, 6)));
	/*Position*/
	r = return_ray(point(2, 3, 4), vector(1, 0, 0));
	assert(equal_tuple(position(r, 0), point(2, 3, 4)));
	assert(equal_tuple(position(r, 1), point(3, 3, 4)));
	assert(equal_tuple(position(r, -1), point(1, 3, 4)));
	assert(equal_tuple(position(r, 2.5), point(4.5, 3, 4)));
	/* RAY SPHERE INTERSECTION TESTS */
	/* t0 != t1 (two intersections) */
	r = return_ray(point(0, 0, -5), vector(0, 0, 1));
	t_sphere s = sphere(0);
	t_xs xs = sphere_intersect(&s, r);
	assert(xs.count == 2 && equal(xs.t0, 4.0) && equal(xs.t1, 6.0) && (t_sphere *)xs.object0 == &s && (t_sphere *)xs.object1 == &s);
	/* t0 == t1 (intersection is tangent to sphere) */
	r = return_ray(point(0, 1, -5), vector(0, 0, 1));
	s = sphere(0);
	xs = sphere_intersect(&s, r);
	assert(xs.count == 2 && equal(xs.t0, 5.0) && equal(xs.t1, 5.0) && (t_sphere *)xs.object0 == &s && (t_sphere *)xs.object1 == &s);
	/* a miss (no intersections at all) */
	r = return_ray(point(0, 2, -5), vector(0, 0, 1));
	s = sphere(0);
	xs = sphere_intersect(&s, r);
	assert(xs.count == 0 && equal(xs.t0, 0.0) && equal(xs.t1, 0.0) && (t_sphere *)xs.object0 == NULL && (t_sphere *)xs.object1 == NULL);
	/* ray's origin == sphere's origin */
	r = return_ray(point(0, 0, 0), vector(0, 0, 1));
	s = sphere(0);
	xs = sphere_intersect(&s, r);
	assert(xs.count == 2 && equal(xs.t0, -1.0) && equal(xs.t1, 1.0) && (t_sphere *)xs.object0 == &s && (t_sphere *)xs.object1 == &s);
	/* ray's origin > sphere's origin */
	r = return_ray(point(0, 0, 5), vector(0, 0, 1));
	s = sphere(0);
	xs = sphere_intersect(&s, r);
	assert(xs.count == 2 && equal(xs.t0, -6.0) && equal(xs.t1, -4.0) && (t_sphere *)xs.object0 == &s && (t_sphere *)xs.object1 == &s);
	/* RAY-OBJECT INTERSECTION RECORD TESTS */
	s = sphere(0);
	t_intersection i = {0, 3.5, &s};
	assert(equal(i.t, 3.5) && (t_sphere *)i.object == &s);
	/* sphere_intersect() sets the objects */
	r = return_ray(point(0, 0, -5), vector(0, 0, 1));
	s = sphere(0);
	xs = sphere_intersect(&s, r);
	assert(xs.count == 2 && (t_sphere *)xs.object0 == &s && (t_sphere *)xs.object1 == &s);
	/* HIT TESTS */
	/* The hit, when all intersections have positive t */
	s = sphere(0);
	t_intersection intersections[4];
	intersections[0].atom_count = 2;
	intersections[0].object = &s;
	intersections[0].t = 1;
	intersections[1].object = &s;
	intersections[1].t = 2;
	t_intersection closest_intersection = hit(intersections);
	assert(equal(closest_intersection.t, 1) && closest_intersection.object == &s);
	/* The hit, when some intersections have negative t */
	s = sphere(0);
	intersections[0].atom_count = 2;
	intersections[0].object = &s;
	intersections[0].t = -1;
	intersections[1].object = &s;
	intersections[1].t = 1;
	closest_intersection = hit(intersections);
	assert(equal(closest_intersection.t, 1) && closest_intersection.object == &s);
	/* The hit, when all intersections have negative t */
	s = sphere(0);
	intersections[0].atom_count = 2;
	intersections[0].object = &s;
	intersections[0].t = -2;
	intersections[1].object = &s;
	intersections[1].t = -1;
	closest_intersection = hit(intersections);
	assert(equal(closest_intersection.t, INT_MAX) && closest_intersection.object == &s); // NO HIT
	/* The hit is always the lowest nonnegative intersection */
	s = sphere(0);
	intersections[0].atom_count = 4;
	intersections[0].object = &s;
	intersections[0].t = 5;
	intersections[1].object = &s;
	intersections[1].t = 7;
	intersections[2].object = &s;
	intersections[2].t = -3;
	intersections[3].object = &s;
	intersections[3].t = 2;
	closest_intersection = hit(intersections);
	assert(equal(closest_intersection.t, 2) && closest_intersection.object == &s);
	/*Transforming Sphere With Ray*/
	r = return_ray(point(1, 2, 3), vector(0, 1, 0));
	m0 = translation(3, 4, 5);
	t_ray r2 = transform_ray(r, m0);
	assert(equal_tuple(r2.origin, point(4, 6, 8)) && equal_tuple(r2.direction, vector(0, 1, 0)));
	r = return_ray(point(1, 2, 3), vector(0, 1, 0));
	m0 = scaling(2, 3, 4);
	r2 = transform_ray(r, m0);
	assert(equal_tuple(r2.origin, point(2, 6, 12)) && equal_tuple(r2.direction, vector(0, 3, 0)));
	t_sphere sp = sphere(0);
	m0 = translation(2, 3, 4);
	set_transform(&sp, m0);
	assert(equal_matrices(sp.transform, m0, 4));
	/*Intersecting a scaled sphere with a ray*/
	r = return_ray(point(0, 0, -5), vector(0, 0, 1));
	sp = sphere(1);
	m0 = scaling(2, 2, 2);
	set_transform(&sp,  m0);
	assert(equal_matrices(sp.transform, m0, 4));
	xs = sphere_intersect(&sp, r);
	assert(xs.count == 2 && equal(xs.t0, 3) && equal(xs.t1, 7));
	/*Intersecting a translated sphere with a ray*/
	r = return_ray(point(0, 0, -5), vector(0, 0, 1));
	sp = sphere(1);
	m0 = translation(5, 0, 0);
	set_transform(&sp,  m0);
	assert(equal_matrices(sp.transform, m0, 4));
	xs = sphere_intersect(&sp, r);
	assert(xs.count == 0);
	/* SURFACE NORMALS */
	/* normal at x axis */
	s = sphere(0);
	t_tuple n = normal_at(s, point(1, 0, 0));
	assert(equal_tuple(n, vector(1, 0, 0)));
	/* normal at y axis */
	s = sphere(0);
	n = normal_at(s, point(0, 1, 0));
	assert(equal_tuple(n, vector(0, 1, 0)));
	/* normal at z axis */
	s = sphere(0);
	n = normal_at(s, point(0, 0, 1));
	assert(equal_tuple(n, vector(0, 0, 1)));
	/* normal at nonaxial point */
	s = sphere(0);
	n = normal_at(s, point(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3));
	assert(equal_tuple(n, vector(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3)));
	/* The normal is a normalized vector */
	s = sphere(0);
	n = normal_at(s, point(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3));
	assert(equal_tuple(n, normalize_vec(n)));
	/* Computing the normal on a translated sphere */
	s = sphere(0);
	s.transform = translation(0, 1, 0);
	n = normal_at(s, point(0, 1.70711, -0.70711));
	assert(equal_tuple(n, vector(0, 0.70711, -0.70711)));
	/* normal of a rotated and scaled sphere */
	s = sphere(0);
	s.transform = matrix_multiply(scaling(1, .5, 1), rotation_z(M_PI / 5), 4);
	n = normal_at(s, point(0, sqrt(2)/2, -sqrt(2)/2));
	assert(equal_tuple(n, vector(0, 0.97014, -0.24254)));
	/*Reflection*/
	/* 45 degree vector */
	t_tuple v = vector(1, -1, 0);
	t_tuple normal = vector(0, 1, 0);
	t_tuple reflection = reflect(v, normal);
	assert(equal_tuple(reflection, vector(1, 1, 0)));
	v = vector(0, -1, 0);
	normal = vector(sqrt(2)/2, sqrt(2)/2, 0);
	reflection = reflect(v, normal);
	assert(equal_tuple(reflection, vector(1, 0, 0)));
	/*Phong Model */
	/*Point Light*/
	t_tuple intensity = color(1, 1, 1);
	t_tuple	pos = point(0, 0, 0);
	t_light	light = point_light(pos, intensity);
	assert(equal_tuple(light.intensity, intensity) && equal_tuple(light.position, pos));
	/* MATERIALS */
	t_material m = material();
	assert(equal_tuple(m.color, color(1, 1, 1)));
	assert(equal(m.ambient, 0.1));
	assert(equal(m.diffuse, 0.9));
	assert(equal(m.specular, 0.9));
	assert(equal(m.shininess, 200.0));
	/* a sphere has a default material */
	s = sphere(0);
	m = s.material;
	assert(equal_tuple(m.color, color(1, 1, 1)));
	assert(equal(m.ambient, 0.1));
	assert(equal(m.diffuse, 0.9));
	assert(equal(m.specular, 0.9));
	assert(equal(m.shininess, 200.0));
	/* A sphere may be assigned a material */
	s = sphere(0);
	m = material();
	m.ambient = 1;
	s.material = m;
	assert(equal_tuple(m.color, color(1, 1, 1)));
	assert(equal(m.ambient, 1));
	assert(equal(m.diffuse, 0.9));
	assert(equal(m.specular, 0.9));
	assert(equal(m.shininess, 200.0));
	/* Lighting with the eye between the light and the surface */
	m = material();
	pos = point(0, 0, 0);
	t_tuple eyev = vector(0, 0, -1);
	t_tuple normalv = vector(0, 0, -1);
	light = point_light(point(0, 0, -10), color(1, 1, 1));
	t_lighting l = {m, light, pos, eyev, normalv};
	t_tuple final_color_intensity = lighting(l);
	assert(equal_tuple(final_color_intensity, color(1.9, 1.9, 1.9)));
	/* Lighting with the eye between light and surface, eye offset 45° */
	m = material();
	pos = point(0, 0, 0);
	eyev = vector(0, sqrt(2)/2, -sqrt(2)/2);
	normalv = vector(0, 0, -1);
	light = point_light(point(0, 0, -10), color(1, 1, 1));
	t_lighting l1 = {m, light, pos, eyev, normalv};
	final_color_intensity = lighting(l1);
	assert(equal_tuple(final_color_intensity, color(1.0, 1.0, 1.0)));
	/* Lighting with eye opposite surface, light offset 45° */
	m = material();
	pos = point(0, 0, 0);
	eyev = vector(0, 0, -1);
	normalv = vector(0, 0, -1);
	light = point_light(point(0, 10, -10), color(1, 1, 1));
	t_lighting l2 = {m, light, pos, eyev, normalv};
	final_color_intensity = lighting(l2);
	assert(equal_tuple(final_color_intensity, color(0.7364, 0.7364, 0.7364)));
	/* Lighting with eye in the path of the reflection vector */
	m = material();
	pos = point(0, 0, 0);
	eyev = vector(0, -sqrt(2)/2, -sqrt(2)/2);
	normalv = vector(0, 0, -1);
	light = point_light(point(0, 10, -10), color(1, 1, 1));
	t_lighting l3 = {m, light, pos, eyev, normalv};
	final_color_intensity = lighting(l3);
	assert(equal_tuple(final_color_intensity, color(1.6364, 1.6364, 1.6364)));
	/* Lighting with the light behind the surface */
	m = material();
	pos = point(0, 0, 0);
	eyev = vector(0, 0, -1);
	normalv = vector(0, 0, -1);
	light = point_light(point(0, 0, 10), color(1, 1, 1));
	t_lighting l4 = {m, light, pos, eyev, normalv};
	final_color_intensity = lighting(l4);
	assert(equal_tuple(final_color_intensity, color(.1, .1, .1)));
	/* The default world TESTS */
	t_world	*world0 = parse("test_cfiles/test0.rt");
	assert(equal_tuple(world0->lights_list->color, color(255, 255, 255)));
	assert(equal(world0->lights_list->intensity, 1));
	assert(equal_tuple(world0->lights_list->pos, point(-10, 10, -10)) && !world0->lights_list->next);
	assert(world0->objects_list && world0->objects_list->next && !world0->objects_list->next->next);
	/* interset world */
	r = return_ray(point(0, 0, -5), vector(0, 0, 1));
	t_xs_list	*xs_list = intersect_world(world0, r);
	assert(xs_list->count == 4);
	for (t_xs_list *tmp = xs_list; tmp; tmp = tmp->next)
		printf("t=%f object=%p form=%d\n", tmp->t, tmp->object.object, tmp->object.form);
	// assert(xs_list->t == 4);
	// assert(xs_list->next->t == 4.5);
	// assert(xs_list->next->next->t == 5.5);
	// assert(xs_list->next->next->next->t == 6);

	/*  to remove */


	// t_canvas c1 = canvas(WIDTH, WIDTH);
    // mlx_t *mlx = mlx_init(WIDTH, WIDTH, "sphere", false);
    // mlx_image_t *img = mlx_new_image(mlx, WIDTH, WIDTH);
    // t_ray ray = return_ray(point(0, 0, -5), vector(0, 0, 1));
    // double wall_z = 10;
    // double wall_size = 7;
    // double half = wall_size/2;
    // double pixel_size = wall_size / WIDTH;
    // t_sphere s1 = sphere(1);
	// s1.material = material();
	// s1.material.color = color(1, 0.2, 1);
	// t_light LIGHT = point_light(point(0, 0, 10), color(1, 1, 1));


	

    // for(int i = 0; i < WIDTH; i++)
    // {
    //     double world_y = half - pixel_size * i;
    //     for(int j = 0; j < WIDTH ; j++)
    //     {
    //         double world_x = -half + pixel_size * j;
    //         t_tuple pos = point(world_x, world_y, wall_z);
    //         t_ray r = return_ray(ray.origin, normalize_vec(sub_tuples(pos, ray.origin)));
	// 		// s1.transform = matrix_multiply(scaling(.4, 1, 1), identity(), 4);
    //         t_xs xs = sphere_intersect(&s1, r);
	// 		t_intersection inter[2];
	// 		inter[0].atom_count = 2;
	// 		inter[0].t = xs.t0;
	// 		inter[1].t = xs.t1;
    //         if (xs.count > 0)
    //         {
	// 			t_tuple P = position(r, hit(inter).t);
	// 			// printf("%f %f %f\n", P.x, P.y, P.z);
	// 			normalv = normal_at(s1, P);
	// 			eyev = negate_tuple(r.direction);
	// 			t_lighting L = {s1.material, LIGHT, P, eyev, normalv};
	// 			final_color_intensity = lighting(L);
	// 			t_tuple fcl;
	// 			fcl = multiply_color_by_scalar(final_color_intensity, 255);
    //             write_pixel(&c1, i, j, fcl);
    //         }
    //         else
    //             write_pixel(&c1, i, j, color(0, 0, 0));
    //     }
    // }
    // create_canvas(&c1, img, mlx);
    // mlx_loop(mlx);
	
}
