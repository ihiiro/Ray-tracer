/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:20:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/20 11:56:09 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef struct s_tuple
{
	double x;
	double y;
	double z;
	double w;
}			t_tuple;

typedef struct s_pixel
{
	int x;
	int y;
	t_tuple color;
}			t_pixel;

typedef struct s_canvas
{
	int 	width;
	int 	height;
	t_pixel **pixels;
}			t_canvas;

/* CONSTANTS */
# define POINT 1.0
# define VECTOR 0.0

/* CONVENIENT ALIASES */
typedef t_tuple t_matrix;