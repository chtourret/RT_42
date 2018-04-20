/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_obj_cone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:25:22 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:34 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_obj	*add_cone(t_cone *cone)
{
	t_obj *obj;

	obj = (t_obj *)ft_memalloc(sizeof(t_obj));
	obj->type = CONE;
	obj->next = NULL;
	obj->solid = init_solid(cone, CONE);
	obj->reflectionx = &cone->reflection;
	obj->shinex = &cone->shine;
	obj->cut = cone->cut;
	return (obj);
}

t_obj			*push_cone(t_obj **begin_obj, t_cone *cone)
{
	t_obj *tmp;

	tmp = *begin_obj;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_cone(cone);
		return (tmp->next);
	}
	else
		*begin_obj = add_cone(cone);
	return (*begin_obj);
}
