/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_scene_tmb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 03:19:22 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:27:15 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		print_thmb_nb(t_data *d, int nb, char *name)
{
	static int		x[3] = {80, 380, 680};
	static int		y[2] = {100, 350};
	unsigned int	i;
	unsigned int	j;
	char			*str;

	i = x[nb % 3];
	j = y[nb / 3];
	str = get_scene_name(nb, name);
	mlx_put_image_to_window(d->mlx, d->win, d->img->img, i, j);
	mlx_string_put(d->mlx, d->win, i + 10, j + 180, 0xFFFFFF, str);
	free(str);
}

void			dirty_override(t_data *d)
{
	double		aa;
	double		dp;

	aa = d->aa_lvl;
	dp = d->dpp;
	d->aa_lvl = 1;
	d->dpp = 1;
	raytracer(d);
	d->aa_lvl = aa;
	d->dpp = dp;
}

static t_scene	*get_list_from_page(t_scene *lst, int p)
{
	int			cpt;
	t_scene		*tmp;

	tmp = lst;
	cpt = 0;
	while (tmp && (cpt++ / 6 < p))
		tmp = tmp->next;
	return (tmp);
}

void			foreach_d_thumbnail(t_env *e)
{
	t_scene		*tmp;
	int			cpt;

	cpt = 0;
	print_page_string(e);
	tmp = get_list_from_page(e->lst_scene, e->page);
	while (tmp && cpt < 6)
	{
		if ((tmp->d->tld == 0) ? tmp->d->tld = 1 : 0)
			dirty_override(tmp->d);
		print_thmb_nb(tmp->d, cpt, tmp->name);
		cpt++;
		tmp = tmp->next;
	}
}
