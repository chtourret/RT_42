/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:21:52 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:42:51 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

t_plane			*free_plane(t_plane *plane)
{
	if (plane)
	{
		free_tf_list(&(plane->tf_list));
		free_cut(&plane->cut);
		free(plane);
		plane = NULL;
	}
	return (NULL);
}

static void		plane_bzero(t_plane *plane)
{
	plane->tf_list = NULL;
	plane->off_x = 0;
	plane->off_y = 0;
	plane->scale_x = 1;
	plane->scale_y = 1;
	plane->texmodifier = 0;
	plane->normal = init_vector(0, 1, 0, 0);
	plane->dist = 0;
	plane->color = set_color(255, 255, 0);
	plane->texture = NULL;
	plane->bumpmap = NULL;
	plane->reflection = 0.6;
	plane->shine = 0.6;
	plane->cut_type = 0;
	plane->cut = NULL;
}

t_plane			*init_plane(void)
{
	t_plane	*plane;
	int		i;

	i = -1;
	plane = (t_plane *)ft_memalloc(sizeof(t_plane));
	plane->cutted_obj = (t_obj **)ft_memalloc(sizeof(t_obj *) * THREADS);
	while (++i < THREADS)
		plane->cutted_obj[i] = NULL;
	plane_bzero(plane);
	return (plane);
}

t_solid			*get_plane_solid(void *p)
{
	t_plane *plane;
	t_solid *solid;

	plane = (t_plane *)p;
	solid = (t_solid *)ft_memalloc(sizeof(t_solid));
	solid->plane = plane;
	return (solid);
}
