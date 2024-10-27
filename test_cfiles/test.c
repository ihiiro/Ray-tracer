/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:47:12 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/27 20:30:45 by yel-yaqi         ###   ########.fr       */
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

#define WIDTH 1100
#define HEIGHT 1100

#define GREEN "\033[0;32m"

void _setcolor_ (char *code) {
  printf("%s", code);
}

void _reset_ () {
  printf("\033[0m");
}

int main()
{
	// _setcolor_(GREEN);
	// printf("testing infrastructure...");
	// _reset_();
	// /* TUPLES TESTS */
	// t_tuple a = return_tuple(4.3, -4.2, 3.1, POINT);
	// assert(a.x == 4.3);
	// assert(a.y == -4.2);
	// assert(a.z == 3.1);
	// assert(a.w == POINT);
	// assert(point_or_vector(a) == POINT);
	// a = return_tuple(4.3, -4.2, 3.1, VECTOR);
	// assert(point_or_vector(a) == VECTOR);
	// /* VECTOR/POINT TESTS */
	// a = point(4.3, -4.2, 3.1);
	// assert(a.x == 4.3);
	// assert(a.y == -4.2);
	// assert(a.z == 3.1);
	// assert(a.w == POINT);
	// a = vector(4.3, -4.2, 3.1);
	// assert(a.x == 4.3);
	// assert(a.y == -4.2);
	// assert(a.z == 3.1);
	// assert(a.w == VECTOR);
	// /* TUPLE ARITHMETIC TESTS */
	// a = vector(3, -2, 5); // addition
	// t_tuple b = point(-2, 3, 1);
	// t_tuple sum_a_b = add_tuples(a, b);
	// assert(equal_tuple(sum_a_b, point(1, 1, 6)));
	// a = point(3, 2, 1); // subtraction
	// b = point(5, 6, 7);
	// t_tuple diff_a_b = sub_tuples(a, b);
	// assert(equal_tuple(diff_a_b, vector(-2, -4, -6)));
	// b = vector(5, 6, 7);
	// diff_a_b = sub_tuples(a, b);
	// assert(equal_tuple(diff_a_b, point(-2, -4, -6)));
	// a = vector(3, 2, 1);
	// b = vector(5, 6, 7);
	// diff_a_b = sub_tuples(a, b);
	// assert(equal_tuple(diff_a_b, vector(-2, -4, -6)));
	// a = vector(1, -2, 3);
	// assert(equal_tuple(negate_tuple(a), return_tuple(-1, 2, -3, VECTOR)));
	// a = return_tuple(1, -2, 3, -4);
	// assert(equal_tuple(scale_tuple(a, 3.5), return_tuple(3.5, -7, 10.5, -14)));
	// assert(equal_tuple(scale_tuple(a, 0.5), return_tuple(0.5, -1, 1.5, -2)));
	// /* VECTOR MATH TESTS */
	// /*Magnitude TESTS*/
	// a = vector(1, 0, 0);
	// assert(vector_magnitude(a) == 1);
	// a = vector(0, 1, 0);
	// assert(vector_magnitude(a) == 1);
	// a = vector(0, 0, 1);
	// assert(vector_magnitude(a) == 1);
	// a = vector(1, 2, 3);
	// assert(vector_magnitude(a) == sqrt(14));
	// a = vector(-1, -2, -3);
	// assert(vector_magnitude(a) == sqrt(14));
	// /* NORM TESTS */
	// a = vector(4, 0, 0);
	// assert(equal_tuple(normalize_vec(a), vector(1, 0, 0)));
	// a = vector(1, 2, 3);
	// assert(equal_tuple(normalize_vec(a), vector(1/sqrt(14), 2/sqrt(14), 3/sqrt(14))));
	// assert(vector_magnitude(normalize_vec(a)) == 1);
	// /* DOT PRODUCT TESTS */
	// a = vector(1, 2, 3);
	// b = vector(2, 3, 4);
	// assert(vec_dot(a, b) == 20);
	// /* CROSS PRODUCT TESTS */
	// assert(equal_tuple(vec_cross(a, b), vector(-1, 2, -1)));
	// assert(equal_tuple(vec_cross(b, a), vector(1, -2, 1)));
	// /* COLOR TESTS */
	// a = color(-0.5, 0.4, 1.7);
	// assert(equal_tuple(a, vector(-0.5, 0.4, 1.7)));
	// /* COLOR ARITHMETIC TESTS */ 
	// a = color(0.9, 0.6, 0.75);
	// b = color(0.7, 0.1, 0.25);
	// assert(equal_tuple(add_colors(a, b), color(1.6, 0.7, 1.0)));
	// assert(equal_tuple(sub_colors(a, b), color(0.2, 0.5, 0.5)));
	// a = color(0.2, 0.3, 0.4);
	// assert(equal_tuple(multiply_color_by_scalar(a, 2), color(0.4, 0.6, 0.8)));
	// a = color(1, 0.2, 0.4);
	// b = color(0.9, 1, 0.1);
	// assert(equal_tuple(multiply_colors(a, b), color(0.9, 0.2, 0.04)));
	// /* CANVAS TESTS */
	// t_canvas	c = canvas(200, 200);
	// assert(c.width == 200 && c.height == 200);
	// for (int x = 0; x < 200; x++)
	// 	for (int y = 0; y < 200; y++)
	// 		assert(equal_tuple(c.pixels[x][y].color, color(255, 255, 255)));
	// write_pixel(&c, 2, 3, color(255, 0, 0));
	// assert(equal_tuple(*pixel_at(&c, 2, 3), color(255, 0, 0)));
	// /* MATRICES TESTS */
	// /* 4 by 4 */
	// t_matrix *matrix = return_4_by_4_matrix(
	// 	return_tuple(1, 2, 3, 4),
	// 	return_tuple(5.5, 6.5, 7.5, 8.5),
	// 	return_tuple(9, 10, 11, 12),
	// 	return_tuple(13.5, 14.5, 15.5, 16.5)
	// );
	// assert(matrix[0].x == 1);
	// assert(matrix[0].w == 4);
	// assert(matrix[1].x == 5.5);
	// assert(matrix[1].z == 7.5);
	// assert(matrix[2].z == 11);
	// assert(matrix[3].x == 13.5);
	// assert(matrix[3].z == 15.5);
	// /* 2 by 2 */
	// matrix = return_2_by_2_matrix(
	// 	return_tuple(-3, 5, 0, 0),
	// 	return_tuple(1, -2, 0, 0)
	// );
	// assert(matrix[0].x == -3);
	// assert(matrix[0].y == 5);
	// assert(matrix[1].x == 1);
	// assert(matrix[1].y == -2);
	// /* 3 by 3 */
	// matrix = return_3_by_3_matrix(
	// 	return_tuple(-3, 5, 0, 0),
	// 	return_tuple(1, -2, -7, 0),	
	// 	return_tuple(0, 1, 1, 0)
	// );
	// assert(matrix[0].x == -3);
	// assert(matrix[1].y == -2);
	// assert(matrix[2].z == 1);
	// /* matrix comparison */
	// t_matrix *m0 = return_4_by_4_matrix(
	// 	return_tuple(1, 2, 3, 4),
	// 	return_tuple(5.5, 6.5, 7.5, 8.5),
	// 	return_tuple(9, 10, 12, 12),
	// 	return_tuple(13.5, 14.5, 15.5, 16.5)
	// );
	// t_matrix *m1 = return_4_by_4_matrix(
	// 	return_tuple(1, 2, 3, 4),
	// 	return_tuple(5.5, 6.5, 7.53, 8.5),
	// 	return_tuple(9, 10, 12, 12),
	// 	return_tuple(13.5, 14.5, 15.5, 16.5)
	// );
	// assert(equal_matrices(m0, m1, 4) == 0);
	// assert(equal_matrices(m1, m1, 4) == 1);
	// matrix = return_2_by_2_matrix(
	// 	return_tuple(-3, 5, 0, 0),
	// 	return_tuple(1, -2, 0, 0)
	// );
	// /* MATRIX MULTIPLICATION */
	// matrix = matrix_multiply(m0, m0, 4);
	// assert(matrix[0].x == 93 && matrix[0].y == 103 && matrix[0].z == 116 && matrix[0].w == 123);
	// assert(matrix[1].x == 223.5 && matrix[1].y == 251.5 && matrix[1].z == 287 && matrix[1].w == 307.5);
	// assert(matrix[2].x == 334 && matrix[2].y == 377 && matrix[2].z == 432 && matrix[2].w == 463);
	// assert(matrix[3].x == 455.5 && matrix[3].y == 515.5 && matrix[3].z == 591 && matrix[3].w == 635.5);
	// /* MATRIX * TUPLE */
	// m1 = return_4_by_4_matrix(
	// 	return_tuple(1, 2, 3, 4),
	// 	return_tuple(2, 4, 4, 2),
	// 	return_tuple(8, 6, 4, 1),
	// 	return_tuple(0, 0, 0, 1)
	// );
	// t_tuple t = multiply_matrix_by_tuple(m1, return_tuple(1, 2, 3, 1));
	// assert(t.x == 18 && t.y == 24 && t.z == 33 && t.w == 1);
	// /* IDENTITY MATRIX */
	// /* matrix * id matrix */
	// m0 = return_4_by_4_matrix(
	// 	return_tuple(1, 0, 0, 0),
	// 	return_tuple(0, 1, 0, 0),
	// 	return_tuple(0, 0, 1, 0),
	// 	return_tuple(0, 0, 0, 1)
	// );
	// matrix = matrix_multiply(m1, m0, 4);
	// assert(matrix[0].x == 1 && matrix[0].y == 2 && matrix[0].z == 3 && matrix[0].w == 4);
	// assert(matrix[1].x == 2 && matrix[1].y == 4 && matrix[1].z == 4 && matrix[1].w == 2);
	// assert(matrix[2].x == 8 && matrix[2].y == 6 && matrix[2].z == 4 && matrix[2].w == 1);
	// assert(matrix[3].x == 0 && matrix[3].y == 0 && matrix[3].z == 0 && matrix[3].w == 1);
	// /* matrix * tuple */
	// t = return_tuple(1, 2, 3, 4);
	// t = multiply_matrix_by_tuple(m0, t);
	// assert(t.x == 1 && t.y == 2 && t.z == 3 && t.w == 4);
	// /* TRANSPOSING MATRICES */
	// m1 = matrix_transpose(m1, 4);
	// assert(m1[0].x == 1 && m1[0].y == 2 && m1[0].z == 8 && m1[0].w == 0);
	// assert(m1[1].x == 2 && m1[1].y == 4 && m1[1].z == 6 && m1[1].w == 0);
	// assert(m1[2].x == 3 && m1[2].y == 4 && m1[2].z == 4 && m1[2].w == 0);
	// assert(m1[3].x == 4 && m1[3].y == 2 && m1[3].z == 1 && m1[3].w == 1);
	// /* transpose id matrix */
	// m0 = matrix_transpose(m0, 4);
	// assert(m0[0].x == 1 && m0[0].y == 0 && m0[0].z == 0 && m0[0].w == 0);
	// assert(m0[1].x == 0 && m0[1].y == 1 && m0[1].z == 0 && m0[1].w == 0);
	// assert(m0[2].x == 0 && m0[2].y == 0 && m0[2].z == 1 && m0[2].w == 0);
	// assert(m0[3].x == 0 && m0[3].y == 0 && m0[3].z == 0 && m0[3].w == 1);
	// /* INVERTING MATRICES */
	// matrix = return_2_by_2_matrix(return_tuple(1, 5, 0, 0), return_tuple(-3, 2, 0, 0));
	// assert(determinant_2x2_matrix(matrix) == 17);
	// /* SUBMATRIX TESTS */
	// matrix = return_3_by_3_matrix(
	// 	return_tuple(1, 5, 0, 0),
	// 	return_tuple(-3, 2, 7, 0),	
	// 	return_tuple(0, 6, -3, 0)
	// );
	// matrix = submatrix(matrix, 0, 2, 3);
	// assert(matrix[0].x == -3 && matrix[0].y == 2 && matrix[0].z == 0 && matrix[0].w == 0);
	// assert(matrix[1].x == 0 && matrix[1].y == 6  && matrix[1].z == 0 && matrix[1].w == 0);
	// m0 = return_4_by_4_matrix(
	// 	return_tuple(-6, 1, 1, 6),
	// 	return_tuple(-8, 5, 8, 6),
	// 	return_tuple(-1, 0, 8, 2),
	// 	return_tuple(-7, 1, -1, 1)
	// );
	// m0 = submatrix(m0, 2, 1, 4);
	// assert(m0[0].x == -6 && m0[0].y == 1 && m0[0].z == 6 && m0[0].w == 0);
	// assert(m0[1].x == -8 && m0[1].y == 8 && m0[1].z == 6 && m0[1].w == 0);
	// assert(m0[2].x == -7 && m0[2].y == -1 && m0[2].z == 1 && m0[2].w == 0);
	// /* MATRIX MINOR TESTS */
	// matrix = return_3_by_3_matrix(
	// 	return_tuple(3, 5, 0, 0),
	// 	return_tuple(2, -1, -7, 0),
	// 	return_tuple(6, -1, 5, 0)
	// );
	// double MINOR = matrix_3_by_3_minor(matrix, 1, 0);
	// assert(MINOR == 25);
	// double COFACTOR = matrix_3_by_3_minor(matrix, 0, 0);
	// assert(COFACTOR == -12);
	// COFACTOR = matrix_cofactor(matrix, 1, 0, 3);
	// assert(COFACTOR == -25);
	// /* 3 by 3 determinant */
	// matrix = return_3_by_3_matrix(
	// 	return_tuple(1, 2, 6, 0),
	// 	return_tuple(-5, 8, -4, 0),
	// 	return_tuple(2, 6, 4, 0)
	// );
	// double DETERMINANT_3_BY_3 = matrix_determinant(matrix, 3);
	// assert(DETERMINANT_3_BY_3 == -196);
	// /* 4 by 4 determinant */
	// matrix = return_4_by_4_matrix(
	// 	return_tuple(-2, -8, 3, 5),
	// 	return_tuple(-3, 1, 7, 3),
	// 	return_tuple(1, 2, -9, 6),
	// 	return_tuple(-6, 7, 7, -9)
	// );
	// double DETERMINANT_4X4 = matrix_determinant(matrix, 4);
	// assert(DETERMINANT_4X4 == -4071);

	// /* 5 * 2 = 10 => 10 * 1/5 = 2 but for matrices */
	// matrix = return_4_by_4_matrix(
	// 	return_tuple(-5, 2, 6, -8),
	// 	return_tuple(1, -5, 1, 8),
	// 	return_tuple(7, 7, -6, -7),
	// 	return_tuple(1, -3, 7, 4)
	// );
	// // matrix = invert_matrix(matrix, 4); tested before OK (omitted because of precision errors)
	// t_matrix *A = return_4_by_4_matrix(
	// 	return_tuple(3, -9, 7, 3),
	// 	return_tuple(3, -8, 2, -9),
	// 	return_tuple(-4, 4, 4, 1),
	// 	return_tuple(-6, 5, -1, 1)
	// );
	// t_matrix *B = return_4_by_4_matrix(
	// 	return_tuple(8, 2, 2, 2),
	// 	return_tuple(3, -1, 7, 0),
	// 	return_tuple(7, 0, 5, 4),
	// 	return_tuple(6, -2, 0, 5)
	// );
	// t_matrix *C = matrix_multiply(A, B, 4);
	// t_matrix *SHOULD_BE_A = matrix_multiply(C, invert_matrix(B, 4), 4);
	// assert(equal(SHOULD_BE_A[0].x , 3) && equal(SHOULD_BE_A[0].y , -9) && equal(SHOULD_BE_A[0].z , 7) && equal(SHOULD_BE_A[0].w , 3));
	// assert(equal(SHOULD_BE_A[1].x , 3) && equal(SHOULD_BE_A[1].y , -8) && equal(SHOULD_BE_A[1].z , 2) && equal(SHOULD_BE_A[1].w , -9));
	// assert(equal(SHOULD_BE_A[2].x , -4) && equal(SHOULD_BE_A[2].y , 4) && equal(SHOULD_BE_A[2].z , 4) && equal(SHOULD_BE_A[2].w , 1));
	// assert(equal(SHOULD_BE_A[3].x , -6) && equal(SHOULD_BE_A[3].y , 5) && equal(SHOULD_BE_A[3].z , -1) && equal(SHOULD_BE_A[3].w , 1));
	// /* MATRIX TRANSFORMATION (TRANSLATION) */
	// /* points */
	// a = return_tuple(-3, 4, 5, POINT);
	// A = translation(5, -3, 2);
	// b = multiply_matrix_by_tuple(A, a);
	// t_tuple result = return_tuple(2, 1, 7, POINT);
	// assert(equal_tuple(b, result));
	// a = return_tuple(-3, 4, 5, POINT);
	// A = translation(5, -3, 2);
	// b = multiply_matrix_by_tuple(invert_matrix(A, 4), a);
	// result = return_tuple(-8, 7, 3, POINT);
	// assert(equal_tuple(b, result));
	// /* vectors */
	// a = return_tuple(-3, 4, 5, VECTOR);
	// A = translation(5, -3, 2);
	// b = multiply_matrix_by_tuple(A, a);
	// assert(equal_tuple(a, b));
	// /*scaling */
	// /* points */
	// a = return_tuple(-4, 6, 8, POINT);
	// A = scaling(2, 3, 4);
	// b = multiply_matrix_by_tuple(A, a);
	// result = return_tuple(-8, 18, 32, POINT);
	// assert(equal_tuple(b, result));
	// /* vectors */
	// a = return_tuple(-4, 6, 8, VECTOR);
	// A = scaling(2, 3, 4);
	// b = multiply_matrix_by_tuple(A, a);
	// result = return_tuple(-8, 18, 32, VECTOR);
	// assert(equal_tuple(b, result));
	// /*inverse*/
	// a = return_tuple(-4, 6, 8, VECTOR);
	// A = scaling(2, 3, 4);
	// b = multiply_matrix_by_tuple(invert_matrix(A, 4), a);
	// result = return_tuple(-2, 2, 2, VECTOR);
	// assert(equal_tuple(b, result));
	// /*negative scalingL: Reflection */
	// a = return_tuple(2, 3, 4, POINT);
	// A = scaling(-1, 1, 1);
	// b = multiply_matrix_by_tuple(A, a);
	// result = return_tuple(-2, 3, 4, POINT);
	// assert(equal_tuple(b, result));
	// /*Rotaion On X axis*/
	// t_tuple p = return_tuple(0, 1, 0, POINT);
	// t_matrix *half_quarter = rotation_x(M_PI/4);
	// t_matrix *full_quarter = rotation_x(M_PI/2);
	// t_tuple point2 = multiply_matrix_by_tuple(half_quarter, p);
	// assert(equal_tuple(point2, return_tuple(0, sqrt(2)/2, sqrt(2)/2, POINT)));
	// point2 = multiply_matrix_by_tuple(full_quarter, p);
	// assert(equal_tuple(point2, return_tuple(0, 0, 1, POINT)));
	// /*Inverse Rotaion On X axis*/
	// p = return_tuple(0, 1, 0, POINT);
	// half_quarter = rotation_x(M_PI/4);
	// t_matrix *inv = invert_matrix(half_quarter, 4);
	// point2 = multiply_matrix_by_tuple(inv, p);
	// assert(equal_tuple(point2, return_tuple(0, sqrt(2)/2, -sqrt(2)/2, POINT)));
	// /*Rotaion On Y axis*/
	// p = return_tuple(0, 0, 1, POINT);
	// half_quarter = rotation_y(M_PI/4);
	// full_quarter = rotation_y(M_PI/2);
	// point2 = multiply_matrix_by_tuple(half_quarter, p);
	// assert(equal_tuple(point2, return_tuple(sqrt(2)/2, 0, sqrt(2)/2, POINT)));
	// point2 = multiply_matrix_by_tuple(full_quarter, p);
	// assert(equal_tuple(point2, return_tuple(1, 0, 0, POINT)));
	// /*Rotaion On Z axis*/
	// p = return_tuple(0, 1, 0, POINT);
	// half_quarter = rotation_z(M_PI/4);
	// full_quarter = rotation_z(M_PI/2);
	// point2 = multiply_matrix_by_tuple(half_quarter, p);
	// assert(equal_tuple(point2, return_tuple(-sqrt(2)/2, sqrt(2)/2, 0, POINT)));
	// point2 = multiply_matrix_by_tuple(full_quarter, p);
	// assert(equal_tuple(point2, return_tuple(-1, 0, 0, POINT)));
	// /*Shearing*/
	// t_shear shear = fill_shear(return_tuple(0, 0, 0, 0), return_tuple(0, 0, 1, 0));
	// t_matrix	*transform = shearing(shear);
	// p = return_tuple(2, 3, 4, POINT);
	// point2 = multiply_matrix_by_tuple(transform, p);
	// assert(equal_tuple(point2, return_tuple(2, 3, 7, POINT)));
	// /*Chaining Transformations*/
	// /* individually */
	// p = return_tuple(1, 0, 1, POINT);
	// A = rotation_x(M_PI/2);
	// B = scaling(5, 5, 5);
	// C = translation(10, 5, 7);
	// p = multiply_matrix_by_tuple(A, p);
	// assert(equal_tuple(p, return_tuple(1, -1, 0, POINT)));
	// p = multiply_matrix_by_tuple(B, p);
	// assert(equal_tuple(p, return_tuple(5, -5, 0, POINT)));
	// p = multiply_matrix_by_tuple(C, p);
	// assert(equal_tuple(p, return_tuple(15, 0, 7, POINT)));
	// /* chained */
	// p = return_tuple(1, 0, 1, POINT);
	// matrix = matrix_multiply(matrix_multiply(C, B, 4), A, 4);
	// p = multiply_matrix_by_tuple(matrix, p);
	// assert(equal_tuple(p, return_tuple(15, 0, 7, POINT)));
	// /* RAY CASTING */
	// t_ray r;
	// r = return_ray(point(1, 2, 3), vector(4, 5, 6));
	// assert(equal_tuple(r.origin, point(1, 2, 3)) && equal_tuple(r.direction, vector(4, 5, 6)));
	// /*Position*/
	// r = return_ray(point(2, 3, 4), vector(1, 0, 0));
	// assert(equal_tuple(position(r, 0), point(2, 3, 4)));
	// assert(equal_tuple(position(r, 1), point(3, 3, 4)));
	// assert(equal_tuple(position(r, -1), point(1, 3, 4)));
	// assert(equal_tuple(position(r, 2.5), point(4.5, 3, 4)));
	// /* RAY SPHERE INTERSECTION TESTS */
	// /* t0 != t1 (two intersections) */
	// r = return_ray(point(0, 0, -5), vector(0, 0, 1));
	// t_sphere s = sphere(0);
	// t_xs xs = sphere_intersect(&s, r);
	// assert(xs.count == 2 && equal(xs.t0, 4.0) && equal(xs.t1, 6.0) && (t_sphere *)xs.object0 == &s && (t_sphere *)xs.object1 == &s);
	// /* t0 == t1 (intersection is tangent to sphere) */
	// r = return_ray(point(0, 1, -5), vector(0, 0, 1));
	// s = sphere(0);
	// xs = sphere_intersect(&s, r);
	// assert(xs.count == 2 && equal(xs.t0, 5.0) && equal(xs.t1, 5.0) && (t_sphere *)xs.object0 == &s && (t_sphere *)xs.object1 == &s);
	// /* a miss (no intersections at all) */
	// r = return_ray(point(0, 2, -5), vector(0, 0, 1));
	// s = sphere(0);
	// xs = sphere_intersect(&s, r);
	// assert(xs.count == 0 && equal(xs.t0, 0.0) && equal(xs.t1, 0.0) && (t_sphere *)xs.object0 == NULL && (t_sphere *)xs.object1 == NULL);
	// /* ray's origin == sphere's origin */
	// r = return_ray(point(0, 0, 0), vector(0, 0, 1));
	// s = sphere(0);
	// xs = sphere_intersect(&s, r);
	// assert(xs.count == 2 && equal(xs.t0, -1.0) && equal(xs.t1, 1.0) && (t_sphere *)xs.object0 == &s && (t_sphere *)xs.object1 == &s);
	// /* ray's origin > sphere's origin */
	// r = return_ray(point(0, 0, 5), vector(0, 0, 1));
	// s = sphere(0);
	// xs = sphere_intersect(&s, r);
	// assert(xs.count == 2 && equal(xs.t0, -6.0) && equal(xs.t1, -4.0) && (t_sphere *)xs.object0 == &s && (t_sphere *)xs.object1 == &s);
	// /* RAY-OBJECT INTERSECTION RECORD TESTS */
	// s = sphere(0);
	// t_intersection i = {0, 3.5, &s};
	// assert(equal(i.t, 3.5) && (t_sphere *)i.object == &s);
	// /* sphere_intersect() sets the objects */
	// r = return_ray(point(0, 0, -5), vector(0, 0, 1));
	// s = sphere(0);
	// xs = sphere_intersect(&s, r);
	// assert(xs.count == 2 && (t_sphere *)xs.object0 == &s && (t_sphere *)xs.object1 == &s);
	// /*Transforming Sphere With Ray*/
	// r = return_ray(point(1, 2, 3), vector(0, 1, 0));
	// m0 = translation(3, 4, 5);
	// t_ray r2 = transform_ray(r, m0);
	// assert(equal_tuple(r2.origin, point(4, 6, 8)) && equal_tuple(r2.direction, vector(0, 1, 0)));
	// r = return_ray(point(1, 2, 3), vector(0, 1, 0));
	// m0 = scaling(2, 3, 4);
	// r2 = transform_ray(r, m0);
	// assert(equal_tuple(r2.origin, point(2, 6, 12)) && equal_tuple(r2.direction, vector(0, 3, 0)));
	// t_sphere sp = sphere(0);
	// m0 = translation(2, 3, 4);
	// set_transform(&sp, m0);
	// assert(equal_matrices(sp.transform, m0, 4));
	// /*Intersecting a scaled sphere with a ray*/
	// r = return_ray(point(0, 0, -5), vector(0, 0, 1));
	// sp = sphere(1);
	// m0 = scaling(2, 2, 2);
	// set_transform(&sp,  m0);
	// assert(equal_matrices(sp.transform, m0, 4));
	// xs = sphere_intersect(&sp, r);
	// assert(xs.count == 2 && equal(xs.t0, 3) && equal(xs.t1, 7));
	// /*Intersecting a translated sphere with a ray*/
	// r = return_ray(point(0, 0, -5), vector(0, 0, 1));
	// sp = sphere(1);
	// m0 = translation(5, 0, 0);
	// set_transform(&sp,  m0);
	// assert(equal_matrices(sp.transform, m0, 4));
	// xs = sphere_intersect(&sp, r);
	// assert(xs.count == 0);
	// /* SURFACE NORMALS */
	// /* normal at x axis */
	// s = sphere(0);
	// t_tuple n = normal_at(s, point(1, 0, 0));
	// assert(equal_tuple(n, vector(1, 0, 0)));
	// /* normal at y axis */
	// s = sphere(0);
	// n = normal_at(s, point(0, 1, 0));
	// assert(equal_tuple(n, vector(0, 1, 0)));
	// /* normal at z axis */
	// s = sphere(0);
	// n = normal_at(s, point(0, 0, 1));
	// assert(equal_tuple(n, vector(0, 0, 1)));
	// /* normal at nonaxial point */
	// s = sphere(0);
	// n = normal_at(s, point(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3));
	// assert(equal_tuple(n, vector(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3)));
	// /* The normal is a normalized vector */
	// s = sphere(0);
	// n = normal_at(s, point(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3));
	// assert(equal_tuple(n, normalize_vec(n)));
	// /* Computing the normal on a translated sphere */
	// s = sphere(0);
	// s.transform = translation(0, 1, 0);
	// n = normal_at(s, point(0, 1.70711, -0.70711));
	// assert(equal_tuple(n, vector(0, 0.70711, -0.70711)));
	// /* normal of a rotated and scaled sphere */
	// s = sphere(0);
	// s.transform = matrix_multiply(scaling(1, .5, 1), rotation_z(M_PI / 5), 4);
	// n = normal_at(s, point(0, sqrt(2)/2, -sqrt(2)/2));
	// assert(equal_tuple(n, vector(0, 0.97014, -0.24254)));
	// /*Reflection*/
	// /* 45 degree vector */
	// t_tuple v = vector(1, -1, 0);
	// t_tuple normal = vector(0, 1, 0);
	// t_tuple reflection = reflect(v, normal);
	// assert(equal_tuple(reflection, vector(1, 1, 0)));
	// v = vector(0, -1, 0);
	// normal = vector(sqrt(2)/2, sqrt(2)/2, 0);
	// reflection = reflect(v, normal);
	// assert(equal_tuple(reflection, vector(1, 0, 0)));
	// /*Phong Model */
	// /*Point Light*/
	// t_tuple intensity = color(1, 1, 1);
	// t_tuple	pos = point(0, 0, 0);
	// t_light	light = point_light(pos, intensity);
	// assert(equal_tuple(light.intensity, intensity) && equal_tuple(light.position, pos));
	// /* MATERIALS */
	// t_material m = material();
	// assert(equal_tuple(m.color, color(1, 1, 1)));
	// assert(equal(m.ambient, 0.1));
	// assert(equal(m.diffuse, 0.9));
	// assert(equal(m.specular, 0.9));
	// assert(equal(m.shininess, 200.0));
	// /* a sphere has a default material */
	// s = sphere(0);
	// m = s.material;
	// assert(equal_tuple(m.color, color(1, 1, 1)));
	// assert(equal(m.ambient, 0.1));
	// assert(equal(m.diffuse, 0.9));
	// assert(equal(m.specular, 0.9));
	// assert(equal(m.shininess, 200.0));
	// /* A sphere may be assigned a material */
	// s = sphere(0);
	// m = material();
	// m.ambient = 1;
	// s.material = m;
	// assert(equal_tuple(m.color, color(1, 1, 1)));
	// assert(equal(m.ambient, 1));
	// assert(equal(m.diffuse, 0.9));
	// assert(equal(m.specular, 0.9));
	// assert(equal(m.shininess, 200.0));
	// /* Lighting with the eye between the light and the surface */
	// m = material();
	// pos = point(0, 0, 0);
	// t_tuple eyev = vector(0, 0, -1);
	// t_tuple normalv = vector(0, 0, -1);
	// light = point_light(point(0, 0, -10), color(1, 1, 1));
	// t_lighting l = {m, light, pos, eyev, normalv, m.color};
	// t_tuple final_color_intensity = lighting(l);
	// assert(equal_tuple(final_color_intensity, color(1.9, 1.9, 1.9)));
	// /* Lighting with the eye between light and surface, eye offset 45° */
	// m = material();
	// pos = point(0, 0, 0);
	// eyev = vector(0, sqrt(2)/2, -sqrt(2)/2);
	// normalv = vector(0, 0, -1);
	// light = point_light(point(0, 0, -10), color(1, 1, 1));
	// t_lighting l1 = {m, light, pos, eyev, normalv, m.color};
	// final_color_intensity = lighting(l1);
	// assert(equal_tuple(final_color_intensity, color(1.0, 1.0, 1.0)));
	// /* Lighting with eye opposite surface, light offset 45° */
	// m = material();
	// pos = point(0, 0, 0);
	// eyev = vector(0, 0, -1);
	// normalv = vector(0, 0, -1);
	// light = point_light(point(0, 10, -10), color(1, 1, 1));
	// t_lighting l2 = {m, light, pos, eyev, normalv, m.color};
	// final_color_intensity = lighting(l2);
	// assert(equal_tuple(final_color_intensity, color(0.7364, 0.7364, 0.7364)));
	// /* Lighting with eye in the path of the reflection vector */
	// m = material();
	// pos = point(0, 0, 0);
	// eyev = vector(0, -sqrt(2)/2, -sqrt(2)/2);
	// normalv = vector(0, 0, -1);
	// light = point_light(point(0, 10, -10), color(1, 1, 1));
	// t_lighting l3 = {m, light, pos, eyev, normalv, m.color};
	// final_color_intensity = lighting(l3);
	// assert(equal_tuple(final_color_intensity, color(1.6364, 1.6364, 1.6364)));
	// /* Lighting with the light behind the surface */
	// m = material();
	// pos = point(0, 0, 0);
	// eyev = vector(0, 0, -1);
	// normalv = vector(0, 0, -1);
	// light = point_light(point(0, 0, 10), color(1, 1, 1));
	// t_lighting l4 = {m, light, pos, eyev, normalv, m.color};
	// final_color_intensity = lighting(l4);
	// assert(equal_tuple(final_color_intensity, color(.1, .1, .1)));
	// /* The default world TESTS */
	// t_world	*world0 = parse("test_cfiles/test0.rt");
	// assert(equal_tuple(world0->lights_list->color, color(1, 1, 1)));
	// assert(equal(world0->lights_list->intensity, 1));
	// assert(equal_tuple(world0->lights_list->pos, point(-10, 10, -10)));
	// assert(world0->objects_list && world0->objects_list->next && !world0->objects_list->next->next);
	// /* interset world */
	// r = return_ray(point(0, 0, -5), vector(0, 0, 1));
	// t_xs_list	*xs_list = intersect_world(world0, r);
	// assert(xs_list->count == 4);
	// assert(xs_list->t == 4);
	// assert(xs_list->next->t == 4.5);
	// assert(xs_list->next->next->t == 5.5);
	// assert(xs_list->next->next->next->t == 6);
	// /*Precomputing the state of an intersection*/
	// r = return_ray(point(0, 0, -5), vector(0, 0, 1));
	// s = sphere(0);
	// xs_list->count = 1;
	// xs_list->next = NULL;
	// xs_list->object.object = &s;
	// xs_list->t = 4;
	// t_comps comps = prepare_computations(xs_list, r);
	// assert(equal(comps.t, 4) && comps.object.object == xs_list->object.object);
	// assert(equal_tuple(point(0, 0, -1), comps.point));
	// assert(equal_tuple(comps.eyev, vector(0, 0, -1)));
	// assert(equal_tuple(vector(0, 0, -1), comps.normalv));
	// /*The hit, when an intersection occurs on the outside*/
	// r = return_ray(point(0, 0, -5), vector(0, 0, 1));
	// s = sphere(0);
	// xs_list->count = 1;
	// xs_list->next = NULL;
	// xs_list->object.object = &s;
	// xs_list->t = 4;
	// comps = prepare_computations(xs_list, r);
	// assert(comps.inside == false);
	// /*The hit, when an intersection occurs on the inside*/
	// r = return_ray(point(0, 0, 0), vector(0, 0, 1));
	// s = sphere(0);
	// xs_list->count = 1;
	// xs_list->next = NULL;
	// xs_list->object.object = &s;
	// xs_list->t = 1;
	// comps = prepare_computations(xs_list, r);
	// assert(equal(comps.t, 1) && comps.object.object == xs_list->object.object);
	// assert(equal_tuple(point(0, 0, 1), comps.point));
	// assert(equal_tuple(comps.eyev, vector(0, 0, -1)));
	// assert(equal_tuple(vector(0, 0, -1), comps.normalv));
	// assert(comps.inside == true);
	// /*Shading an intersection*/
	// r = return_ray(point(0, 0, -5), vector(0, 0, 1));
	// t_sphere *ss = (t_sphere *)world0->objects_list->object;
	// ss->material.diffuse = .7;
	// ss->material.specular = .2;
	// xs_list->count = 1;
	// xs_list->next = NULL;
	// xs_list->object.object = ss;
	// xs_list->t = 4;
	// xs_list->object.form = SPHERE;
	// comps = prepare_computations(xs_list, r);
	// comps.object.form = SPHERE;
	// t_tuple col = shade_hit(*world0, comps);
	// assert(equal_tuple(col, color(0.400661, 0.475826, 0.325496)));
	// /*Shading an intersection from the inside*/
	// r = return_ray(point(0, 0, 0), vector(0, 0, 1));
	// world0 = parse("test_cfiles/test1.rt");
	// ss = (t_sphere *)world0->objects_list->object;
	// xs_list->count = 1;
	// xs_list->next = NULL;
	// xs_list->object.object = ss;
	// xs_list->t = 0.5;
	// xs_list->object.form = SPHERE;
	// comps = prepare_computations(xs_list, r);
	// comps.object.form = SPHERE;
	// col = shade_hit(*world0, comps);
	// assert(equal_tuple(col, color(0.90498, 0.90498, 0.90498)));
	// /*  The color when a ray misses (black) */
	// world0 = parse("test_cfiles/test0.rt");
	// ss = (t_sphere *)world0->objects_list->object;
	// ss->material.diffuse = .7;
	// ss->material.specular = .2;
	// r = return_ray(point(0, 0, -5), vector(0, 1, 0));
	// col = color_at(world0, r);
	// assert(equal_tuple(color(0, 0, 0), col));
	// /* The color when a ray hits */
	// r = return_ray(point(0, 0, -5), vector(0, 0, 1));
	// col = color_at(world0, r);
	// assert(equal_tuple(color(0.400661, 0.475826, 0.325496), col));
	// // /* The color with an intersection behind the ray */
	// ss = (t_sphere*)world0->objects_list->object;
	// ss->material.ambient = 1;
	// ss = (t_sphere*)world0->objects_list->next->object;
	// ss->material.ambient = 1;
	// r = return_ray(point(0, 0, 0.75), vector(0, 0, -1));
	// col = color_at(world0, r);
	// assert(equal_tuple(col, ss->material.color));
	// /* The transformation matrix for the default orientation */
	// t_tuple from = point(0, 0, 0);
	// t_tuple to = point(0, 0, -1);
	// t_tuple up = vector(0, 1, 0);
	// t_matrix *t_ = view_transform(from, to, up);
	// assert(equal_matrices(t_, identity(), 4));
	// /* A view transformation matrix looking in positive z direction */
	// from = point(0, 0, 0);
	// to = point(0, 0, 1);
	// up = vector(0, 1, 0);
	// t_ = view_transform(from, to, up);
	// assert(equal_matrices(t_, scaling(-1, 1, -1), 4));
	// /* The view transformation moves the world */
	// from = point(0, 0, 8);
	// to = point(0, 0, 0);
	// up = vector(0, 1, 0);
	// t_ = view_transform(from, to, up);
	// assert(equal_matrices(t_, translation(0, 0, -8), 4));
	// /*An arbitrary view transformation*/
	// from = point(1, 3, 2);
	// to = point(4, -2, 8);
	// up = vector(1, 1, 0);
	// t_ = view_transform(from, to, up);
	// matrix = return_4_by_4_matrix(return_tuple(-0.50709, 0.50709, 0.67612, -2.36643),
	// return_tuple(0.76772, 0.60609, 0.12122, -2.82843),
	// return_tuple(-0.35857, 0.59761, -0.71714, 0.00000),
	// return_tuple(0.00000, 0.00000, 0.00000, 1.00000));
	// assert(equal_matrices(t_, matrix, 4));
	// /* Constructing a camera */
	// world0 = parse("test_cfiles/cam.rt");
	// t_camera_ *cam = &world0->camera;
	// camera(160, 120, cam);
	// assert(equal(cam->hsize, 160));
	// assert(equal(cam->vsize, 120));
	// assert(equal(radians(cam->fov), M_PI / 2));
	// assert(equal_matrices(cam->transform, identity(), 4));
	// /* The pixel size for a horizontal canvas */
	// camera(200, 125, cam);
	// assert(equal(cam->pixel_size, .01));
	// camera(125, 200, cam);
	// assert(equal(cam->pixel_size, .01));
	// /* Constructing a ray through the center of the canvas */
	// camera(201, 101, cam);
	// r = ray_for_pixel(cam, 100, 50);
	// assert(equal_tuple(r.origin, point(0, 0, 0)));
	// assert(equal_tuple(r.direction, vector(0, 0, -1)));
	// /* Constructing a ray through a corner of the canvas */
	// camera(201, 101, cam);
	// r = ray_for_pixel(cam, 0, 0);
	// assert(equal_tuple(r.origin, point(0, 0, 0)));
	// assert(equal_tuple(r.direction, vector(0.66519, 0.33259, -0.66851)));
	// /* Constructing a ray when the camera is transformed */
	// camera(201, 101, cam);
	// cam->transform = matrix_multiply(rotation_y(M_PI / 4), translation(0, -2, 5), 4);
	// r = ray_for_pixel(cam, 100, 50);
	// assert(equal_tuple(r.origin, point(0, 2, -5)));
	// assert(equal_tuple(r.direction, vector(sqrt(2)/2, 0, -sqrt(2)/2)));
	// /* Rendering default world with a camera */
	// world0 = parse("test_cfiles/test0.rt");
	// ss = (t_sphere *)world0->objects_list->object;
	// ss->material.diffuse = .7;
	// ss->material.specular = .2;
	// cam = &world0->camera;
	// camera(11, 11, cam);
	// from = point(0, 0, -5);
	// to = cam->vec;
	// up = vector(0, 1, 0);
	// cam->transform = view_transform(from, to, up);
	// t_canvas	image = canvas(cam->hsize, cam->vsize);
	// render(&image, cam, world0);
	// col = color(102.168544, 121.335680, 83.001408);
	// assert(equal_tuple(col, *pixel_at(&image, 5, 5)));
	// /*Lighting with the surface in shadow*/
	// m = material();
	// eyev = vector(0, 0, -1);
	// normalv = vector(0, 0, -1);
	// light = point_light(point(0, 0, -10), color(1, 1, 1));
	// int in_shadow = true;
	// t_lighting l50 = {m, light, light.position, eyev, normalv, color(1, 1, 1),in_shadow};
	// result = lighting(l50);
	// assert(equal_tuple(result, color(0.1, 0.1, 0.1)));
	// t_world	*dw = parse("test_cfiles/test0.rt");
	// /*There is no shadow when nothing is collinear with point and light*/
	// p = point(0, 10, 0);
	// assert(is_shadowed(dw, p) == false);
	// /*The shadow when an object is between the point and the light*/
	// p = point(10, -10, 10);
	// assert(is_shadowed(dw, p) == true);
	// /* There is no shadow when an object is behind the light*/
	// p = point(-20, 20, -20);
	// assert(is_shadowed(dw, p) == false);
	// /*There is no shadow when an object is behind the point*/
	// p = point(-2, 2, -2);
	// assert(is_shadowed(dw, p) == false);
	// /*shade_hit() is given an intersection in shadow*/
	// dw->lights_list->pos = point(0, 0, -10);
	// ss = (t_sphere*)dw->objects_list->next->object;
	// ss->transform = translation(0, 0, 10);
	// r = return_ray(point(0, 0, 5), vector(0, 0, 1));
	// xs_list = intersect_world(dw, r);
	// t_xs_list	*the_hit = hit(xs_list);
	// comps = prepare_computations(the_hit, r);
	// col = shade_hit(*dw, comps);
	// // printf("%f %f %f\n", col.x, col.y, col.z);
	// assert(equal_tuple(col, color(0.1, 0.1, 0.1)));
	// /* The hit should offset the point */
	// r = return_ray(point(0, 0, -5), vector(0, 0, 1));
	// dw = parse("test_cfiles/test2.rt");
	// xs_list = intersect_world(dw, r);
	// the_hit = hit(xs_list);
	// comps = prepare_computations(the_hit, r);
	// assert(comps.over_point.z < -EPSILON/2);
	// assert(comps.point.z > comps.over_point.z);
	// /* A ray intersecting a plane from above */
	// t_plane	pl = plane();
	// r = return_ray(point(0, 1, 0), vector(0, -1, 0));
	// t_xs inter = plane_intersect(&pl, r);
	// assert(inter.count == 2 && equal(inter.t0, 1));
	// /* A ray intersecting a plane from below */
	// r = return_ray(point(0, -1, 0), vector(0, 1, 0));
	// inter = plane_intersect(&pl, r);
	// assert(inter.count == 2 && equal(inter.t0, 1));
	// /* A ray misses a cylinder */
	// t_cylinder cyl = cylinder();
	// t_tuple direction = normalize_vec(vector(0, 1, 0));
	// r = return_ray(point(1, 0, 0), direction);
	// xs = cylinder_intersect(&cyl, r);
	// assert(equal(0, xs.count));
	// direction = normalize_vec(vector(0, 1, 0));
	// r = return_ray(point(0, 0, 0), direction);
	// xs = cylinder_intersect(&cyl, r);
	// assert(equal(0, xs.count));
	// direction = normalize_vec(vector(1, 1, 1));
	// r = return_ray(point(0, 0, -5), direction);
	// xs = cylinder_intersect(&cyl, r);
	// assert(equal(0, xs.count));
	// /* A ray strikes a cylinder */
	// direction = normalize_vec(vector(0, 0, 1));
	// r = return_ray(point(1, 0, -5), direction);
	// xs = cylinder_intersect(&cyl, r);
	// // printf("count %d ------ t0 %f -------- t1 %f\n", xs.count,xs.t0,xs.t1);
	// assert(equal(xs.count, 2) && equal(5, xs.t0) && equal(5, xs.t1));

	// direction = normalize_vec(vector(0, 0, 1));
	// r = return_ray(point(0, 0, -5), direction);
	// xs = cylinder_intersect(&cyl, r);
	// // assert(equal(xs.count, 2) && equal(4, xs.t0) && equal(6, xs.t1));

	// direction = normalize_vec(vector(0.1, 1, 1));
	// r = return_ray(point(0.5, 0, -5), direction);
	// xs = cylinder_intersect(&cyl, r);
	// // assert(equal(xs.count, 2) && equal(6.80798, xs.t0) && equal(7.08872, xs.t1));

	// /* Normal vector on a cylinder */
	// cyl = cylinder();
	// normal = normal_at_cylinder(cyl, point(1,0,0));
	// assert(equal_tuple(normal, vector(1,0,0)));

	// normal = normal_at_cylinder(cyl, point(0,5,-1));
	// assert(equal_tuple(normal, vector(0,0,-1)));

	// normal = normal_at_cylinder(cyl, point(0,-2, 1));
	// assert(equal_tuple(normal, vector(0,0,1)));

	// normal = normal_at_cylinder(cyl, point(-1, 1, 0));
	// assert(equal_tuple(normal, vector(-1,0,0)));

	// /* cylinder tests */
	// cyl = cylinder();
	// cyl.maximum = 2;
	// cyl.minimum = 1;
	// direction = normalize_vec(vector(0.1, 1, 0));
	// r = return_ray(point(0, 1.5, 0), direction);
	// xs = cylinder_intersect(&cyl, r);
	// assert(equal(xs.count, 0));
	// direction = normalize_vec(vector(0, 0, 1));
	// r = return_ray(point(0, 3, -5), direction);
	// xs = cylinder_intersect(&cyl, r);
	// assert(equal(xs.count, 0));
	// direction = normalize_vec(vector(0, 0, 1));
	// r = return_ray(point(0, 2, -5), direction);
	// xs = cylinder_intersect(&cyl, r);
	// assert(equal(xs.count, 0));
	// direction = normalize_vec(vector(0, 0, 1));
	// r = return_ray(point(0, 1, -5), direction);
	// xs = cylinder_intersect(&cyl, r);
	// assert(equal(xs.count, 0));

































	
	// /* to remove */
	// // walls
	t_world	*scene = parse("s.rt");
	// // t_world	*scene = parse("scene.rt");
	// t_sphere *floor = (t_sphere*)scene->objects_list->object;
	// floor->transform = scaling(10, 0.01, 10);
	// floor->material.specular = 0;
	// t_sphere *wall_left = (t_sphere*)scene->objects_list->next->object;
	// wall_left->transform = matrix_multiply(translation(0, 0, 5), matrix_multiply(matrix_multiply(rotation_y(-M_PI/4),
	// 	rotation_x(M_PI/2), 4), scaling(10, 0.01, 10), 4), 4);
	// wall_left->material = floor->material;
	// t_sphere *wall_right = (t_sphere*)scene->objects_list->next->next->object;
	// wall_right->transform = matrix_multiply(translation(0, 0, 5), matrix_multiply(matrix_multiply(rotation_y(M_PI/4),
	// 	rotation_x(M_PI/2), 4), scaling(10, 0.01, 10), 4), 4);
	// wall_right->material = floor->material;
	// // spheres
	// t_sphere *sp_middle = (t_sphere*)scene->objects_list->next->next->next->object;
	// sp_middle->transform = translation(-0.5, 1, 0.5);
	// sp_middle->material.diffuse = .7;
	// sp_middle->material.specular = .5;
	// t_sphere *sp_right = (t_sphere*)scene->objects_list->next->next->next->next->object;
	// sp_right->transform = matrix_multiply(translation(1.5, 0.5, -0.5),
	// 	scaling(0.5, 0.5, 0.5), 4);
	// sp_right->material.diffuse = .7;
	// sp_right->material.specular = .3;
	// t_sphere *sp_left =(t_sphere*)scene->objects_list->next->next->next->next->next->object;
	// sp_left->transform = matrix_multiply(translation(-1.5, 0.33, -0.75),
	// 	scaling(0.33, 0.33, 0.33), 4);
	// sp_left->material.diffuse = .7;
	// sp_left->material.specular = .3;

	// // camera
	camera(WIDTH, HEIGHT, &scene->camera);
	scene->camera.transform = view_transform(scene->camera.pos,
		scene->camera.vec, vector(0,1,0));


	mlx_t	*mlx = mlx_init(WIDTH, HEIGHT, "scene", false);
	mlx_image_t	*img = mlx_new_image(mlx, WIDTH, HEIGHT);
	t_canvas image = canvas(scene->camera.hsize, scene->camera.vsize);
	

	render(&image, &scene->camera, scene);
	create_canvas(&image, img, mlx);
	

	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);

	// _setcolor_(GREEN);
	// printf(" OK.\n");
	// _reset_();
}


/* debugging helpers */
// print 4x4 matrix
/*

	printf("%f %f %f %f\n", t_[0].x, t_[0].y, t_[0].z, t_[0].w);
	printf("%f %f %f %f\n", t_[1].x, t_[1].y, t_[1].z, t_[1].w);
	printf("%f %f %f %f\n", t_[2].x, t_[2].y, t_[2].z, t_[2].w);
	printf("%f %f %f %f\n", t_[3].x, t_[3].y, t_[3].z, t_[3].w);

*/