/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj_hyperboloid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboualav <aboualav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:40:52 by aboualav          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:43 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_hyperboloid		*free_hyperboloid(t_hyperboloid *hyperboloid)
{
	if (hyperboloid)
	{
		free_tf_list(&(hyperboloid->tf_list));
		free_cut(&hyperboloid->cut);
		free(hyperboloid);
		hyperboloid = NULL;
	}
	return (NULL);
}

t_hyperboloid		*init_hyperboloid(int sheets)
{
	t_hyperboloid *hyperboloid;

	hyperboloid = (t_hyperboloid *)ft_memalloc(sizeof(t_hyperboloid));
	hyperboloid->tf_list = NULL;
	hyperboloid->off_x = 0;
	hyperboloid->off_y = 0;
	hyperboloid->scale_x = 1;
	hyperboloid->scale_y = 1;
	hyperboloid->color = set_color(0, 0, 255);
	hyperboloid->texture = NULL;
	hyperboloid->bumpmap = NULL;
	hyperboloid->texmodifier = 0;
	hyperboloid->reflection = 0.6;
	hyperboloid->shine = 0.6;
	hyperboloid->sheets = sheets;
	hyperboloid->cut = NULL;
	return (hyperboloid);
}

t_solid				*get_hyperboloid_solid(void *p)
{
	t_hyperboloid	*hyperboloid;
	t_solid			*solid;

	hyperboloid = (t_hyperboloid *)p;
	solid = (t_solid *)ft_memalloc(sizeof(t_solid));
	solid->hyperboloid = hyperboloid;
	return (solid);
}
