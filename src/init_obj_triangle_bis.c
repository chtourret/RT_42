/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj_triangle_bis.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 00:16:38 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:40 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_triangle		*init_tri_w_p(t_vect a, t_vect b, t_vect c)
{
	t_triangle	*triangle;

	triangle = (t_triangle *)ft_memalloc(sizeof(t_triangle));
	triangle->tf_list = NULL;
	triangle->a = a;
	triangle->b = b;
	triangle->c = c;
	calculate_sides(triangle);
	triangle->normal = compute_triangle_normal(triangle);
	triangle->distance = dot_product_vector(triangle->normal, triangle->a);
	triangle->color = set_color(255, 0, 0);
	triangle->reflection = 0.5;
	triangle->shine = 0.5;
	triangle->texture = NULL;
	triangle->bumpmap = NULL;
	triangle->cut = NULL;
	return (triangle);
}

t_solid			*get_triangle_solid(void *p)
{
	t_triangle	*triangle;
	t_solid		*solid;

	triangle = (t_triangle *)p;
	solid = (t_solid *)ft_memalloc(sizeof(t_solid));
	solid->triangle = triangle;
	return (solid);
}
