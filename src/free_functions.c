/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 04:54:21 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:29:57 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_func		*free_function(void **f)
{
	if (f)
		free(f);
	f = NULL;
	return (NULL);
}

static t_func		*free_func_lst(t_func *func)
{
	if (func)
	{
		free_function(func->get_obj_tf_list);
		free_function(func->get_obj_normal);
		free_function(func->get_obj_color);
		free_function(func->get_obj_n);
		free_function((void **)func->post_pro);
		free(func);
		func = NULL;
	}
	return (NULL);
}

t_obj				*free_obj(t_obj **begin_light_list)
{
	t_obj		*tmp;
	t_obj		*next_tmp;

	tmp = *begin_light_list;
	next_tmp = NULL;
	while (tmp)
	{
		next_tmp = tmp->next;
		select_free_obj(tmp);
		free(tmp->solid);
		tmp->solid = NULL;
		free(tmp);
		tmp = next_tmp;
	}
	*begin_light_list = NULL;
	return (NULL);
}

void				free_scene_list(t_scene *s)
{
	t_scene		*tmp_0;
	t_scene		*tmp_1;

	tmp_0 = s;
	if (tmp_0)
		while (tmp_0)
		{
			tmp_1 = tmp_0->next;
			free_data(tmp_0->d);
			free(tmp_0);
			tmp_0 = tmp_1;
		}
}

void				free_data(t_data *d)
{
	if (d)
	{
		if (d->light_list)
			free_light_list(&(d->light_list));
		if (d->obj)
			free_obj(&(d->obj));
		if (d->func)
			free_func_lst(d->func);
		if (d->texturelist)
			free_texture(d->mlx, d->texturelist);
		if (d->img)
			free_img(d->mlx, d->img);
		free(d);
		d = NULL;
	}
}
