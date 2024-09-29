/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:26:12 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/29 18:18:52 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data_structs/data_structs.h"
#include "../data_structs/data_funcs.h"
#include "get_next_line/get_next_line.h"
#include <libc.h>

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_atoi(const char *str, int *is_fraction)
{
	long	rslt;
	long	tmp;
	int		sign;

	sign = 1;
	rslt = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str) || *str == '.')
	{
		if (*str == '.')
		{
			str++;
			*is_fraction = 1;
		}
		tmp = rslt * 10 + *str - '0';
		if (tmp < rslt && sign == 1)
			return (-1);
		if (tmp < rslt && sign == -1)
			return (0);
		rslt = tmp;
		str++;
	}
	return (sign * rslt);
}

typedef struct s_light_
{
	t_tuple	pos;
	t_tuple	color;
	double	intensity;
	struct s_light_	*next;
}		t_light_;

typedef struct s_object_
{
	int		form;
	void	*object;
	struct s_object_	*next;
}		t_object_;

typedef struct s_camera_
{
	t_tuple		pos;
	t_tuple		vec;
	double		fov;
}		t_camera_;

typedef struct s_world
{
	t_light_ 	*lights_list;
	t_object_	*objects_list;
	t_tuple		ambient_color;
	double		ambient_intensity;
	t_camera_	camera;
}		t_world;

void	front_lights(t_light_ **lst, t_light_ *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}


void	append_lights(t_light_ **lst, t_light_ *new)
{
	t_light_	*ptr;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		front_lights(lst, new);
		return ;
	}
	ptr = *lst;
	while (ptr)
	{
		if (!ptr->next)
		{
			ptr->next = new;
			break ;
		}
		ptr = ptr->next;
	}
}

void	front_objects(t_object_ **lst, t_object_ *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	append_objects(t_object_ **lst, t_object_ *new)
{
	t_object_	*ptr;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		front_objects(lst, new);
		return ;
	}
	ptr = *lst;
	while (ptr)
	{
		if (!ptr->next)
		{
			ptr->next = new;
			break ;
		}
		ptr = ptr->next;
	}
}

#include <stdlib.h>
#include <unistd.h>

void	exitf(char *msg)
{
	size_t	len;

	len = 0;
	while (msg[len])
		len++;
	write(STDERR_FILENO, msg, len);
	exit(EXIT_FAILURE);
}

bool	valid_color(t_tuple color)
{
	if (color.x > 255 || color.x < 0
		|| color.y > 255 || color.y < 0
		|| color.z > 255 || color.z < 0)
		return (false);
	return (true);
}

void	parse_ambient(const char *line, t_world **world, int is_fraction)
{
	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++;
	(*world)->ambient_intensity = ft_atoi(line, &is_fraction) / 10.0;
	is_fraction = 10;
	if ((*world)->ambient_intensity > 1 || (*world)->ambient_intensity < 0)
		exitf(" intensity parse error\n");
	while (*line != ' ')
		line++;
	(*world)->ambient_color.x = ft_atoi(line, &is_fraction);
	while (*line != ',')
		line++;
	line++;
	(*world)->ambient_color.y = ft_atoi(line, &is_fraction);
	is_fraction = 10;

	while (*line != ',')
		line++;
	line++;
	(*world)->ambient_color.z = ft_atoi(line, &is_fraction);
	is_fraction = 10;
	if (!valid_color((*world)->ambient_color))
		exitf("color parse error\n");
}

void	reach_for(const char **line, char end, int skip)
{
	while (**line && **line != end)
		(*line)++;
	if (skip)
		(*line)++;
}

void	parse_camera(const char *line, t_world **world, int is_fraction)
{
	reach_for(&line, ' ', 0);
	(*world)->camera.pos.x = ft_atoi(line, &is_fraction) / (10.0 / is_fraction);
	is_fraction = 10;
	reach_for(&line, ',', 1);
	(*world)->camera.pos.y = ft_atoi(line, &is_fraction) / (10.0 / is_fraction);
	is_fraction = 10;
	reach_for(&line, ',', 1);
	(*world)->camera.pos.z = ft_atoi(line, &is_fraction) / (10.0 / is_fraction);
	is_fraction = 10;
	while (*line != ' ')
		line++;
	(*world)->camera.vec.x = ft_atoi(line, &is_fraction);
	is_fraction = 10;
	reach_for(&line, ',', 1);
	(*world)->camera.vec.y = ft_atoi(line, &is_fraction);
	is_fraction = 10;
	reach_for(&line, ',', 1);
	(*world)->camera.vec.z = ft_atoi(line, &is_fraction);
	if ((*world)->camera.vec.z != 0 && (*world)->camera.vec.z != 1 && (*world)->camera.vec.z != -1)
		exitf("camera o vector parse error\n");
	is_fraction = 10;
	reach_for(&line, ' ', 0);
	(*world)->camera.fov = ft_atoi(line, &is_fraction);
	if ((*world)->camera.fov < 0 || (*world)->camera.fov > 180)
		exitf("camera FOV parse error\n");
}

void	parse_lights()
{
	// light 3d coordinates
		while (*line != ' ')
			line++;
		light = malloc(sizeof(t_light_));
		light->pos.x = ft_atoi(line, &is_fraction) / (10.0 / is_fraction);
		is_fraction = 10;
		while (*line != ',')
			line++;
		line++;
		light->pos.y = ft_atoi(line, &is_fraction) / (10.0 / is_fraction);
		is_fraction = 10;
		while (*line != ',')
			line++;
		line++;
		light->pos.z = ft_atoi(line, &is_fraction) / (10.0 / is_fraction);
		is_fraction = 10;
		// light intensity
		while (*line != ' ')
			line++;
		while (*line == ' ')
			line++;
		light->intensity = ft_atoi(line, &is_fraction) / 10.0;
		is_fraction = 10;
		if (light->intensity > 1 || light->intensity < 0) // intensity should be in range [0.0,1.0]
		{
			printf(" intensity parse error\n");
			exit(EXIT_FAILURE);
		}
		// light rgb
		while (*line != ' ')
			line++;
		light->color.x = ft_atoi(line, &is_fraction);
		if (light->color.x > 255 || light->color.x < 0)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		while (*line != ',')
			line++;
		line++;
		light->color.y = ft_atoi(line, &is_fraction);
		is_fraction = 10;

		if (light->color.y > 255 || light->color.y < 0)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		if (light->color.y > 255 || light->color.z < 0)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		while (*line != ',')
			line++;
		line++;
		light->color.z = ft_atoi(line, &is_fraction);
		is_fraction = 10;

		if (light->color.z > 255)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		if (light->color.z > 255)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		light->next = NULL;
		append_lights(lights_list, light);
}

void get_values(const char *line, t_light_ **lights_list, t_object_ **objects_list, t_world **world)
{
	size_t	i;
	int		is_fraction = 10;
	t_tuple	light_rgb;
	t_sphere *sp;
	t_object_	*object;
	t_light_	*light;

	i = 0;
	if (line[0] == 'A' && line[1] == ' ') // A
		parse_ambient(line, world, 10);
	else if (line[0] == 'C' && line[1] == ' ') // C
		parse_camera(line, world, 10);
	else if (line[0] == 'L' && line[1] == ' ') // L
		parse_lights();
	else if (line[0] == 's' && line[1] == 'p' && line[2] == ' ') // sp
	{
		// sphere center 3d coordinates
		sp = malloc(sizeof(t_sphere));
		object = malloc(sizeof(t_object_));
		*sp = sphere(0);
		sp->material.ambient = (*world)->ambient_intensity;
		while (*line != ' ')
			line++;
		sp->center.x = ft_atoi(line, &is_fraction) / (10.0 / is_fraction);
		is_fraction = 10;
		while (*line != ',')
			line++;
		line++;
		sp->center.y = ft_atoi(line, &is_fraction) / (10.0 / is_fraction);
		is_fraction = 10;
		while (*line != ',')
			line++;
		line++;
		sp->center.z = ft_atoi(line, &is_fraction) / (10.0 / is_fraction);
		is_fraction = 10;
		/* sphere radius */
		while (*line != ' ')
			line++;
		while (*line == ' ')
			line++;
		sp->radius = ft_atoi(line, &is_fraction) / 10.0 / 2;
		is_fraction = 10;
		if (sp->radius <= 0) // get rid of meaningless number
		{
			printf(" radius parse error\n");
			exit(EXIT_FAILURE);
		}
		// sphere rgb
		while (*line != ' ')
			line++;
		sp->material.color.x = ft_atoi(line, &is_fraction);
		if (sp->material.color.x > 255 || sp->material.color.x < 0)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		while (*line != ',')
			line++;
		line++;
		sp->material.color.y = ft_atoi(line, &is_fraction);
		is_fraction = 10;

		if (sp->material.color.y > 255 || sp->material.color.y < 0)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		if (sp->material.color.y > 255 || sp->material.color.z < 0)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		while (*line != ',')
			line++;
		line++;
		sp->material.color.z = ft_atoi(line, &is_fraction);
		is_fraction = 10;
		if (sp->material.color.z > 255)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		if (sp->material.color.z > 255)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		sp->material.ambient = (*world)->ambient_intensity;
		object->form = SPHERE;
		object->object = sp;
		object->next = NULL;
		append_objects(objects_list, object);
	}
}

t_world	*parse(const char *file)
{
	t_light_	*lights_list = NULL;
	t_object_	*objects_list = NULL;
	t_world		*world = malloc(sizeof(t_world));
	t_tuple		ambient_rgb;
	const char	*line;
	int			fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	line = get_next_line(fd);
	while (line)
	{
		get_values(line, &lights_list, &objects_list, &world);
		line = get_next_line(fd);
	}
	world->lights_list = lights_list;
	world->objects_list = objects_list;
	return (world);
}

int main()
{
	t_world *world = parse("spec.rt");

	printf("world ambient intensity: [%f]\n", world->ambient_intensity);
	printf("world ambient rgb: [%f %f %f]\n", world->ambient_color.x, world->ambient_color.y, world->ambient_color.z);
	printf("world camera:\n\t3d_coords[%f %f %f]\n", world->camera.pos.x, world->camera.pos.y, world->camera.pos.z);
	printf("\torientation vector[%f %f %f]\n", world->camera.vec.x, world->camera.vec.y, world->camera.vec.z);
	printf("\tFOV[%f]\n", world->camera.fov);
	printf("world objects(spheres):\n");
	for (; world->objects_list; world->objects_list = world->objects_list->next)
	{
		t_sphere *sp = world->objects_list->object;
		printf("\tform[%d]\n\tcpos[%f %f %f]\n\tr[%f]\n\t&trans[%p]\n\twamb[%f]\n\trgb[%f %f %f]\n\n", world->objects_list->form, sp->center.x, sp->center.y, sp->center.z,
		sp->radius, sp->transform, sp->material.ambient,sp->material.color.x, sp->material.color.y, sp->material.color.z);
		// fprintf(stderr, "F");

	}
	printf("\nworld lights:\n");
	for (; world->lights_list; world->lights_list = world->lights_list->next)
	{
		printf("\tposition[%f %f %f]", world->lights_list->pos.x, world->lights_list->pos.y, world->lights_list->pos.z);
		printf("\n\trgb[%f %f %f]", world->lights_list->color.x, world->lights_list->color.y, world->lights_list->color.z);
		printf("\n\tintensity[%f]\n\n", world->lights_list->intensity);
	}
}