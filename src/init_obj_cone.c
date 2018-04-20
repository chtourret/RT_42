/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj_cone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:19:33 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:46 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

t_cone		*free_cone(t_cone *cone)
{
	if (cone)
	{
		if (cone->tf_list)
			free_tf_list(&(cone->tf_list));
		free_cut(&cone->cut);
		free(cone);
		cone = NULL;
	}
	return (NULL);
}

t_cone		*init_cone(double alpha)
{
	t_cone *cone;

	cone = (t_cone *)ft_memalloc(sizeof(t_cone));
	cone->tf_list = NULL;
	cone->off_x = 0;
	cone->off_y = 0;
	cone->scale_x = 1;
	cone->scale_y = 1;
	cone->tan_alpha = pow(tan(alpha * M_PI / 180), 2);
	cone->color = set_color(0, 255, 0);
	cone->texture = NULL;
	cone->bumpmap = NULL;
	cone->texmodifier = 0;
	cone->reflection = 0.6;
	cone->shine = 0.6;
	cone->cut = NULL;
	return (cone);
}

t_solid		*get_cone_solid(void *p)
{
	t_cone		*cone;
	t_solid		*solid;

	cone = (t_cone *)p;
	solid = (t_solid *)ft_memalloc(sizeof(t_solid));
	solid->cone = cone;
	return (solid);
}
