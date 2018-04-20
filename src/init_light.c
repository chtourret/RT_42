/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:20:58 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:46 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_light		*init_light(void)
{
	t_light *light;

	light = (t_light *)ft_memalloc(sizeof(t_light));
	light->pos.x = 0;
	light->pos.y = 0;
	light->pos.z = 0;
	light->color.r = 255;
	light->color.g = 255;
	light->color.b = 255;
	light->next = NULL;
	return (light);
}
