/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_apply_parameters_complex.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 13:08:44 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:13 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	manage_paraboloid_params(t_p_cache *cache, t_paraboloid *paraboloid)
{
	disect_param(cache->line, &PARAM_NAME, &PARAMS);
	if (ft_strcmp(PARAM_NAME, "color") == 0 && chk(PARAMS, 3, tf, cache))
		paraboloid->color = set_color(ft_atoi(cache->params[0]),
				ft_atoi(cache->params[1]), ft_atoi(cache->params[2]));
	else if (ft_strcmp(PARAM_NAME, "shine") == 0 && chk(PARAMS, 1, tf, cache))
		paraboloid->shine = ft_atof(PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "reflection") == 0
		&& chk(PARAMS, 1, tf, cache))
		paraboloid->reflection = ft_atof(PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "texture") == 0 && chk(PARAMS, 1, tf, cache))
		paraboloid->texture = get_texture_data(cache->d, PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "bumpmap") == 0 && chk(PARAMS, 1, tf, cache))
		paraboloid->bumpmap = get_texture_data(cache->d, PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "texmodifier") == 0)
		paraboloid->texmodifier = ft_atoi(PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "texscale") == 0)
		attributeboth(&paraboloid->scale_x, &paraboloid->scale_y, TWO_ATOF);
	else if (ft_strcmp(PARAM_NAME, "texoffset") == 0)
		attributeboth(&paraboloid->off_x, &paraboloid->off_y, TWO_ATOF);
	else
		transform(&paraboloid->tf_list, PARAM_NAME, PARAMS, cache);
}

void	manage_hyperboloid_params(t_p_cache *cache, t_hyperboloid *hyperboloid)
{
	disect_param(CAC->line, &PARAM_NAME, &PARAMS);
	if (ft_strcmp(PARAM_NAME, "color") == 0 && chk(PARAMS, 3, tf, CAC))
		hyperboloid->color = set_color(ft_atoi(cache->params[0]),
				ft_atoi(cache->params[1]), ft_atoi(cache->params[2]));
	else if (ft_strcmp(PARAM_NAME, "shine") == 0 && chk(PARAMS, 1, tf, CAC))
		hyperboloid->shine = ft_atof(PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "reflection") == 0
		&& chk(PARAMS, 1, tf, CAC))
		hyperboloid->reflection = ft_atof(PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "texture") == 0 && chk(PARAMS, 1, tf, CAC))
		hyperboloid->texture = get_texture_data(CAC->d, PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "bumpmap") == 0 && chk(PARAMS, 1, tf, CAC))
		hyperboloid->bumpmap = get_texture_data(CAC->d, PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "sheetmode") == 0 && chk(PARAMS, 1, tf, CAC))
		hyperboloid->sheets = ft_atoi(PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "texmodifier") == 0)
		hyperboloid->texmodifier = ft_atoi(PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "texscale") == 0)
		attributeboth(&hyperboloid->scale_x, &hyperboloid->scale_y, TWO_ATOF);
	else if (ft_strcmp(PARAM_NAME, "texoffset") == 0)
		attributeboth(&hyperboloid->off_x, &hyperboloid->off_y, TWO_ATOF);
	else
		transform(&hyperboloid->tf_list, PARAM_NAME, PARAMS, CAC);
}

void	manage_cube_params(t_p_cache *cache, t_cube *cube)
{
	disect_param(cache->line, &PARAM_NAME, &PARAMS);
	if (ft_strcmp(PARAM_NAME, "color") == 0 && chk(PARAMS, 3, tf, cache))
		cube->color = set_color(ft_atoi(cache->params[0]),
				ft_atoi(cache->params[1]), ft_atoi(cache->params[2]));
	else if (ft_strcmp(PARAM_NAME, "shine") == 0 && chk(PARAMS, 1, tf, cache))
		cube->shine = ft_atof(PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "reflection") == 0
		&& chk(PARAMS, 1, tf, cache))
		cube->reflection = ft_atof(PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "vertex_a") == 0
		&& chk(PARAMS, 3, parsetest_vector, cache))
		cube->corner1 = init_vector(TWO_ATOF, ft_atof(PARAMS[2]), 1);
	else if (ft_strcmp(PARAM_NAME, "vertex_b") == 0
		&& chk(PARAMS, 3, parsetest_vector, cache))
		cube->corner2 = init_vector(TWO_ATOF, ft_atof(PARAMS[2]), 1);
	else
		transform(&cube->tf_list, PARAM_NAME, PARAMS, cache);
}

void	manage_prism_params(t_p_cache *cache, t_prism *prism)
{
	disect_param(cache->line, &PARAM_NAME, &PARAMS);
	if (ft_strcmp(PARAM_NAME, "color") == 0 && chk(PARAMS, 3, tf, cache))
		prism->color = set_color(ft_atoi(cache->params[0]),
				ft_atoi(cache->params[1]), ft_atoi(cache->params[2]));
	else if (ft_strcmp(PARAM_NAME, "shine") == 0 && chk(PARAMS, 1, tf, cache))
		prism->shine = ft_atof(PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "reflection") == 0
		&& chk(PARAMS, 1, tf, cache))
		prism->reflection = ft_atof(PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "vertex_a") == 0
		&& chk(PARAMS, 3, parsetest_vector, cache))
		prism->a = init_vector(TWO_ATOF, ft_atof(PARAMS[2]), 1);
	else if (ft_strcmp(PARAM_NAME, "vertex_b") == 0
		&& chk(PARAMS, 3, parsetest_vector, cache))
		prism->b = init_vector(TWO_ATOF, ft_atof(PARAMS[2]), 1);
	else if (ft_strcmp(PARAM_NAME, "vertex_c") == 0
		&& chk(PARAMS, 3, parsetest_vector, cache))
		prism->c = init_vector(TWO_ATOF, ft_atof(PARAMS[2]), 1);
	else if (ft_strcmp(PARAM_NAME, "vertex_d") == 0
		&& chk(PARAMS, 3, parsetest_vector, cache))
		prism->d = init_vector(TWO_ATOF, ft_atof(PARAMS[2]), 1);
	else
		transform(&prism->tf_list, PARAM_NAME, PARAMS, cache);
}
