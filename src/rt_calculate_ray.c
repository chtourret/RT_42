/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_calculate_ray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:47:59 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:05 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vect		calculate_ray_dir(t_data *d, double x, double y,
		t_thread *thread)
{
	double xindent;
	double yindent;
	t_vect ray_dir;
	t_vect left;
	t_vect up;

	if (thread)
		xindent = d->cam.plane_width / d->width * (thread->x + x *
				(1 / d->aa_lvl));
	else
		xindent = d->cam.plane_width / d->width * (x * (1 / d->aa_lvl));
	if (thread)
		yindent = d->cam.plane_height / d->height * (thread->y + y *
				(1 / d->aa_lvl));
	else
		yindent = d->cam.plane_height / d->height * (y * (1 / d->aa_lvl));
	ray_dir = d->cam.first_pixel_dir;
	left = d->cam.left;
	mult_vector(&left, xindent);
	up = d->cam.up;
	mult_vector(&up, yindent * -1);
	substract_to_vector(&ray_dir, left);
	add_to_vector(&ray_dir, up);
	normalize_vector(&ray_dir);
	return (ray_dir);
}

t_ray				calculate_ray(t_data *d, double x, double y,
		t_thread *thread)
{
	t_vect	cam_ray_dir;
	t_vect	cam_ray_ori;
	t_ray	cam_ray;

	cam_ray_dir = calculate_ray_dir(d, x, y, thread);
	cam_ray_ori = d->cam.pos;
	cam_ray = init_ray(cam_ray_ori, cam_ray_dir);
	return (cam_ray);
}
