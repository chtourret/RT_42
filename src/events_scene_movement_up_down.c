/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_scene_movement_up_down.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:17:09 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:29:34 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	event_mov_dwn(t_data *d)
{
	normalize_vector(&d->cam.dir);
	substract_to_vector(&(d->cam.pos), init_vector(0, 1, 0, 1));
	create_cam(&d->cam, d);
	remake(d);
}

void	event_mov_up(t_data *d)
{
	normalize_vector(&d->cam.dir);
	add_to_vector(&(d->cam.pos), init_vector(0, 1, 0, 1));
	create_cam(&d->cam, d);
	remake(d);
}
