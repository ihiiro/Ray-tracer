/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:22:03 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/02 21:28:30 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include "data_funcs.h"
#include "../maths/maths.h"
#include <stdlib.h>
#include <stdio.h>

void	front_xs(t_xs_list **lst, t_xs_list *node0)
{
	if (!lst)
		return ;

	*lst = node0;
}

void	append_xs(t_xs_list **lst, t_xs xs)
{
	t_xs_list	*ptr;
	t_xs_list	*node0;
	t_xs_list	*node1;

	node0 = malloc(sizeof(t_xs_list));
	node0->object.object = xs.object0;
	node0->object.form = xs.form;
	node0->t = xs.t0;
	node0->next = NULL;
	if (!equal(xs.t0, xs.t1))
	{
		node1 = malloc(sizeof(t_xs_list));
		node1->object.object = xs.object1;
		node1->t = xs.t1;
		node1->object.form = xs.form;
		node1->next = NULL;
		node0->next = node1;
	}
	if (!*lst)
	{
		front_xs(lst, node0);
		return ;
	}
	ptr = *lst;
	while (ptr)
	{
		if (!ptr->next)
		{
			ptr->next = node0;
			break ;
		}
		ptr = ptr->next;
	}
}

void	swap(t_xs_list *a, t_xs_list *b)
{
	t_xs_list	atmp;

	atmp.object = a->object;
	atmp.t = a->t;
	a->object = b->object;
	a->t = b->t;
	b->object = atmp.object;
	b->t = atmp.t;
}

void	sort_xs_list(t_xs_list *xs_list, int count)
{
	double		t;
	int			c;
	t_xs_list	*head;

	if (!xs_list)
		return ;
	c = 0;
	head = xs_list;
	while (c < count)
	{
		xs_list = head;
		while (xs_list && xs_list->next)
		{
			if (xs_list->t > xs_list->next->t)
				swap(xs_list, xs_list->next);
			xs_list = xs_list->next;
		}
		c++;
	}
}

t_xs_list	*intersect_world(t_world *world, t_ray ray)
{
	t_object_		*iter;
	t_xs			obj_xs;
	t_xs_list		*xs_list;
	int				count;

	iter = world->objects_list;
	xs_list = NULL;
	count = 0;
	while (iter)
	{
		if (iter->form == SPHERE)
		{
			obj_xs = sphere_intersect(iter->object, ray);
			obj_xs.form = SPHERE;
			if (obj_xs.count == 2 && obj_xs.t0 == obj_xs.t1)
				count++;
			else if (obj_xs.count == 2 && obj_xs.t0 != obj_xs.t1)
				count += 2;
			if (obj_xs.count == 2)
				append_xs(&xs_list, obj_xs);
		}
		iter = iter->next;
	}
	if (xs_list)
	{
		sort_xs_list(xs_list, count);
		xs_list->count = count;
	}
	return (xs_list);
}
