/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboualav <aboualav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 15:08:14 by aboualav          #+#    #+#             */
/*   Updated: 2017/06/21 12:24:54 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

t_color			set_color(int r, int g, int b)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color			copy_color(t_color c)
{
	return (set_color(c.r, c.g, c.b));
}

int				get_color(t_color color)
{
	return ((color.r << 16) + (color.g << 8) + color.b);
}

static void		transform_to_checkerboard(t_color *color, t_record *info)
{
	int square;

	square = (int)floor(info->n_pos.x) + (int)floor(info->n_pos.z);
	if (square % 2 == 0)
	{
		color->r = 0;
		color->g = 0;
		color->b = 0;
	}
	else
	{
		color->r = 0xff;
		color->g = 0xff;
		color->b = 0xff;
	}
}

void			define_obj_color(t_record *info)
{
	if (*info->obj->reflectionx == 10)
		transform_to_checkerboard(&(info->color), info);
}
