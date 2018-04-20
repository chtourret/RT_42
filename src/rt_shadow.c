/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_shadow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 16:49:56 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:02 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		color_add_diffuse(t_color *final_color, t_record *info,
		t_color light_color)
{
	t_color	obj_color;

	obj_color = info->color;
	color_multiply(&obj_color, light_color);
	color_scale(&obj_color, info->cosinus * DIFFUSE);
	color_add(final_color, obj_color);
}

void		calculate_diffuse_and_specular(t_record *info, t_data *d,
		t_color *final_color, t_light *light_list)
{
	t_record	*shadow_info;
	char		shadow;

	shadow_info = NULL;
	shadow = NOT_FOUND;
	info->to_light_ray = init_ray(info->n_pos, info->to_light_dir);
	shadow_info = find_n(info->to_light_ray, d, info->current_thread);
	if (shadow_info)
		if (shadow_info->dist <= info->dist_to_light)
			shadow = FOUND;
	if (shadow == NOT_FOUND)
	{
		color_add_diffuse(final_color, info, light_list->color);
		specular_color(info, final_color, light_list);
	}
	free_info(shadow_info);
}

t_vect		calculate_to_light_dir(t_vect light_pos,
		t_vect n_pos)
{
	substract_to_vector(&light_pos, n_pos);
	light_pos.w = 0;
	return (light_pos);
}

void		add_diffuse_and_specular(t_record *info, t_data *d,
		t_light *light_list, t_color *final_color)
{
	t_record	*shadow_info;

	shadow_info = NULL;
	info->to_light_dir = calculate_to_light_dir(light_list->pos,
			info->n_pos);
	info->dist_to_light = vector_magnitude(info->to_light_dir);
	normalize_vector(&(info->to_light_dir));
	if (dot_product_vector(info->oldnorm, info->to_light_dir) < 0)
		return ;
	info->cosinus = dot_product_vector(info->normal, info->to_light_dir);
	if (info->cosinus > 0)
		calculate_diffuse_and_specular(info, d, final_color, light_list);
	free_info(shadow_info);
}
