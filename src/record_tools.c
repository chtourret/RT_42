/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 19:02:28 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:05 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		free_info(t_record *info)
{
	if (info)
	{
		free(info);
		info = NULL;
	}
}

void		init_info_zero(t_record *info)
{
	info->obj = NULL;
	info->oldnorm = init_vector(0, 0, 0, 1);
	info->n_pos = init_vector(0, 0, 0, 0);
	info->refl_dir = init_vector(0, 0, 0, 0);
	info->to_light_dir = init_vector(0, 0, 0, 0);
	info->oldnorm = init_vector(0, 0, 0, 0);
	info->normal = init_vector(0, 0, 0, 0);
	info->refl_ray.ori = init_vector(0, 0, 0, 0);
	info->to_light_ray.ori = init_vector(0, 0, 0, 0);
	info->ray.ori = init_vector(0, 0, 0, 0);
	info->refl_ray.dir = init_vector(0, 0, 0, 0);
	info->to_light_ray.dir = init_vector(0, 0, 0, 0);
	info->ray.dir = init_vector(0, 0, 0, 0);
	info->dist_to_light = -1;
	info->cosinus = -1;
	info->dist = -1;
	info->type = -1;
	info->current_thread = NULL;
	info->obj = NULL;
	info->color = set_color(0, 0, 0);
}
