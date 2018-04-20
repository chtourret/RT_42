/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scenes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:23:46 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:38 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <dirent.h>

void			g_scene(t_data *d, char *name)
{
	int			fd;
	char		*path;

	if (!(path = ft_strnew(ft_strlen(name) + ft_strlen("scenes/") + 1)))
		ft_malloc_error();
	ft_strcat(path, "scenes/");
	ft_strcat(path, name);
	if ((fd = open(path, O_RDONLY)) < 3)
		ft_parsing_error(0, "file opening error", name);
	lexer(fd, name);
	close(fd);
	if ((fd = open(path, O_RDONLY)) < 3)
		ft_parsing_error(0, "file re-opening error", name);
	parser(fd, d, name);
	free(path);
}

t_data			*create_scene_d(t_env *e, char *name)
{
	t_data		*d;

	d = (t_data *)ft_memalloc(sizeof(t_data));
	init_data_zero(d);
	d->mlx = e->mlx;
	d->win = e->win;
	g_scene(d, name);
	d->width = 250;
	d->height = 175;
	d->dpp = d->aa_lvl * d->aa_lvl;
	d->tld = 0;
	d->func = init_function();
	create_cam(&(d->cam), d);
	d->img = init_img(d->mlx, d->width, d->height);
	return (d);
}

void			load_scenes(t_env *e)
{
	t_scene	*tmp;

	e->lst_scene = get_scene_list();
	tmp = e->lst_scene;
	while (tmp)
	{
		tmp->d = create_scene_d(e, tmp->name);
		tmp = tmp->next;
		e->lst_size++;
	}
	e->page_m = e->lst_size / 6;
	if (e->lst_size % 6)
		e->page_m++;
}
