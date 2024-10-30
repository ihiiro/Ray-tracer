/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_linked_lists.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:38:56 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/30 12:37:21 by yel-yaqi         ###   ########.fr       */
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

// bool	validate_normalized_vectors(t_object_ *object)
// {
// 	if (object->form == PLANE)
// 		if (!normalized_vector(((t_plane *)object->object)->normal))
// 			return (false);
// 	if (object->form == CYLINDER || object->form == CONE)
// 		if (!normalized_vector(((t_cylinder *)object->object)->vec))
// 			return (false);
// 	return (true);
// }

void	append_objects(t_object_ **lst, t_object_ *new)
{
	t_object_	*ptr;

	if (!lst || !new)
		return ;
	if (!*lst)
		front_objects(lst, new);
	else
	{
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
	// if (!validate_normalized_vectors(new))
	// 	exitf("append_objects: non-unit vector\n");
}
