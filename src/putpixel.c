/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 16:28:34 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:06 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	putpixel(int x, int y, unsigned int color, t_img *img)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char t;

	b = (color & 0xFF) >> 0;
	g = (color & 0xFF00) >> 8;
	r = (color & 0xFF0000) >> 16;
	t = (color & 0xFF000000) >> 24;
	t = 0;
	if (img->endian == 0)
	{
		img->data[(y * img->sl) + x * (img->bpp >> 3)] = b;
		img->data[(y * img->sl) + x * (img->bpp >> 3) + 1] = g;
		img->data[(y * img->sl) + x * (img->bpp >> 3) + 2] = r;
		img->data[(y * img->sl) + x * (img->bpp >> 3) + 3] = t;
	}
	else
	{
		img->data[y * img->sl + x * img->bpp / 8] = (color & 0xFF) >> 0;
		img->data[y * img->sl + x * img->bpp / 8 + 1] = (color & 0xFF00) >> 8;
		img->data[y * img->sl + x * img->bpp / 8 + 2] =
			(color & 0xFF0000) >> 16;
	}
}
