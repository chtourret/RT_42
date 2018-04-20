/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 04:55:58 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:31:21 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vect		get_first_pix_dir(t_cam cam)
{
	t_vect first_pixel_pos;
	t_vect first_pixel_dir;

	mult_vector(&cam.dir, cam.cam_plane_dist);
	mult_vector(&cam.up, cam.plane_height / 2.0);
	mult_vector(&cam.left, cam.plane_width / 2.0);
	first_pixel_pos = cam.pos;
	add_to_vector(&first_pixel_pos, cam.dir);
	add_to_vector(&first_pixel_pos, cam.up);
	add_to_vector(&first_pixel_pos, cam.left);
	first_pixel_dir = init_vector(first_pixel_pos.x - cam.pos.x,
			first_pixel_pos.y - cam.pos.y, first_pixel_pos.z - cam.pos.z, 0);
	normalize_vector(&first_pixel_dir);
	return (first_pixel_dir);
}

void				create_cam(t_cam *cam, t_data *d)
{
	t_vect	dir;

	normalize_vector(&(cam->dir));
	cam->cam_plane_dist = 1;
	cam->plane_width = 1;
	cam->plane_height = (double)d->height / (double)d->width;
	cam->up = init_vector(0, 1, 0, 0);
	dir = cam->dir;
	negative_vector(&dir);
	cam->left = cross_product_vector(dir, cam->up);
	cam->up = cross_product_vector(cam->left, dir);
	cam->first_pixel_dir = get_first_pix_dir(*cam);
}
