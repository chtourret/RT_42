/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_pro_img_anaglyph.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 04:57:44 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:07 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_img		*img_anaglyph_fuse(t_data *d, t_img *blu, t_img *red)
{
	int		x;
	int		y;
	t_color	c_red;
	t_color c_blu;
	t_img	*fuse;

	fuse = init_img(d, d->width, d->height);
	x = -1;
	while (++x < d->width)
	{
		y = -1;
		while (++y < d->height)
		{
			c_red = img_pull_pixel(x, y, red);
			c_blu = img_pull_pixel(x, y, blu);
			putpixel(x, y,
				get_color((t_color){c_red.r, c_blu.g, c_blu.b}), fuse);
		}
	}
	return (fuse);
}

void		img_anaglyph(t_data *d)
{
	t_img	*save;
	t_img	*fuse;

	save = d->img;
	d->cam.pos.x++;
	create_cam(&(d->cam), d);
	d->img = init_img(d, d->width, d->height);
	raytracer(d);
	fuse = img_anaglyph_fuse(d, d->img, save);
	mlx_put_image_to_window(d->mlx, d->win, fuse->img, 0, 0);
	free(d->img);
	free(fuse);
	d->img = save;
	d->cam.pos.x--;
	create_cam(&(d->cam), d);
}
