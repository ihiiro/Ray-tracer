/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:26:12 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/29 13:01:34 by yel-yaqi         ###   ########.fr       */
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


int	ft_atoi(const char *str)
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
			str++;
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
	t_tuple	ambient_color;
	double	ambient_intensity;

	i = 0;
	if (line[0] == 'A' && line[1] == ' ')
	{
		/* A */
		printf("A");
		while (*line != ' ')
			line++;
		while (*line == ' ')
			line++;
		ambient_intensity = ft_atoi(line) / 10.0;
		if (ambient_intensity > 1) // intensity should be in range [0.0,1.0]
		{
			printf(" intensity parse error\n");
			exit(EXIT_FAILURE);
		}
		printf("=[%.1f]", ambient_intensity); // ambient intensity
		while (*line != ' ')
			line++;
		ambient_color.x = ft_atoi(line);
		if (ambient_color.x > 255)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		printf("[%.0f ", ambient_color.x);
		while (*line != ',')
			line++;
		line++;
		ambient_color.y = ft_atoi(line);
		if (ambient_color.y > 255)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		if (ambient_color.y > 255)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		printf("%.0f ", ambient_color.y);
		while (*line != ',')
			line++;
		line++;
		ambient_color.z = ft_atoi(line);
		if (ambient_color.z > 255)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		if (ambient_color.z > 255)
		{
			printf(" color parse error\n");
			exit(EXIT_FAILURE);
		}
		printf("%.0f]\n", ambient_color.z);
	}
	else if (line[0] == 'C' && line[1] == ' ')
	{
		printf("C\n");
		
	}
	else if (line[0] == 'L' && line[1] == ' ')
	{
		printf("L\n");
		
	}
	else if (line[0] == 's' && line[1] == 'p' && line[2] == ' ')
	{
		printf("sp\n");
		
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
	world->light_list = lights_list;
	world->object_list = objects_list;
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