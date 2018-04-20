/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raytracer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:05:36 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:03 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			init_x_info_color(double *x, t_record **info,
		t_color *color)
{
	*x = -1;
	*info = NULL;
	*color = set_color(0, 0, 0);
}

static t_color		calculate_pixel(t_data *d, t_thread *t)
{
	double		x;
	double		y;
	t_record	*info;
	t_ray		cam_ray;
	t_color		color;

	init_x_info_color(&x, &info, &color);
	while (++x < d->aa_lvl)
	{
		y = -1;
		while (++y < d->aa_lvl)
		{
			cam_ray = calculate_ray(d, x, y, t);
			info = find_n(cam_ray, d, t);
			if (info)
			{
				info->current_thread = t;
				get_color_at(d, info);
				color_add_nolimit(&color, info->color);
				free_info(info);
			}
		}
	}
	color_divide(&(color), d->dpp);
	return (color);
}

static void			init_thread_values(t_thread *t)
{
	t->x = t->num * t->d->width / THREADS;
	t->y = 0;
	t->d->x = 0;
	t->d->y = 0;
}

static void			*calculate(void *p)
{
	t_color			color;
	t_thread		*t;
	double			end_x;

	t = (t_thread *)p;
	end_x = (t->num + 1) * t->d->width / THREADS;
	init_thread_values(t);
	while (t->x < end_x)
	{
		while (t->y < t->d->height)
		{
			color = calculate_pixel(t->d, t);
			putpixel(t->x, t->y, get_color(color), t->d->img);
			t->y++;
			t->d->y++;
		}
		t->y = 0;
		t->d->y = 0;
		t->d->x++;
		t->x++;
	}
	pthread_exit(0);
}

void				raytracer(t_data *d)
{
	int i;

	i = -1;
	while (++i < THREADS)
	{
		d->th[i].num = i;
		d->th[i].d = (t_data *)d;
		pthread_create(&d->th[i].t, NULL, calculate, &d->th[i]);
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(d->th[i].t, NULL);
}
