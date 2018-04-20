/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_obj_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 00:43:45 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:22 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

int				inside(t_obj *obj, t_ray ray, double *dist)
{
	t_vect	raydir;
	t_vect	rayori;
	t_vect	normal;
	int		inside;

	inside = 0;
	if (dist[0] < dist[1])
		dist[2] = dist[1];
	else
		dist[2] = dist[0];
	raydir = ray.dir;
	rayori = ray.ori;
	mult_vector(&(raydir), dist[2]);
	add_to_vector(&(rayori), raydir);
	normal = init_vector(2 * rayori.x, -2 * TO_CONE->tan_alpha *
			rayori.y, 2 * rayori.z, 0);
	normalize_vector(&normal);
	raydir = ray.dir;
	negative_vector(&raydir);
	if (dot_product_vector(normal, raydir) > 0)
		inside = 1;
	return (inside);
}

static void		check_for_solutions_cone(double *dist, t_ray ray,
		t_obj *obj)
{
	if (dist[0] > dist[1])
		swap_double(&dist[0], &dist[1]);
	if (dist[0] < 0 && dist[1] > 0)
		dist[2] = dist[1];
	else if (dist[0] > 0 && dist[1] > 0)
		dist[2] = dist[0];
	else
	{
		if (!inside(obj, ray, dist))
		{
			dist[0] = 0;
			dist[1] = 0;
		}
	}
}

void			get_cone_n(t_ray ray, t_obj *obj, t_thread *thread,
		double *dist)
{
	double	a;
	double	b;
	double	c;
	double	delta;

	(void)thread;
	a = (ray.dir.x * ray.dir.x) + (ray.dir.z * ray.dir.z) -
		obj->solid->cone->tan_alpha * (ray.dir.y * ray.dir.y);
	b = (2 * ray.ori.x * ray.dir.x) + (2 * ray.ori.z * ray.dir.z) -
		(2 * obj->solid->cone->tan_alpha * ray.ori.y * ray.dir.y);
	c = pow(ray.ori.x, 2) + pow(ray.ori.z, 2) -
		obj->solid->cone->tan_alpha * pow(ray.ori.y, 2);
	delta = b * b - 4 * a * c;
	if (delta > 0)
	{
		dist[0] = (((-1 * b - sqrt(delta))) / (2 * a)) - ACC;
		dist[1] = (((-1 * b + sqrt(delta))) / (2 * a)) - ACC;
		check_for_solutions_cone(dist, ray, obj);
	}
}
