/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_pro_eblouissement.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 00:45:52 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:08 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		copy_light(t_light **alist, t_light seen)
{
	t_light		*new;
	t_light		*list;

	list = *alist;
	new = init_light();
	new->pos.x = seen.pos.x;
	new->pos.y = seen.pos.y;
	new->pos.z = seen.pos.z;
	new->color.r = seen.color.r;
	new->color.g = seen.color.g;
	new->color.b = seen.color.b;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
	else
		*alist = new;
}

t_obj		*find_hit_light(t_ray ray, t_data *d, double dist, t_thread *thread)
{
	t_research	r;
	t_obj		*tmp_current;

	ray.dir.w = 0;
	init_var(&r, ray);
	r.current_obj = d->obj;
	while (r.current_obj)
	{
		tmp_current = r.current_obj;
		r.modified_ray = ray;
		find_n_dist(&r, d, thread);
		if ((r.dist[2] > r.final_dist && r.final_dist == 0
			&& r.dist[2] > ACC) || (r.dist[2] < r.final_dist &&
			r.final_dist > 0 && r.dist[2] > ACC))
		{
			r.final_dist = r.dist[2];
			r.closest_obj = r.current_obj;
			r.final_ray = r.modified_ray;
		}
		if (tmp_current->next == NULL
				&& r.final_dist > ACC && dist > r.final_dist)
			return (r.closest_obj);
		r.current_obj = tmp_current->next;
	}
	return (NULL);
}

t_light		*get_visible_lights(t_data *d)
{
	t_light		*tmp;
	t_light		*new_list;
	t_ray		tlr;
	double		dist;

	new_list = NULL;
	tmp = d->light_list;
	while (tmp)
	{
		tlr = init_ray(d->cam.pos, tmp->pos);
		substract_to_vector(&(tlr.dir), tlr.ori);
		dist = vector_magnitude(tlr.dir);
		normalize_vector(&(tlr.dir));
		if (dot_product_vector(tlr.dir, d->cam.dir) > 0)
			if (!(find_hit_light(tlr, d, dist, NULL)))
				copy_light(&new_list, *tmp);
		tmp = tmp->next;
	}
	return (new_list);
}

t_color		foreach_light_dist(t_ray ray, t_light *lst, t_color boost)
{
	t_light		*tmp;
	t_color		lol;
	double		dist;
	t_vect		tmpmaggle;
	t_ray		tmp_ray;

	tmp = lst;
	while (tmp)
	{
		tmp_ray = init_ray(ray.ori, ray.dir);
		tmpmaggle = tmp->pos;
		substract_to_vector(&tmpmaggle, tmp_ray.ori);
		mult_vector(&tmp_ray.dir, dot_product_vector(tmp_ray.dir, tmpmaggle));
		substract_to_vector(&tmp_ray.dir, tmpmaggle);
		dist = vector_magnitude(tmp_ray.dir);
		lol = copy_color(tmp->color);
		color_scale(&lol, 1 / (5 * dist));
		color_add(&boost, lol);
		tmp = tmp->next;
	}
	return (boost);
}

void		add_eblouissement(t_data *d)
{
	t_light		*iseeyou;
	t_ray		ray;
	t_color		boost;
	int			x;
	int			y;

	iseeyou = get_visible_lights(d);
	x = -1;
	while (++x < d->width)
	{
		y = -1;
		while (++y < d->height)
		{
			ray = calculate_ray(d, x, y, NULL);
			boost = img_pull_pixel(x, y, d->img);
			boost = foreach_light_dist(ray, iseeyou, boost);
			putpixel(x, y, get_color(boost), d->img);
		}
	}
	mlx_clear_window(d->mlx, d->win);
	mlx_put_image_to_window(d->mlx, d->win, d->img->img, 0, 0);
}
