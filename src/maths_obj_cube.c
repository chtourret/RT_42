/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_obj_cube.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 00:42:30 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:21 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		init_cube_distance2(double distance[12][3])
{
	distance[6][0] = 0;
	distance[6][1] = 0;
	distance[6][2] = 0;
	distance[7][0] = 0;
	distance[7][1] = 0;
	distance[7][2] = 0;
	distance[8][0] = 0;
	distance[8][1] = 0;
	distance[8][2] = 0;
	distance[9][0] = 0;
	distance[9][1] = 0;
	distance[9][2] = 0;
	distance[10][0] = 0;
	distance[10][1] = 0;
	distance[10][2] = 0;
	distance[11][0] = 0;
	distance[11][1] = 0;
	distance[11][2] = 0;
}

static void		init_cube_distance(double distance[12][3])
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
	distance[4][0] = 0;
	distance[4][1] = 0;
	distance[4][2] = 0;
	distance[5][0] = 0;
	distance[5][1] = 0;
	distance[5][2] = 0;
	init_cube_distance2(distance);
}

static void		find_second_cube_n(double distance[12][3],
	double *dist, int winning_i, double first_distance)
{
	int		i;
	double	tmp;

	i = -1;
	tmp = 0;
	dist[2] = first_distance;
	dist[0] = dist[2];
	dist[1] = dist[2];
	while (++i < 12)
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

void			save_closest_triangle(t_obj *obj, t_thread *thread, int *i,
		int *winning_i)
{
	if (thread == NULL)
		TO_CUBE->closest_triangle[0] = *i;
	else
		TO_CUBE->closest_triangle[thread->num] = *i;
	*winning_i = *i;
}

void			get_cube_n(t_ray ray, t_obj *obj, t_thread *thread,
		double *dist)
{
	double		distance[12][3];
	double		tmp;
	int			i;
	int			winning_i;

	i = -1;
	init_cube_distance(distance);
	while (++i < 12)
		get_triangle_n(ray, TO_CUBE->triangle[i], thread, distance[i]);
	if (thread == NULL)
		TO_CUBE->closest_triangle[0] = -1;
	else
		TO_CUBE->closest_triangle[thread->num] = -1;
	tmp = 0;
	i = -1;
	while (++i < 12)
	{
		if ((tmp < distance[i][2] && tmp == 0 && distance[i][2] > ACC) ||
				(distance[i][2] < tmp && tmp != 0 && distance[i][2] > ACC))
		{
			tmp = distance[i][2];
			save_closest_triangle(obj, thread, &i, &winning_i);
		}
	}
	find_second_cube_n(distance, dist, winning_i, tmp);
}
