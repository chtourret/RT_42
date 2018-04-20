/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_select_scene.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 22:37:48 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:29:50 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		init_data_zero(t_data *d)
{
	d->mlx = NULL;
	d->win = NULL;
	d->img = NULL;
	d->obj = NULL;
	d->texturelist = NULL;
	d->light_list = NULL;
	d->func = NULL;
	d->width = WIDTH;
	d->height = HEIGHT;
	d->x = 0;
	d->y = 0;
	d->ambient = 0.2;
	d->aa_lvl = 1;
	d->dpp = 1;
	d->cam.pos = (t_vect){0, 0.0000000001, 7, 1};
	d->reflections = REFLECTIONS;
}

t_data		*copy_scene(t_scene *src)
{
	t_data *d;

	d = (t_data *)ft_memalloc(sizeof(t_data));
	init_data_zero(d);
	d = ft_memcpy(d, src->d, sizeof(t_data));
	d->width = WIDTH;
	d->height = HEIGHT;
	d->img = init_img(d->mlx, d->width, d->height);
	create_cam(&(d->cam), d);
	return (d);
}

int			select_scene(t_env *e, int k)
{
	t_scene		*tmp;
	int			cpt;

	if (k >= 0 && k < 6 && k < e->lst_size)
	{
		k = k + 6 * e->page;
		if (k >= e->lst_size)
			return (0);
		tmp = e->lst_scene;
		cpt = 0;
		while (tmp && cpt < k)
		{
			tmp = tmp->next;
			cpt++;
		}
		e->current_scene = copy_scene(tmp);
		e->in_menu = 0;
		return (1);
	}
	return (0);
}

int			clic_scene(t_env *e, int x, int y)
{
	t_butt	*tmp;

	tmp = e->butt_lst;
	while (tmp)
	{
		if (x >= tmp->xmin && x <= tmp->xmax)
			if (y >= tmp->ymin && y <= tmp->ymax)
				return (tmp->moon);
		tmp = tmp->next;
	}
	return (-1);
}
