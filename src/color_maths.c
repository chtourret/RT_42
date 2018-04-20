/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_maths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 04:53:43 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:39:28 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

void		color_scale(t_color *color, double scalar)
{
	color->r = (int)((double)color->r * scalar);
	if (color->r > 255)
		color->r = 255;
	color->g = (int)((double)color->g * scalar);
	if (color->g > 255)
		color->g = 255;
	color->b = (int)((double)color->b * scalar);
	if (color->b > 255)
		color->b = 255;
}

void		color_add(t_color *c1, t_color c2)
{
	c1->r += c2.r;
	if (c1->r > 255)
		c1->r = 255;
	c1->g += c2.g;
	if (c1->g > 255)
		c1->g = 255;
	c1->b += c2.b;
	if (c1->b > 255)
		c1->b = 255;
}

void		color_add_nolimit(t_color *c1, t_color c2)
{
	c1->r += c2.r;
	c1->g += c2.g;
	c1->b += c2.b;
}

void		color_divide(t_color *c, double d)
{
	c->r = (int)(((double)c->r) / d);
	c->g = (int)(((double)c->g) / d);
	c->b = (int)(((double)c->b) / d);
}

void		color_multiply(t_color *c1, t_color c2)
{
	double r_intensity;
	double g_intensity;
	double b_intensity;

	r_intensity = (double)c2.r / 0xFF;
	g_intensity = (double)c2.g / 0xFF;
	b_intensity = (double)c2.b / 0xFF;
	c1->r = (int)((double)(c1->r) * r_intensity);
	c1->g = (int)((double)(c1->g) * g_intensity);
	c1->b = (int)((double)(c1->b) * b_intensity);
}
