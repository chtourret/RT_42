/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_obj_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 16:24:17 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:29 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_obj	*add_sphere(t_sphere *sphere)
{
	t_obj *obj;

	obj = (t_obj *)ft_memalloc(sizeof(t_obj));
	obj->type = SPHERE;
	obj->next = NULL;
	obj->solid = init_solid(sphere, SPHERE);
	obj->reflectionx = &sphere->reflection;
	obj->shinex = &sphere->shine;
	obj->cut = sphere->cut;
	return (obj);
}

t_obj			*push_sphere(t_obj **begin_obj, t_sphere *sphere)
{
	t_obj *tmp;

	tmp = *begin_obj;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_sphere(sphere);
		return (tmp->next);
	}
	*begin_obj = add_sphere(sphere);
	return (*begin_obj);
}
