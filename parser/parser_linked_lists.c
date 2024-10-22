/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_linked_lists.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:38:56 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/22 14:04:51 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data_structs/data_structs.h"
#include "../data_structs/data_funcs.h"

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

bool	validate_normalized_vectors(t_object_ *object)
{
	t_plane		*pl;
	t_cylinder	*cy;

	pl = NULL;
	cy = NULL;
	if (object->form == PLANE)
		pl = object->object;
	else if (object->form == CYLINDER)
		cy = object->object;
	if (pl)
		if (!normalized_vector(pl->normal))
			return (false);
	if (cy)
		if (!normalized_vector(cy->vec))
			return (false);
	return (true);
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
	if (!validate_normalized_vectors(new))
		exitf("append_objects: non-unit vector\n");
}
