/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 21:19:54 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:28:45 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		remake(t_data *d)
{
	raytracer(d);
	mlx_clear_window(d->mlx, d->win);
	mlx_put_image_to_window(d->mlx, d->win, d->img->img, 0, 0);
	add_eblouissement(d);
}

void		display_again(t_data *d)
{
	mlx_clear_window(d->mlx, d->win);
	mlx_put_image_to_window(d->mlx, d->win, d->img->img, 0, 0);
}

void		display_scenes(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img_bg, 0, 0);
	foreach_d_thumbnail(e);
}
