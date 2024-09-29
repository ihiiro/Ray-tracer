/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:26:12 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/29 14:00:01 by yel-yaqi         ###   ########.fr       */
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






/*






================








*/



typedef struct s_light_
{
	t_tuple	pos;
	t_tuple	color;
	t_tuple	intensity;
	struct s_light_	*next;
}		t_light_;

typedef struct s_object_
{
	int		form;
	void	*object;
	struct s_object_	*next;
}		t_object_;

typedef struct s_world
{
	t_light_ 	*light_list;
	t_object_	*object_list;
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

void get_values(const char *line, t_light_ **lights_list, t_object_ **objects_list)
{
	size_t	i;
	t_tuple	ambient_rgb;
	double	ambient_intensity;
	t_tuple	camera;
	double	camera_fov;
	t_tuple	camera_o_vec;
	int		is_fraction = 10;
	t_tuple		light;
	double	light_intensity;
	t_tuple	light_rgb;
	t_sphere sp;

	i = 0;
	if (line[0] == 'A' && line[1] == ' ') // A
	{
		/* ambient intensity */
		printf("A");
		while (*line != ' ')
			line++;
		while (*line == ' ')
			line++;
		ambient_intensity = ft_atoi(line, &is_fraction) / 10.0;
		is_fraction = 10;
		if (ambient_intensity > 1 || ambient_intensity < 0) // intensity should be in range [0.0,1.0]
		{
			printf(" intensity parse error\n");
			exit(EXIT_FAILURE);
		}
		printf("=[%.1f]", ambient_intensity); // ambient intensity
		// ambient rgb
		while (*line != ' ')
			line++;
		ambient_rgb.x = ft_atoi(line, &is_fraction);
		if (ambient_rgb.x > 255 || ambient_rgb.x < 0)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		printf("[%.0f ", ambient_rgb.x);
		while (*line != ',')
			line++;
		line++;
		ambient_rgb.y = ft_atoi(line, &is_fraction);
		is_fraction = 10;

		if (ambient_rgb.y > 255 || ambient_rgb.y < 0)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		if (ambient_rgb.y > 255 || ambient_rgb.z < 0)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		printf("%.0f ", ambient_rgb.y);
		while (*line != ',')
			line++;
		line++;
		ambient_rgb.z = ft_atoi(line, &is_fraction);
		is_fraction = 10;

		if (ambient_rgb.z > 255)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		if (ambient_rgb.z > 255)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		printf("%.0f]\n", ambient_rgb.z);
	}
	else if (line[0] == 'C' && line[1] == ' ') // C
	{
		// camera 3d coordinates
		printf("C");
		while (*line != ' ')
			line++;
		camera.x = ft_atoi(line, &is_fraction) / (10.0 / is_fraction);
		is_fraction = 10;
		printf("=[%.1f ", camera.x);
		while (*line != ',')
			line++;
		line++;
		camera.y = ft_atoi(line, &is_fraction) / (10.0 / is_fraction);
		is_fraction = 10;
		printf("%.1f ", camera.y);
		while (*line != ',')
			line++;
		line++;
		camera.z = ft_atoi(line, &is_fraction) / (10.0 / is_fraction);
		is_fraction = 10;
		printf("%.1f]", camera.z);
		// camera orientation vector
		while (*line != ' ')
			line++;
		camera_o_vec.x = ft_atoi(line, &is_fraction);
		if (camera_o_vec.x != 0 && camera_o_vec.x != 1 && camera_o_vec.x != -1)
		{
			printf("camera o vector parse error\n");
			exit(EXIT_FAILURE);
		}
		is_fraction = 10;
		printf("[%.1f ", camera_o_vec.x);
		while (*line != ',')
			line++;
		line++;
		camera_o_vec.y = ft_atoi(line, &is_fraction);
		if (camera_o_vec.y != 0 && camera_o_vec.y != 1 && camera_o_vec.y != -1)
		{
			printf("camera o vector parse error\n");
			exit(EXIT_FAILURE);
		}
		is_fraction = 10;
		printf("%.1f ", camera_o_vec.y);
		while (*line != ',')
			line++;
		line++;
		camera_o_vec.z = ft_atoi(line, &is_fraction);
		if (camera_o_vec.z != 0 && camera_o_vec.z != 1 && camera_o_vec.z != -1)
		{
			printf("camera o vector parse error\n");
			exit(EXIT_FAILURE);
		}
		is_fraction = 10;
		printf("%.1f]", camera_o_vec.z);
		// camera FOV
		while (*line != ' ')
			line++;
		camera_fov = ft_atoi(line, &is_fraction);
		if (camera_fov < 0 || camera_fov > 180)
		{
			printf("camera FOV parse error\n");
			exit(EXIT_FAILURE);
		}
		printf("[%.1f]\n", camera_fov);

	}
	else if (line[0] == 'L' && line[1] == ' ') // L
	{
		// light 3d coordinates
		printf("L");
		while (*line != ' ')
			line++;
		light.x = ft_atoi(line, &is_fraction) / (10.0 / is_fraction);
		is_fraction = 10;
		printf("=[%.1f ", light.x);
		while (*line != ',')
			line++;
		line++;
		light.y = ft_atoi(line, &is_fraction) / (10.0 / is_fraction);
		is_fraction = 10;
		printf("%.1f ", light.y);
		while (*line != ',')
			line++;
		line++;
		light.z = ft_atoi(line, &is_fraction) / (10.0 / is_fraction);
		is_fraction = 10;
		printf("%.1f]", light.z);
		// light intensity
		while (*line != ' ')
			line++;
		while (*line == ' ')
			line++;
		light_intensity = ft_atoi(line, &is_fraction) / 10.0;
		is_fraction = 10;
		if (light_intensity > 1 || light_intensity < 0) // intensity should be in range [0.0,1.0]
		{
			printf(" intensity parse error\n");
			exit(EXIT_FAILURE);
		}
		printf("[%.1f]", light_intensity);
		// light rgb
		while (*line != ' ')
			line++;
		light_rgb.x = ft_atoi(line, &is_fraction);
		if (light_rgb.x > 255 || light_rgb.x < 0)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		printf("[%.0f ", light_rgb.x);
		while (*line != ',')
			line++;
		line++;
		light_rgb.y = ft_atoi(line, &is_fraction);
		is_fraction = 10;

		if (light_rgb.y > 255 || light_rgb.y < 0)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		if (light_rgb.y > 255 || light_rgb.z < 0)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		printf("%.0f ", light_rgb.y);
		while (*line != ',')
			line++;
		line++;
		light_rgb.z = ft_atoi(line, &is_fraction);
		is_fraction = 10;

		if (light_rgb.z > 255)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		if (light_rgb.z > 255)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		printf("%.0f]\n", light_rgb.z);
	}
	else if (line[0] == 's' && line[1] == 'p' && line[2] == ' ') // sp
	{
		// sphere center 3d coordinates
		printf("sp");
		sp = sphere(0);
		while (*line != ' ')
			line++;
		sp.center.x = ft_atoi(line, &is_fraction) / (10.0 / is_fraction);
		is_fraction = 10;
		printf("=[%.1f ", sp.center.x);
		while (*line != ',')
			line++;
		line++;
		sp.center.y = ft_atoi(line, &is_fraction) / (10.0 / is_fraction);
		is_fraction = 10;
		printf("%.1f ", sp.center.y);
		while (*line != ',')
			line++;
		line++;
		sp.center.z = ft_atoi(line, &is_fraction) / (10.0 / is_fraction);
		is_fraction = 10;
		printf("%.1f]", sp.center.z);
		/* sphere radius */
		while (*line != ' ')
			line++;
		while (*line == ' ')
			line++;
		sp.radius = ft_atoi(line, &is_fraction) / 10.0 / 2;
		is_fraction = 10;
		if (sp.radius <= 0) // get rid of meaningless number
		{
			printf(" radius parse error\n");
			exit(EXIT_FAILURE);
		}
		printf("[%.1f]", sp.radius);
		// sphere rgb
		while (*line != ' ')
			line++;
		sp.material.color.x = ft_atoi(line, &is_fraction);
		if (sp.material.color.x > 255 || sp.material.color.x < 0)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		printf("[%.0f ", sp.material.color.x);
		while (*line != ',')
			line++;
		line++;
		sp.material.color.y = ft_atoi(line, &is_fraction);
		is_fraction = 10;

		if (sp.material.color.y > 255 || sp.material.color.y < 0)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		if (sp.material.color.y > 255 || sp.material.color.z < 0)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		printf("%.0f ", sp.material.color.y);
		while (*line != ',')
			line++;
		line++;
		sp.material.color.z = ft_atoi(line, &is_fraction);
		is_fraction = 10;

		if (sp.material.color.z > 255)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		if (sp.material.color.z > 255)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		printf("%.0f]\n", sp.material.color.z);
	}
}

t_world	*parse(const char *file)
{
	t_light_	*lights_list = NULL;
	t_object_	*objects_list = NULL;
	t_world		*world = NULL;
	const char	*line;
	int			fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	line = get_next_line(fd);
	while (line)
	{
		get_values(line, &lights_list, &objects_list);
		line = get_next_line(fd);
	}
	// world->light_list = lights_list;
	// world->object_list = objects_list;
	return (world);
}

/*

world parse(file)
	lights_list
	object_list
	for line in file
		get_values(line, lights_list, object_list)
	world.lights_list = lights_list
	world.object_list = object_list
	return world

*/

int main()
{
	t_world *world = parse("spec.rt");
}