/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_scene_movement.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:20:23 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:29:41 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	event_mov_fwd(t_data *d)
{
	normalize_vector(&d->cam.dir);
	add_to_vector(&(d->cam.pos), (d->cam.dir));
	create_cam(&d->cam, d);
	remake(d);
}

void	event_mov_bwd(t_data *d)
{
	normalize_vector(&d->cam.dir);
	substract_to_vector(&(d->cam.pos), (d->cam.dir));
	create_cam(&d->cam, d);
	remake(d);
}

void	event_mov_strafe_lft(t_data *d)
{
	normalize_vector(&d->cam.dir);
	add_to_vector(&(d->cam.pos), (d->cam.left));
	create_cam(&d->cam, d);
	remake(d);
}

void	event_mov_strafe_rgt(t_data *d)
{
	normalize_vector(&d->cam.dir);
	substract_to_vector(&(d->cam.pos), (d->cam.left));
	create_cam(&d->cam, d);
	remake(d);
}
