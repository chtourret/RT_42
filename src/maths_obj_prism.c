/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_obj_prism.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 00:45:11 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:16 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			init_prism_distance(double distance[4][3])
{
	distance[0][0] = 0;
	distance[0][1] = 0;
	distance[0][2] = 0;
	distance[1][0] = 0;
	distance[1][1] = 0;
	distance[1][2] = 0;
	distance[2][0] = 0;
	distance[2][1] = 0;
	distance[2][2] = 0;
	distance[3][0] = 0;
	distance[3][1] = 0;
	distance[3][2] = 0;
}

static void			find_second_prism_n(double distance[12][3],
	double *dist, int winning_i, double first_distance)
{
	int		i;
	double	tmp;

	i = -1;
	tmp = 0;
	dist[2] = first_distance;
	dist[0] = dist[2];
	dist[1] = dist[2];
	while (++i < 4)
	{
		if (i != winning_i)
		{
			if (distance[i][2] != 0)
				tmp = distance[i][2];
		}
	}
	if (tmp < dist[2])
		dist[0] = tmp;
	else
		dist[1] = tmp;
}

static void			save_closest_triangle_prism(t_obj *obj, t_thread *thread,
		int *i, int *winning_i)
{
	if (thread)
		TO_PRISM->closest_triangle[thread->num] = *i;
	else
		TO_PRISM->closest_triangle[0] = *i;
	*winning_i = *i;
}

void				get_prism_n(t_ray ray, t_obj *obj,
		t_thread *thread, double *dist)
{
	double	distance[4][3];
	double	tmp;
	int		i;
	int		winning_i;

	init_prism_distance(distance);
	i = -1;
	while (++i < 4)
		get_triangle_n(ray, TO_PRISM->triangle[i], thread, distance[i]);
	if (thread)
		TO_PRISM->closest_triangle[thread->num] = -1;
	else
		TO_PRISM->closest_triangle[0] = -1;
	tmp = 0;
	i = -1;
	while (++i < 4)
	{
		if ((tmp < distance[i][2] && tmp == 0 && distance[i][2] > ACC) ||
				(distance[i][2] < tmp && tmp != 0 && distance[i][2] > ACC))
		{
			tmp = distance[i][2];
			save_closest_triangle_prism(obj, thread, &i, &winning_i);
		}
	}
	find_second_prism_n(distance, dist, winning_i, tmp);
}
