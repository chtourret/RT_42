/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_get_pixel_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:47:45 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:03 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

double			get_solid_tex_y(double hit)
{
	double		decimal;

	hit += 1;
	hit /= 2;
	decimal = fmod(hit, 1);
	if (decimal < 0)
		decimal = 1 + decimal;
	return (decimal);
}

t_color			texmodifier(double pos[2], t_texture *tex, t_color c, char alt)
{
	if (tex != NULL)
		c = img_pull_pixel(pos[0] *
			tex->img.x, pos[1] * tex->img.y, &tex->img);
	if (alt == SINX)
		c = set_color(c.r * sin(pos[0] * M_PI), c.g
			* sin(pos[0] * M_PI), c.b * sin(pos[0] * M_PI));
	else if (alt == SINY)
		c = set_color(c.r * sin(pos[1] * M_PI), c.g
			* sin(pos[1] * M_PI), c.b * sin(pos[1] * M_PI));
	else if (alt == SINXY)
		c = set_color(c.r * sin(pos[1] * M_PI) *
			sin(pos[0] * M_PI), c.g * sin(pos[1] * M_PI) *
			sin(pos[0] * M_PI), c.b * sin(pos[1] * M_PI) *
			sin(pos[0] * M_PI));
	else if (alt == QUAD)
		c = ((pos[0] > 0.5 && pos[1] > 0.5) || (pos[0] <
			0.5 && pos[1] < 0.5)) ? set_color(0, 0, 0) : c;
	return (c);
}

int				solid_texturemode(int type)
{
	return (type == SPHERE || type == CYLINDER || type == CONE ||
			type == HYPERBOLOID || type == PARABOLOID);
}

void			bumpmap_normal(double x, double y, t_record *info)
{
	t_vect		result;
	t_texture	*tex;
	double		res[5];

	if ((tex = bumpmapgetter(info->obj->type, info->obj)) == NULL)
		return ;
	res[0] = GET_COLOR_MOY(x * tex->img.x, y * tex->img.y + 1);
	res[1] = GET_COLOR_MOY(x * tex->img.x - 1, y * tex->img.y);
	res[2] = GET_COLOR_MOY(x * tex->img.x, y * tex->img.y);
	res[3] = GET_COLOR_MOY(x * tex->img.x, y * tex->img.y - 1);
	res[4] = GET_COLOR_MOY(x * tex->img.x + 1, y * tex->img.y);
	result.y = res[2];
	result.z = res[0] - res[3];
	result.x = res[4] - res[1];
	if (result.x == 0 && result.y == 0 && result.z == 0)
		return ;
	info->oldnorm = info->normal;
	normalize_vector(&result);
	if (info->obj->type == PLANE)
		info->normal = result;
	else if (!(result.x == 0 && result.y == 1 && result.z == 0))
		if (solid_texturemode(info->obj->type))
			info->normal = get_bumped_vect(info->normal, result);
	if (dot_product_vector(info->normal, info->oldnorm) < 0)
		info->normal = info->oldnorm;
}

t_color			get_pixel_color(t_data *d, t_record *info, int type)
{
	t_vect		hitpos;
	t_texture	*tex;
	double		pos[2];

	hitpos = info->n_pos;
	apply_inverse_tf(info->obj, &hitpos, d);
	if (solid_texturemode(type))
	{
		pos[0] = ((atan2(hitpos.x, hitpos.z) + M_PI) / (2 * M_PI));
		pos[1] = get_solid_tex_y(hitpos.y);
	}
	else if (type == PLANE)
	{
		pos[0] = get_solid_tex_y(hitpos.z);
		pos[1] = get_solid_tex_y(hitpos.x);
	}
	else
		return (info->color);
	pos[0] = texoffx(type, info->obj, texscalex(type, info->obj, pos[0]));
	pos[1] = texoffy(type, info->obj, texscaley(type, info->obj, pos[1]));
	tex = texturegetter(info->obj->type, info->obj);
	info->color = texmodifier(pos, tex, info->color,
		texmodifiergetter(info->obj->type, info->obj));
	bumpmap_normal(pos[0], pos[1], info);
	return (info->color);
}
