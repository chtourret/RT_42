/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:11:17 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:28 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	main_loop(t_env *e)
{
	if (e->rendering == 1)
	{
		remake(e->current_scene);
		e->rendering = 0;
	}
	if (e->loading == 1)
	{
		load_scenes(e);
		display_scenes(e);
		e->loading = 0;
	}
	return (1);
}

int			mlx_hub(t_env *e)
{
	mlx_loop_hook(e->mlx, &main_loop, e);
	mlx_hook(e->win, 2, 1, events_key, e);
	mlx_hook(e->win, 4, 1, events_mouse, e);
	mlx_hook(e->win, 17, (1L << 17), ft_close_cross, e);
	mlx_loop(e->mlx);
	return (0);
}

int			welcome_to_rt(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img_wel, 0, 0);
	return (1);
}

int			main(void)
{
	t_env	*e;

	e = init_env();
	if (!welcome_to_rt(e))
		ft_error();
	mlx_hub(e);
	return (0);
}
