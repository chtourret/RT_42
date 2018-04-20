/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_find_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 18:54:23 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:04 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vect				find_n_pos(t_ray ray, t_record *info)
{
	mult_vector(&(ray.dir), info->dist);
	add_to_vector(&(ray.ori), ray.dir);
	return (ray.ori);
}

void				find_n_dist(t_research *r, t_data *d, t_thread *thread)
{
	r->dist[0] = 0;
	r->dist[1] = 0;
	r->dist[2] = 0;
	if (r->current_obj->type != CSG)
	{
		apply_inverse_tf(r->current_obj, &(r->modified_ray.ori), d);
		apply_inverse_tf(r->current_obj, &(r->modified_ray.dir), d);
		((void (*)(t_ray ray, t_obj *, t_thread *, double *))
			d->func->get_obj_n[r->current_obj->type])(r->modified_ray,
				r->current_obj, thread, r->dist);
		check_cut(r, d, thread);
	}
	else
		get_csg_n(r, thread, d);
}

static t_record		*create_record(t_research r, t_data *d, t_thread *thread)
{
	t_record *info;

	info = (t_record *)ft_memalloc(sizeof(t_record));
	init_info_zero(info);
	info->type = r.closest_obj->type;
	info->obj = r.closest_obj;
	info->dist = r.final_dist - ACC;
	info->ray = r.final_ray;
	info->n_pos = find_n_pos(r.final_ray, info);
	info->normal = define_obj_normal(info, d, thread);
	apply_tf(info->obj, &(info->ray.dir), d, TF_RAY);
	apply_tf(info->obj, &(info->ray.ori), d, TF_RAY);
	info->color = COLOR(info->obj);
	define_obj_color(info);
	apply_tf(info->obj, &(info->n_pos), d, TF_INTERSECTION);
	if_plane_cut_an_object(d, info, thread);
	if (dot_product_vector(info->ray.dir, info->normal) > 0)
		negative_vector(&(info->normal));
	return (info);
}

void				init_var(t_research *r, t_ray ray)
{
	r->closest_obj = NULL;
	r->current_obj = NULL;
	r->dist[0] = 0;
	r->dist[1] = 0;
	r->dist[2] = 0;
	r->final_dist = 0;
	r->modified_ray = ray;
}

t_record			*find_n(t_ray ray, t_data *d, t_thread *thread)
{
	t_research		r;
	t_obj			*tmp;

	init_var(&r, ray);
	tmp = d->obj;
	while (tmp)
	{
		r.modified_ray = ray;
		r.current_obj = tmp;
		find_n_dist(&r, d, thread);
		if ((r.dist[2] > r.final_dist && r.final_dist == 0 &&
					r.dist[2] > ACC) ||
				(r.dist[2] < r.final_dist && r.final_dist > 0 &&
				r.dist[2] > ACC))
		{
			r.final_dist = r.dist[2];
			r.closest_obj = r.current_obj;
			r.final_ray = r.modified_ray;
		}
		if (tmp->next == NULL && r.final_dist > ACC)
			return (create_record(r, d, thread));
		tmp = tmp->next;
	}
	return (NULL);
}
