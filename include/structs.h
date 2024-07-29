#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct tuple_s
{
	double	x;
	double	y;
	double	z;
	double	w;
}		tuple_t;

typedef struct color_s
{
	double	r;
	double	g;
	double	b;
}		color_t;

typedef struct canvas_s
{
	double	width;
	double	height;
}		canvas_t;

#endif