/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 16:50:16 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:41:37 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		add_specular_color(t_color *final_color, t_color light_color,
		double specular, double degree)
{
	specular = pow(specular, 10);
	color_scale(&light_color, specular * degree);
	color_add(final_color, light_color);
}

void		calculate_specular_color(t_color *final_color, t_color light_color,
		t_record *info)
{
	double specular;

	calculate_refl_ray(info);
	specular = dot_product_vector(info->refl_dir, info->to_light_dir);
	if (specular > 0)
		add_specular_color(final_color, light_color, specular,
				*info->obj->shinex);
}

void		specular_color(t_record *info, t_color *final_color,
		t_light *light_list)
{
	if (*info->obj->shinex > 0 && *info->obj->shinex <= 1)
		calculate_specular_color(final_color, light_list->color, info);
}
