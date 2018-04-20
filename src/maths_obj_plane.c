/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_obj_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 00:45:06 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:42:08 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

void		get_plane_n(t_ray ray, t_obj *obj, t_thread *thread, double *dist)
{
	t_vect v;
	t_vect w;
	double a;
	double b;

	(void)thread;
	a = dot_product_vector(ray.dir, TO_PLANE->normal);
	b = 0;
	v = ray.ori;
	w = TO_PLANE->normal;
	if (a != 0)
	{
		mult_vector(&w, TO_PLANE->dist);
		substract_to_vector(&v, w);
		b = dot_product_vector(TO_PLANE->normal, v);
		dist[0] = -1 * b / a;
		dist[1] = dist[0];
		dist[2] = dist[0];
	}
}
