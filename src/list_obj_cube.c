/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_obj_cube.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:23:00 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:33 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_obj	*add_cube(t_cube *cube)
{
	t_obj *obj;

	obj = (t_obj *)ft_memalloc(sizeof(t_obj));
	obj->type = CUBE;
	obj->next = NULL;
	obj->reflectionx = &cube->reflection;
	obj->shinex = &cube->shine;
	obj->solid = init_solid(cube, CUBE);
	obj->cut = cube->cut;
	return (obj);
}

t_obj			*push_cube(t_obj **begin_obj, t_cube *cube)
{
	t_obj *tmp;

	tmp = *begin_obj;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_cube(cube);
		return (tmp->next);
	}
	else
		*begin_obj = add_cube(cube);
	return (*begin_obj);
}
