/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_get_color_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:21:47 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:04 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

unsigned char	moy(t_color color)
{
	return ((color.r + color.g + color.b) / 3);
}

static t_color	apply_ambient(t_data *d, t_color obj_color)
{
	t_color		final_color;

	final_color = obj_color;
	color_scale(&final_color, d->ambient);
	return (final_color);
}

t_color			*get_color_at(t_data *d, t_record *info)
{
	t_color		final_color;
	t_light		*light_list;
	static int	reflect[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	int			thread_number;

	info->oldnorm = info->normal;
	thread_number = info->current_thread->num;
	final_color = apply_ambient(d, get_pixel_color(d, info, info->obj->type));
	light_list = d->light_list;
	while (light_list)
	{
		add_diffuse_and_specular(info, d, light_list, &final_color);
		light_list = light_list->next;
	}
	if (++reflect[thread_number] <= d->reflections)
		add_refls(d, info, &final_color);
	info->color = final_color;
	reflect[thread_number] = 0;
	return (&(info->color));
}
