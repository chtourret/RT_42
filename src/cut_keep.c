/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_keep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 22:07:19 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:25:46 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			keep_plane(t_cut *cut)
{
	if (cut->dot > 0)
	{
		if ((cut->final_dist_p == 0 && cut->plane[2] > cut->final_dist_p) ||
				(cut->final_dist_p > ACC && cut->plane[2] < cut->final_dist_p
					&& cut->plane[2] > ACC))
		{
			cut->closest_positive = cut->current_obj;
			cut->closest_positive_ray = cut->modified_ray;
			cut->final_dist_p = cut->plane[2];
			cut->c_p = cut->c;
		}
	}
	else
	{
		if (cut->plane[2] > cut->final_dist_n && cut->plane[2] > ACC)
		{
			cut->closest_negative = cut->current_obj;
			cut->closest_negative_ray = cut->modified_ray;
			cut->final_dist_n = cut->plane[2];
			cut->c_n = cut->c;
		}
	}
	return (1);
}

int			keep_nothing(t_research *r, t_cut *cut)
{
	r->dist[0] = 0;
	r->dist[1] = 0;
	r->dist[2] = 0;
	cut->final_dist = 0;
	r->current_obj = cut->cutted_obj;
	cut->final_dist_p = 0;
	cut->final_dist_n = 0;
	cut->closest_negative = NULL;
	cut->closest_positive = NULL;
	return (0);
}
