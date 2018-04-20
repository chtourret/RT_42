/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:22:26 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:41 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

t_sphere	*free_sphere(t_sphere *sphere)
{
	if (sphere)
	{
		free_tf_list(&(sphere->tf_list));
		free_cut(&sphere->cut);
		free(sphere);
		sphere = NULL;
	}
	return (NULL);
}

t_sphere	*init_sphere(double rad)
{
	t_sphere *sphere;

	sphere = (t_sphere *)ft_memalloc(sizeof(t_sphere));
	sphere->tf_list = NULL;
	sphere->off_x = 0;
	sphere->off_y = 0;
	sphere->scale_x = 1;
	sphere->scale_y = 1;
	sphere->radius = rad;
	sphere->color = set_color(255, 0, 0);
	sphere->texmodifier = 0;
	sphere->texture = NULL;
	sphere->bumpmap = NULL;
	sphere->reflection = 0.6;
	sphere->shine = 0.6;
	sphere->cut = NULL;
	return (sphere);
}

t_solid		*get_sphere_solid(void *p)
{
	t_sphere	*sphere;
	t_solid		*solid;

	sphere = (t_sphere *)p;
	solid = (t_solid *)ft_memalloc(sizeof(t_solid));
	solid->sphere = sphere;
	return (solid);
}
