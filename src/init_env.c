/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctourret <ctourret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:16:09 by ctourret          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:48 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		env_bzero(t_env *e)
{
	e->lst_scene = NULL;
	e->current_scene = NULL;
	e->page = 0;
	e->page_m = 0;
	e->lst_size = 0;
	e->in_menu = 1;
	e->butt_lst = NULL;
	e->w = WIDTH;
	e->h = HEIGHT;
	e->rendering = 0;
	e->loading = 0;
	e->cmd = 0;
}

t_env		*init_env(void)
{
	t_env		*e;

	e = (t_env *)malloc(sizeof(t_env));
	env_bzero(e);
	e->mlx = NULL;
	e->win = NULL;
	if ((e->mlx = mlx_init()) == NULL)
		ft_malloc_error();
	if ((e->win = mlx_new_window(e->mlx, e->w, e->h, "RT")) == NULL)
		ft_malloc_error();
	if ((!(e->img_bg = mlx_xpm_file_to_image(e->mlx, "xpm/plainBG.xpm",
				&e->w, &e->h))) ||
			(!(e->img_wel = mlx_xpm_file_to_image(e->mlx, "xpm/welcome.xpm",
				&e->w, &e->h))) ||
			(!(e->img_rendering = mlx_xpm_file_to_image(e->mlx, "xpm/rend.xpm",
				&e->w, &e->h))) ||
			(!(e->img_loading = mlx_xpm_file_to_image(e->mlx, "xpm/loading.xpm",
				&e->w, &e->h))) ||
			(!(e->img_cmd = mlx_xpm_file_to_image(e->mlx, "xpm/cmd.xpm",
				&e->w, &e->h))))
		ft_error();
	return (e);
}

void		reload_env(t_env *e)
{
	if (e->lst_scene)
		free_scene_list(e->lst_scene);
	if (e->current_scene)
		free(e->current_scene);
	if (e->butt_lst)
		free_butt(e->butt_lst);
	env_bzero(e);
	welcome_to_rt(e);
}

void		free_butt(t_butt *b)
{
	t_butt		*tmp_0;
	t_butt		*tmp_1;

	tmp_0 = b;
	if (tmp_0)
		while (tmp_0)
		{
			tmp_1 = tmp_0->next;
			free(tmp_0);
			tmp_0 = tmp_1;
		}
}

void		free_env(t_env *e)
{
	if (e)
	{
		if (e->lst_scene)
			free_scene_list(e->lst_scene);
		if (e->current_scene)
		{
			free_img(e->mlx, e->current_scene->img);
			free(e->current_scene);
		}
		if (e->butt_lst)
			free_butt(e->butt_lst);
		free(e);
		e = NULL;
	}
}
