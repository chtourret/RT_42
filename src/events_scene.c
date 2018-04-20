/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 18:55:33 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:29:45 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		events_key_scene2(int keycode, t_data *d)
{
	if (keycode == KEY_UP)
		event_mov_look_up(d);
	if (keycode == KEY_DOWN)
		event_mov_look_down(d);
	if (keycode == KEY_R)
		event_mov_up(d);
	if (keycode == KEY_F)
		event_mov_dwn(d);
	if (keycode == 50)
		add_eblouissement(d);
}

int				events_key_scene(int keycode, t_data *d)
{
	if (keycode == KEY_SPACE)
		remake(d);
	if (keycode == KEY_P)
		display_again(d);
	if (keycode >= KEY_1 && keycode <= KEY_4)
		img_recolor(d, (int (*)(t_color c))d->func->post_pro[keycode - KEY_1]);
	if (keycode == KEY_W)
		event_mov_fwd(d);
	if (keycode == KEY_S)
		event_mov_bwd(d);
	if (keycode == KEY_A)
		event_mov_strafe_lft(d);
	if (keycode == KEY_D)
		event_mov_strafe_rgt(d);
	if (keycode == KEY_LEFT)
		event_mov_look_left(d);
	if (keycode == KEY_RIGHT)
		event_mov_look_right(d);
	events_key_scene2(keycode, d);
	return (0);
}

char			*display_object_stats(t_data *d, t_obj *hitted_obj)
{
	char		*str;
	static char	*type[10] = {"Zero", "Sphere", "Plane", "Cylinder", "Cone",
		"Triangle", "Prism", "Cube", "Paraboloid", "Hyperboloid"};

	(void)(d);
	if (!(str = ft_strnew(20)))
		ft_malloc_error();
	str = ft_strcat(str, "Type :");
	str = ft_strcat(str, type[hitted_obj->type + 1]);
	return (str);
}

t_obj			*find_hit(t_ray ray, t_data *d, t_thread *thread)
{
	t_research		r;
	t_obj			*tmp_current;

	init_var(&r, ray);
	r.current_obj = d->obj;
	while (r.current_obj)
	{
		tmp_current = r.current_obj;
		r.modified_ray = ray;
		find_n_dist(&r, d, thread);
		if ((r.dist[2] > r.final_dist && r.final_dist == 0
			&& r.dist[2] > ACC) || (r.dist[2] < r.final_dist &&
			r.final_dist > 0 && r.dist[2] > ACC))
		{
			r.final_dist = r.dist[2];
			r.closest_obj = r.current_obj;
			r.final_ray = r.modified_ray;
		}
		if (tmp_current->next == NULL && r.final_dist > ACC)
			return (r.closest_obj);
		r.current_obj = tmp_current->next;
	}
	return (NULL);
}

int				events_mouse_scene(int button, int x, int y, t_data *d)
{
	t_obj		*hit_obj;
	char		*str;

	hit_obj = NULL;
	str = NULL;
	display_again(d);
	if (button == 1)
	{
		if ((hit_obj = find_hit(calculate_ray(d, x, y, NULL), d, NULL)))
		{
			str = display_object_stats(d, hit_obj);
			mlx_string_put(d->mlx, d->win, 6, 6, 0xFFFFFF, str);
			mlx_string_put(d->mlx, d->win, 5, 5, 0xFFFFFF, str);
		}
	}
	return (1);
}
