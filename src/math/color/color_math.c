#include "../../../include/rt.h"

/* @hadamard_product(rgb0, rgb1)
	Takes 2 color tuples and returns their product color tuple.
	The rgb values of the new tuple are the products
	of the corresponding parts of the old two color tuples.
 */
color_t	hadamard_product(color_t rgb0, color_t rgb1)
{
	return (color(rgb0.r * rgb1.r,
				  rgb0.g * rgb1.g,
				  rgb0.b * rgb1.b));
}

/* @diff_color(rgb0, rgb1)
	Takes 2 color tuples and returns their difference color tuple.
	The rgb values of the new tuple are the differences of the
	corresponding parts of the old two color tuples.
 */
color_t	diff_color(color_t rgb0, color_t rgb1)
{
	return (color(rgb0.r - rgb1.r,
				  rgb0.g - rgb1.g,
				  rgb0.b - rgb1.b));
}

/* @scale_color(rgb0, rgb1)
	Takes a color tuple and a scalar quantity, and returns
	the scaled color tuple. Each part of the new color
	tuple is the product of the old part and the scalar.
 */
color_t	scale_color(color_t rgb, double scalar)
{
	return (color(rgb.r * scalar,
				  rgb.g * scalar,
				  rgb.b * scalar));
}

