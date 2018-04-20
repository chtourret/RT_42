/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj_csg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:21:14 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:45 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_csg		*free_csg(t_csg *csg)
{
	if (csg)
	{
		free_obj(&(csg->first));
		free_obj(&(csg->second));
		csg = NULL;
	}
	return (NULL);
}

t_csg		*init_csg(void)
{
	t_csg *csg;

	csg = (t_csg *)ft_memalloc(sizeof(t_csg));
	csg->operation = -1;
	csg->first = NULL;
	csg->second = NULL;
	return (csg);
}

t_solid		*get_csg_solid(void *p)
{
	t_csg		*csg;
	t_solid		*solid;

	csg = (t_csg *)p;
	solid = (t_solid *)ft_memalloc(sizeof(t_solid));
	solid->csg = csg;
	return (solid);
}
