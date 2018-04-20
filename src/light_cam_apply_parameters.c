/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_cam_apply_parameters.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 13:14:58 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:36 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	manage_light_params(t_p_cache *cache, t_light *light)
{
	disect_param(cache->line, &PARAM_NAME, &PARAMS);
	if (ft_strcmp(PARAM_NAME, "position") == 0 && chk(PARAMS, 3,
				parsetest_vector, cache))
		light->pos = init_vector(TWO_ATOF,
				ft_atof(PARAMS[2]), 1);
	else if (ft_strcmp(PARAM_NAME, "color") == 0 &&
			chk(PARAMS, 3, tf, cache))
		light->color = set_color(ft_atoi(PARAMS[0]), ft_atoi(PARAMS[1]),
				ft_atoi(PARAMS[2]));
	else
		ft_parsing_error(POS,
				"unsupported parameter passed to light object", FN);
}

void	manage_camera_params(t_p_cache *cache, t_cam *cam)
{
	disect_param(cache->line, &PARAM_NAME, &PARAMS);
	if (ft_strcmp(PARAM_NAME, "position") == 0 && chk(PARAMS, 3,
				parsetest_vector, cache))
		cam->pos = init_vector(TWO_ATOF,
				ft_atof(PARAMS[2]), 1);
	else if (ft_strcmp(PARAM_NAME, "orientation") == 0 && chk(PARAMS,
				3, parsetest_vector, cache))
		cam->dir = init_vector(TWO_ATOF,
				ft_atof(PARAMS[2]), 1);
	else if (ft_strcmp(PARAM_NAME, "look_at") == 0 && chk(PARAMS, 3,
				parsetest_vector, cache))
		cam->dir = init_vector(ft_atof(PARAMS[0]) - cam->pos.x,
				ft_atof(PARAMS[1]) - cam->pos.y,
				ft_atof(PARAMS[2]) - cam->pos.z, 0);
	else
		ft_parsing_error(POS,
				"unsupported parameter passed to camera object", FN);
	normalize_vector(&cam->dir);
}

void	manage_root_parameters(t_p_cache *cache, t_data *d)
{
	disect_param(cache->line, &PARAM_NAME, &PARAMS);
	if (ft_strcmp(PARAM_NAME, "window_size") == 0 &&
			chk(PARAMS, 2, tf, cache))
	{
		d->width = ft_atoi(PARAMS[0]);
		d->height = ft_atoi(PARAMS[1]);
	}
	else if (ft_strcmp(PARAM_NAME, "AAlvl") == 0 &&
			chk(PARAMS, 1, tf, cache))
		d->aa_lvl = ft_atoi(PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "reflections") == 0 &&
			chk(PARAMS, 1, tf, cache))
		d->reflections = ft_atoi(PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "ambient") == 0 &&
			chk(PARAMS, 1, tf, cache))
		d->ambient = ft_atof(PARAMS[0]);
	else
		ft_parsing_error(POS,
				"unsupported parameter passed to root object", FN);
}
