/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:21:34 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:44 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

t_cylinder		*free_cylinder(t_cylinder *cylinder)
{
	if (cylinder)
	{
		free_tf_list(&(cylinder->tf_list));
		free_cut(&cylinder->cut);
		free(cylinder);
		cylinder = NULL;
	}
	return (NULL);
}

t_cylinder		*init_cylinder(void)
{
	t_cylinder *cylinder;

	cylinder = (t_cylinder *)ft_memalloc(sizeof(t_cylinder));
	cylinder->tf_list = NULL;
	cylinder->off_x = 0;
	cylinder->off_y = 0;
	cylinder->scale_x = 1;
	cylinder->scale_y = 1;
	cylinder->color = set_color(255, 255, 0);
	cylinder->texture = NULL;
	cylinder->bumpmap = NULL;
	cylinder->texmodifier = 0;
	cylinder->reflection = 0.6;
	cylinder->shine = 0.6;
	cylinder->cut = NULL;
	return (cylinder);
}

t_solid			*get_cylinder_solid(void *p)
{
	t_cylinder	*cylinder;
	t_solid		*solid;

	cylinder = (t_cylinder *)p;
	solid = (t_solid *)ft_memalloc(sizeof(t_solid));
	solid->cylinder = cylinder;
	return (solid);
}
