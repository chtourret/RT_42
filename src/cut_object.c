/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:42:59 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:25:53 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			calculate_plane(t_cut *cut, t_data *d,
		t_thread *thread)
{
	cut->modified_ray = cut->object_ray;
	cut->plane[0] = 0;
	cut->plane[1] = 0;
	cut->plane[2] = 0;
	if (cut->current_obj->solid->plane->cut_type == 1)
	{
		apply_tf(cut->cutted_obj, &(cut->modified_ray.ori), d, TF_RAY);
		apply_tf(cut->cutted_obj, &(cut->modified_ray.dir), d, TF_RAY);
	}
	apply_inverse_tf(cut->current_obj, &(cut->modified_ray.ori), d);
	apply_inverse_tf(cut->current_obj, &(cut->modified_ray.dir), d);
	cut->dot = dot_product_vector(cut->modified_ray.dir,
			cut->current_obj->solid->plane->normal);
	get_plane_n(cut->modified_ray, cut->current_obj, thread,
			cut->plane);
}

static int			research_cut(t_research *r, t_cut *cut, t_data *d, int c36)
{
	t_vect raydir;
	t_vect rayori;

	if (cut->cutted_obj->type == CONE)
	{
		raydir = cut->object_ray.dir;
		rayori = cut->object_ray.ori;
		mult_vector(&(raydir), r->dist[2]);
		add_to_vector(&(rayori), raydir);
		raydir = r->modified_ray.dir;
		if (c36 == 1)
			negative_vector(&raydir);
		cut->c.in =
			dot_product_vector(((t_vect (*)(t_obj *, t_vect, t_thread *))
						d->func->get_obj_normal[cut->cutted_obj->type])
					(cut->cutted_obj, rayori, NULL), raydir) > 0 ? 1 : 0;
	}
	cut->cutted_obj->type == CONE ? init_cut_condition_cone(r, cut) :
		init_cut_condition_others(r, cut);
	if (cut->cutted_obj->type == CONE)
		return (research_in_cone(r, cut));
	else
		return (research_in_others(r, cut));
	return (0);
}

static void			init_cut(t_cut *cut, t_research *r)
{
	cut->modified_ray = r->modified_ray;
	cut->object_ray = r->modified_ray;
	cut->final_dist = 0;
	cut->final_dist_p = 0;
	cut->final_dist_n = 0;
	cut->closest_negative = NULL;
	cut->closest_positive = NULL;
	cut->closest_positive_ray = r->modified_ray;
	cut->closest_negative_ray = r->modified_ray;
	cut->cutted_obj = r->current_obj;
}

void				check_cut(t_research *r, t_data *d, t_thread *thread)
{
	t_cut	cut;
	int		type;
	int		c36;

	c36 = -1;
	type = r->current_obj->type;
	cut.current_obj = r->current_obj->cut;
	if (r->dist[2] > ACC && type != HYPERBOLOID)
		c36 = 0;
	else if (r->dist[2] < 0 && type == CONE)
		c36 = 1;
	if (c36 == 1 || c36 == 0)
	{
		init_cut(&cut, r);
		while (cut.current_obj)
		{
			calculate_plane(&cut, d, thread);
			if (cut.plane[2] > ACC || cut.plane[2] < 0)
				if (research_cut(r, &cut, d, c36) == 0)
					break ;
			cut.current_obj = cut.current_obj->next;
		}
		save_dist(r, &cut, thread);
	}
}
