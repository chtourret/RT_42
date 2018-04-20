/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_cam_populators.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 04:57:30 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:36 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		populatelight(int fd, t_p_cache *cache, t_light **lst)
{
	t_light	*light;
	char	lineid;

	if (cache->scope > 1)
		ft_parsing_error(POS, "light should only be defined at root", FN);
	light = init_light();
	while ((cache->linelen = get_next_line(fd, &cache->line)) > 0)
	{
		POS++;
		lineid = line_identifier(cache);
		if (lineid == CONTEXT_CLOSER)
			break ;
		else if (lineid == DECLARATOR)
			ft_parsing_error(POS, "light cannot support items", FN);
		else if (lineid == PARAMETER)
			manage_light_params(cache, light);
		free(cache->line);
	}
	push_light(lst, light);
}

void		populatecamera(int fd, t_p_cache *cache)
{
	char	lineid;

	if (cache->scope > 1)
		ft_parsing_error(POS, "camera should only be defined at root", FN);
	while ((cache->linelen = get_next_line(fd, &cache->line)) > 0)
	{
		POS++;
		lineid = line_identifier(cache);
		if (lineid == CONTEXT_CLOSER)
			break ;
		else if (lineid == DECLARATOR)
			ft_parsing_error(POS, "camera cannot support  items", FN);
		else if (lineid == PARAMETER)
			manage_camera_params(cache, &cache->d->cam);
		free(cache->line);
		cache->d->cam.pos.x += ACC;
		cache->d->cam.pos.y += ACC;
		cache->d->cam.pos.z += ACC;
	}
}
