/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_pro_hub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 04:57:41 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:41:46 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color		img_pull_pixel(int x, int y, t_img *img)
{
	t_color	c;

	if (img->x && img->y)
	{
		while (x < 0)
			x += img->x;
		while (y < 0)
			y += img->y;
		x = x % img->x;
		y = y % img->y;
	}
	c.b = img->data[y * img->sl + x * (img->bpp >> 3)] & 0xFF;
	c.g = img->data[y * img->sl + x * (img->bpp >> 3) + 1] & 0xFF00 >> 8;
	c.r = img->data[y * img->sl + x * (img->bpp >> 3) + 2] & 0xFF0000 >> 16;
	return (c);
}

t_img		*img_map_pixel(t_data *d, int (*f)(t_color))
{
	int		x;
	int		y;
	t_color	c;
	t_img	*img;

	img = init_img(d->mlx, d->width, d->height);
	x = -1;
	while (++x < d->width)
	{
		y = -1;
		while (++y < d->height)
		{
			c = img_pull_pixel(x, y, d->img);
			putpixel(x, y, f(c), img);
		}
	}
	return (img);
}

void		img_recolor(t_data *d, int (*f)(t_color))
{
	t_img	*img;

	img = img_map_pixel(d, f);
	mlx_clear_window(d->mlx, d->win);
	mlx_put_image_to_window(d->mlx, d->win, img->img, 0, 0);
	free_img(d->mlx, img);
}

void		**init_post_pro(void)
{
	void	**p_p;

	p_p = (void **)ft_memalloc(sizeof(void *) * 5);
	p_p[0] = &img_b_n_w;
	p_p[1] = &img_sepia;
	p_p[2] = &img_negative;
	p_p[3] = &img_b_n_w;
	p_p[4] = &img_b_n_w;
	return (p_p);
}
