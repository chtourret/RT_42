/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_pro_recolor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 04:57:51 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:06 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		img_b_n_w(t_color c)
{
	t_color				new;
	unsigned int		k;

	k = (c.b * 0.07 + c.g * 0.72 + c.r * 0.21);
	new.b = k;
	new.g = k;
	new.r = k;
	return (get_color(new));
}

int		img_sepia(t_color c)
{
	t_color				new;

	if ((new.r = 0.393 * c.r + 0.769 * c.g + 0.189 * c.b) > 255)
		new.r = 255;
	if ((new.g = 0.349 * c.r + 0.686 * c.g + 0.168 * c.b) > 255)
		new.g = 255;
	if ((new.b = 0.272 * c.r + 0.534 * c.g + 0.131 * c.b) > 255)
		new.b = 255;
	return (get_color(new));
}

int		img_negative(t_color c)
{
	t_color				new;

	new.b = 255 - c.b;
	new.g = 255 - c.g;
	new.r = 255 - c.r;
	return (get_color(new));
}
