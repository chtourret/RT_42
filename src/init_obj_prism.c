/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj_prism.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:22:00 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:42 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_prism		*free_prism(t_prism *prism)
{
	int i;

	i = 0;
	if (prism)
	{
		free_tf_list(&(prism->tf_list));
		while (i < 4)
		{
			if (prism->triangle[i])
				free_obj(&prism->triangle[i]);
			i++;
		}
		free_cut(&prism->cut);
		free(prism);
		prism = NULL;
	}
	return (NULL);
}

t_prism		*compute_prism(t_prism *prism)
{
	t_vect a;
	t_vect b;
	t_vect c;
	t_vect d;

	a = prism->a;
	b = prism->b;
	c = prism->c;
	d = prism->d;
	prism->triangle[0] = add_triangle(init_tri_w_p(a, b, c));
	prism->triangle[1] = add_triangle(init_tri_w_p(b, d, c));
	prism->triangle[2] = add_triangle(init_tri_w_p(a, c, d));
	prism->triangle[3] = add_triangle(init_tri_w_p(a, b, d));
	return (prism);
}

void		prism_bzero(t_prism *prism)
{
	prism->a = init_vector(-1, -1, 0, 1);
	prism->b = init_vector(1, -1, 0, 1);
	prism->c = init_vector(0, 1, 0, 1);
	prism->d = init_vector(0, 0, 1, 1);
	prism->color = set_color(255, 0, 0);
	prism->tf_list = NULL;
	prism->texture = NULL;
	prism->bumpmap = NULL;
	prism->reflection = 0.6;
	prism->shine = 0.6;
	prism->cut = NULL;
}

t_prism		*init_prism(void)
{
	t_prism	*prism;
	int		i;

	i = -1;
	prism = (t_prism *)ft_memalloc(sizeof(t_prism));
	prism_bzero(prism);
	prism->triangle = (t_obj **)ft_memalloc(sizeof(t_obj *) * 4);
	while (++i < 4)
		prism->triangle[i] = NULL;
	prism->closest_triangle = (int *)ft_memalloc(sizeof(int) * THREADS);
	i = -1;
	while (++i < THREADS)
		prism->closest_triangle[i] = -1;
	return (prism);
}

t_solid		*get_prism_solid(void *p)
{
	t_prism	*prism;
	t_solid	*solid;

	prism = (t_prism *)p;
	solid = (t_solid *)ft_memalloc(sizeof(t_solid));
	solid->prism = prism;
	return (solid);
}
