/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj_paraboloid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:21:44 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:33:29 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_paraboloid		*free_paraboloid(t_paraboloid *paraboloid)
{
	if (paraboloid)
	{
		free_tf_list(&(paraboloid->tf_list));
		free_cut(&paraboloid->cut);
		free(paraboloid);
		paraboloid = NULL;
	}
	return (NULL);
}

t_paraboloid		*init_paraboloid(void)
{
	t_paraboloid *paraboloid;

	paraboloid = (t_paraboloid *)ft_memalloc(sizeof(t_paraboloid));
	paraboloid->tf_list = NULL;
	paraboloid->off_x = 0;
	paraboloid->off_y = 0;
	paraboloid->scale_x = 1;
	paraboloid->scale_y = 1;
	paraboloid->color = set_color(0, 0, 255);
	paraboloid->texture = NULL;
	paraboloid->bumpmap = NULL;
	paraboloid->texmodifier = 0;
	paraboloid->reflection = 0.6;
	paraboloid->shine = 0.6;
	paraboloid->cut = NULL;
	return (paraboloid);
}

t_solid				*get_paraboloid_solid(void *p)
{
	t_paraboloid	*paraboloid;
	t_solid			*solid;

	paraboloid = (t_paraboloid *)p;
	solid = (t_solid *)ft_memalloc(sizeof(t_solid));
	solid->paraboloid = paraboloid;
	return (solid);
}
