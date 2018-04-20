/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_obj_hyperboloid.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 00:44:55 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:18 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

static void		check_for_solutions_hyper(double *dist)
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

void			get_hyperboloid_n(t_ray ray, t_obj *obj,
		t_thread *thread, double *dist)
{
	double a;
	double b;
	double c;
	double delta;

	(void)thread;
	(void)obj;
	a = pow(ray.dir.x, 2) - pow(ray.dir.y, 2) + pow(ray.dir.z, 2);
	b = (2 * ray.ori.x * ray.dir.x) - (2 * ray.ori.y * ray.dir.y) +
		(2 * ray.ori.z * ray.dir.z);
	if (TO_HYPERBOLOID->sheets == 1)
		c = pow(ray.ori.x, 2) - pow(ray.ori.y, 2) + pow(ray.ori.z, 2) - 1;
	else
		c = pow(ray.ori.x, 2) - pow(ray.ori.y, 2) + pow(ray.ori.z, 2) + 1;
	delta = (b * b) - (4 * a * c);
	if (delta > 0)
	{
		dist[0] = (((-1 * b - sqrt(delta))) / (2 * a)) - ACC;
		dist[1] = (((-1 * b + sqrt(delta))) / (2 * a)) - ACC;
		check_for_solutions_hyper(dist);
	}
}
