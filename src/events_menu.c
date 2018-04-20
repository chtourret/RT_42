/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:20:01 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:28:53 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		page_manager(t_env *e, int k)
{
	if (k == KEY_LEFT && e->page > 0)
	{
		e->page--;
		display_scenes(e);
	}
	if (k == KEY_RIGHT && e->page + 1 < e->page_m)
	{
		e->page++;
		display_scenes(e);
	}
}

int			events_key_menu(int keycode, t_env *e)
{
	if (!e->lst_scene)
	{
		if (keycode == KEY_ENTER)
		{
			e->loading = 1;
			mlx_put_image_to_window(e->mlx, e->win, e->img_loading, 0, 0);
		}
	}
	else if (e->lst_scene)
	{
		if (keycode >= 83 && keycode <= 88)
			if (select_scene(e, keycode - 83))
			{
				e->rendering = 1;
				mlx_clear_window(e->mlx, e->win);
				mlx_put_image_to_window(e->mlx, e->win, e->img_rendering, 0, 0);
			}
		if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
			page_manager(e, keycode);
	}
	return (0);
}

int			events_mouse_menu(int button, int x, int y, t_env *e)
{
	if (!e->butt_lst)
		e->butt_lst = init_butt();
	if (e->lst_scene && e->butt_lst && button == 1)
		if (select_scene(e, clic_scene(e, x, y)))
			remake(e->current_scene);
	return (0);
}
