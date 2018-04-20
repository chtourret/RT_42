/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_obj_paraboloid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 00:45:00 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:17 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

static void		check_for_solutions_para(double *dist)
{
	if (dist[0] > dist[1])
		swap_double(&dist[0], &dist[1]);
	if (dist[0] < 0 && dist[1] > 0)
		dist[2] = dist[1];
	else if (dist[0] > 0 && dist[1] > 0)
		dist[2] = dist[0];
	else
	{
		dist[0] = 0;
		dist[1] = 0;
	}
}

void			get_paraboloid_n(t_ray ray, t_obj *obj,
		t_thread *thread, double *dist)
{
	double a;
	double b;
	double c;
	double delta;

	(void)thread;
	(void)obj;
	a = ray.dir.x * ray.dir.x + ray.dir.z * ray.dir.z;
	b = 2 * ray.dir.x * ray.ori.x + 2 * ray.dir.z * ray.ori.z - ray.dir.y;
	c = ray.ori.x * ray.ori.x + ray.ori.z * ray.ori.z - ray.ori.y;
	delta = (b * b) - (4 * a * c);
	if (delta > 0)
	{
		dist[0] = (((-1 * b - sqrt(delta))) / (2 * a)) - ACC;
		dist[1] = (((-1 * b + sqrt(delta))) / (2 * a)) - ACC;
		check_for_solutions_para(dist);
	}
}
