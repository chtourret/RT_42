/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:20:08 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:29:00 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			ft_close_cross(t_env *e)
{
	free_env(e);
	ft_putstr("Program closed successfully\n");
	exit(0);
}

int			events_mouse(int button, int x, int y, t_env *e)
{
	if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT)
	{
		if (e->in_menu == 0)
			events_mouse_scene(button, x, y, e->current_scene);
		else
			events_mouse_menu(button, x, y, e);
	}
	return (0);
}

void		back_to_the_menu(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	free_img(e->mlx, e->current_scene->img);
	free(e->current_scene);
	e->current_scene = NULL;
	e->in_menu = 1;
	display_scenes(e);
}

int			events_key(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
		ft_close_cross(e);
	else if (keycode == KEY_F2)
		reload_env(e);
	else if (e->in_menu == 1)
		events_key_menu(keycode, e);
	else
	{
		if (keycode == 82 || keycode == KEY_BACKSPACE)
			back_to_the_menu(e);
		events_key_scene(keycode, e->current_scene);
		if (keycode == KEY_H)
		{
			e->cmd = (e->cmd == 1) ? 0 : 1;
			display_again(e->current_scene);
			if (e->cmd)
				mlx_put_image_to_window(e->mlx, e->win, e->img_cmd, 0, 440);
		}
	}
	return (0);
}
