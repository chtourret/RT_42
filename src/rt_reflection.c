/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_reflection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 16:35:33 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:02 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		add_refl_color(t_color *final_color, t_color refl_color,
		double refl_degree)
{
	color_scale(&refl_color, refl_degree);
	color_add(final_color, refl_color);
}

t_vect		calculate_refl_dir(t_record *info)
{
	double dot_product;
	t_vect ray_dir;
	t_vect refl_dir;

	ray_dir = info->ray.dir;
	negative_vector(&ray_dir);
	dot_product = dot_product_vector(ray_dir, info->normal);
	refl_dir = info->normal;
	mult_vector(&refl_dir, dot_product * 2);
	add_to_vector(&refl_dir, info->ray.dir);
	normalize_vector(&refl_dir);
	return (refl_dir);
}

void		calculate_refl_ray(t_record *info)
{
	info->refl_dir = calculate_refl_dir(info);
	info->refl_ray = init_ray(info->n_pos, info->refl_dir);
}

void		add_refls(t_data *d, t_record *info, t_color *final_color)
{
	t_record	*refl_info;
	t_color		*color;

	refl_info = NULL;
	if (*info->obj->reflectionx <= 1 && *info->obj->reflectionx > 0)
	{
		calculate_refl_ray(info);
		refl_info = find_n(info->refl_ray, d, info->current_thread);
		if (refl_info)
		{
			refl_info->current_thread = info->current_thread;
			color = get_color_at(d, refl_info);
			refl_info->color = *color;
			add_refl_color(final_color, refl_info->color,
					*info->obj->reflectionx);
		}
	}
	free_info(refl_info);
}
