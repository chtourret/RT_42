/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctourret <ctourret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 22:16:41 by ctourret          #+#    #+#             */
/*   Updated: 2017/06/21 12:26:22 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				if_plane_cut_an_object(t_data *d, t_record *info,
		t_thread *t)
{
	int				num;

	num = t ? t->num : 0;
	if (info->type == PLANE)
	{
		if (info->obj->solid->plane->cutted_obj[num] != NULL)
		{
			if (info->TO_PLANE->cut_type == 0)
			{
				apply_tf(info->obj->solid->plane->cutted_obj[num],
						&(info->ray.dir), d, TF_RAY);
				apply_tf(info->obj->solid->plane->cutted_obj[num],
						&(info->ray.ori), d, TF_RAY);
				apply_tf(info->obj->solid->plane->cutted_obj[num],
						&(info->n_pos), d, TF_INTERSECTION);
				apply_tf(info->obj->solid->plane->cutted_obj[num],
						&info->normal, d, TF_NORMAL);
			}
			info->obj->solid->plane->cutted_obj[num] = NULL;
		}
	}
}

static void			change_dist_zero(t_research *r, t_cut *cut, t_thread *t)
{
	r->dist[0] = cut->final_dist;
	r->dist[2] = cut->final_dist;
	if (t)
		r->current_obj->solid->plane->cutted_obj[t->num] = cut->cutted_obj;
	else
		r->current_obj->solid->plane->cutted_obj[0] = cut->cutted_obj;
}

static void			change_dist_one(t_research *r, t_cut *cut)
{
	r->dist[0] = cut->final_dist;
	r->current_obj = cut->cutted_obj;
}

static void			analyze_dist_p_n(t_research *r, t_cut *cut)
{
	if (cut->final_dist_p == 0 && cut->final_dist_n == 0)
		return ;
	else if (cut->final_dist_p > ACC && cut->final_dist_n > ACC
			&& cut->final_dist_p < cut->final_dist_n)
		save_nothing(r, cut);
	else if (cut->final_dist_p > ACC && cut->final_dist_n > ACC
			&& cut->final_dist_p > cut->final_dist_n)
		select_special_case(r, cut);
	else if (cut->final_dist_p == 0)
		select_negative_case(r, cut);
	else if (cut->final_dist_n == 0)
		select_positive_case(r, cut);
}

void				save_dist(t_research *r, t_cut *cut, t_thread *t)
{
	analyze_dist_p_n(r, cut);
	if (cut->final_dist == 0)
		return ;
	else if (cut->final_dist > r->dist[0])
	{
		r->dist[1] = cut->final_dist;
		r->dist[2] = cut->final_dist;
		if (t)
			r->current_obj->solid->plane->cutted_obj[t->num] = cut->cutted_obj;
		else
			r->current_obj->solid->plane->cutted_obj[0] = cut->cutted_obj;
	}
	else if (cut->final_dist > ACC && cut->final_dist < r->dist[0])
		change_dist_zero(r, cut, t);
	else
		change_dist_one(r, cut);
}
