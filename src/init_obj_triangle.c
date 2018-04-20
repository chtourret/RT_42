/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj_triangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:22:37 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:39 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_triangle		*free_triangle(t_triangle *triangle)
{
	if (triangle)
	{
		free_tf_list(&(triangle->tf_list));
		free_cut(&triangle->cut);
		free_triangle(triangle);
		triangle = NULL;
	}
	return (NULL);
}

t_vect			compute_triangle_normal(t_triangle *triangle)
{
	t_vect normal;

	normal = cross_product_vector(triangle->ab, triangle->cb);
	normalize_vector(&normal);
	return (normal);
}

void			calculate_sides(t_triangle *triangle)
{
	triangle->ab = init_vector(triangle->b.x - triangle->a.x,
			triangle->b.y - triangle->a.y,
			triangle->b.z - triangle->a.z, 0);
	triangle->ac = init_vector(triangle->c.x - triangle->a.x,
			triangle->c.y - triangle->a.y,
			triangle->c.z - triangle->a.z, 0);
	triangle->ba = init_vector(triangle->a.x - triangle->b.x,
			triangle->a.y - triangle->b.y,
			triangle->a.z - triangle->b.z, 0);
	triangle->bc = init_vector(triangle->c.x - triangle->b.x,
			triangle->c.y - triangle->b.y,
			triangle->c.z - triangle->b.z, 0);
	triangle->ca = init_vector(triangle->a.x - triangle->c.x,
			triangle->a.y - triangle->c.y,
			triangle->a.z - triangle->c.z, 0);
	triangle->cb = init_vector(triangle->b.x - triangle->c.x,
			triangle->b.y - triangle->c.y,
			triangle->b.z - triangle->c.z, 0);
}

t_triangle		*compute_triangle(t_triangle *triangle)
{
	calculate_sides(triangle);
	triangle->normal = compute_triangle_normal(triangle);
	triangle->distance = dot_product_vector(triangle->normal, triangle->a);
	return (triangle);
}

t_triangle		*init_triangle(void)
{
	t_triangle *triangle;

	triangle = (t_triangle *)ft_memalloc(sizeof(t_triangle));
	triangle->tf_list = NULL;
	triangle->a = init_vector(0, 0, 0, 1);
	triangle->b = init_vector(0, 0, 0, 1);
	triangle->c = init_vector(0, 0, 0, 1);
	triangle->ab = init_vector(0, 0, 0, 0);
	triangle->ac = init_vector(0, 0, 0, 0);
	triangle->ba = init_vector(0, 0, 0, 0);
	triangle->bc = init_vector(0, 0, 0, 0);
	triangle->ca = init_vector(0, 0, 0, 0);
	triangle->cb = init_vector(0, 0, 0, 0);
	triangle->normal = init_vector(0, 0, 0, 0);
	triangle->distance = 0;
	triangle->color = set_color(255, 0, 0);
	triangle->reflection = 0.5;
	triangle->shine = 0.5;
	triangle->texture = NULL;
	triangle->bumpmap = NULL;
	return (triangle);
}
