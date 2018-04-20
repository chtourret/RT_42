/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_apply_parameters_basic.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 13:07:33 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:14 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	manage_sphere_params(t_p_cache *cache, t_sphere *sphere)
{
	disect_param(cache->line, &PARAM_NAME, &PARAMS);
	if (ft_strcmp(PARAM_NAME, "color") == 0 && chk(PARAMS, 3, tf, cache))
		sphere->color = set_color(ft_atoi(cache->params[0]),
				ft_atoi(cache->params[1]), ft_atoi(cache->params[2]));
	else if (ft_strcmp(PARAM_NAME, "shine") == 0 && chk(PARAMS, 1, tf, cache))
		sphere->shine = ft_atof(PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "reflection") == 0
		&& chk(PARAMS, 1, tf, cache))
		sphere->reflection = ft_atof(PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "texture") == 0 && chk(PARAMS, 1, tf, cache))
		sphere->texture = get_texture_data(cache->d, PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "bumpmap") == 0 && chk(PARAMS, 1, tf, cache))
		sphere->bumpmap = get_texture_data(cache->d, PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "texmodifier") == 0)
		sphere->texmodifier = ft_atoi(PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "texscale") == 0)
		attributeboth(&sphere->scale_x, &sphere->scale_y, TWO_ATOF);
	else if (ft_strcmp(PARAM_NAME, "texoffset") == 0)
		attributeboth(&sphere->off_x, &sphere->off_y, TWO_ATOF);
	else
		transform(&sphere->tf_list, PARAM_NAME, PARAMS, cache);
}

void	manage_plane_params(t_p_cache *cache, t_plane *plane)
{
	disect_param(CAC->line, &PARAM_NAME, &PARAMS);
	if (ft_strcmp(PARAM_NAME, "color") == 0 && chk(PARAMS, 3, tf, CAC))
		plane->color = set_color(ft_atoi(cache->params[0]),
				ft_atoi(cache->params[1]), ft_atoi(cache->params[2]));
	else if (ft_strcmp(PARAM_NAME, "shine") == 0 && chk(PARAMS, 1, tf, CAC))
		plane->shine = ft_atof(PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "reflection") == 0
		&& chk(PARAMS, 1, tf, CAC))
		plane->reflection = ft_atof(PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "texture") == 0 && chk(PARAMS, 1, tf, CAC))
		plane->texture = get_texture_data(CAC->d, PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "bumpmap") == 0 && chk(PARAMS, 1, tf, CAC))
		plane->bumpmap = get_texture_data(CAC->d, PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "texmodifier") == 0)
		plane->texmodifier = ft_atoi(PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "texscale") == 0)
		attributeboth(&plane->scale_x, &plane->scale_y, TWO_ATOF);
	else if (ft_strcmp(PARAM_NAME, "texoffset") == 0)
		attributeboth(&plane->off_x, &plane->off_y, TWO_ATOF);
	else if (ft_strcmp(PARAM_NAME, "absolute") == 0 && chk(PARAMS, 1, tf, CAC))
		plane->cut_type = ft_atoi(PARAMS[0]);
	else
		transform(&plane->tf_list, PARAM_NAME, PARAMS, CAC);
}

void	manage_cylinder_params(t_p_cache *cache, t_cylinder *cylinder)
{
	disect_param(cache->line, &PARAM_NAME, &PARAMS);
	if (ft_strcmp(PARAM_NAME, "color") == 0 && chk(PARAMS, 3, tf, cache))
		cylinder->color = set_color(ft_atoi(cache->params[0]),
				ft_atoi(cache->params[1]), ft_atoi(cache->params[2]));
	else if (ft_strcmp(PARAM_NAME, "shine") == 0 && chk(PARAMS, 1, tf, cache))
		cylinder->shine = ft_atof(PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "reflection") == 0
		&& chk(PARAMS, 1, tf, cache))
		cylinder->reflection = ft_atof(PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "texture") == 0 && chk(PARAMS, 1, tf, cache))
		cylinder->texture = get_texture_data(cache->d, PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "bumpmap") == 0 && chk(PARAMS, 1, tf, cache))
		cylinder->bumpmap = get_texture_data(cache->d, PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "texmodifier") == 0)
		cylinder->texmodifier = ft_atoi(PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "texscale") == 0)
		attributeboth(&cylinder->scale_x, &cylinder->scale_y, TWO_ATOF);
	else if (ft_strcmp(PARAM_NAME, "texoffset") == 0)
		attributeboth(&cylinder->off_x, &cylinder->off_y, TWO_ATOF);
	else
		transform(&cylinder->tf_list, PARAM_NAME, PARAMS, cache);
}

void	manage_cone_params(t_p_cache *cache, t_cone *cone)
{
	disect_param(cache->line, &PARAM_NAME, &PARAMS);
	if (ft_strcmp(PARAM_NAME, "color") == 0 && chk(PARAMS, 3, tf, cache))
		cone->color = set_color(ft_atoi(cache->params[0]),
				ft_atoi(cache->params[1]), ft_atoi(cache->params[2]));
	else if (ft_strcmp(PARAM_NAME, "shine") == 0 && chk(PARAMS, 1, tf, cache))
		cone->shine = ft_atof(PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "reflection") == 0
		&& chk(PARAMS, 1, tf, cache))
		cone->reflection = ft_atof(PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "texture") == 0 && chk(PARAMS, 1, tf, cache))
		cone->texture = get_texture_data(cache->d, PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "bumpmap") == 0 && chk(PARAMS, 1, tf, cache))
		cone->bumpmap = get_texture_data(cache->d, PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "texmodifier") == 0)
		cone->texmodifier = ft_atoi(PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "texscale") == 0)
		attributeboth(&cone->scale_x, &cone->scale_y, TWO_ATOF);
	else if (ft_strcmp(PARAM_NAME, "texoffset") == 0)
		attributeboth(&cone->off_x, &cone->off_y, TWO_ATOF);
	else
		transform(&cone->tf_list, PARAM_NAME, PARAMS, cache);
}

void	manage_triangle_params(t_p_cache *cache, t_triangle *triangle)
{
	disect_param(cache->line, &PARAM_NAME, &PARAMS);
	if (ft_strcmp(PARAM_NAME, "color") == 0 && chk(PARAMS, 3, tf, cache))
		triangle->color = set_color(ft_atoi(cache->params[0]),
				ft_atoi(cache->params[1]), ft_atoi(cache->params[2]));
	else if (ft_strcmp(PARAM_NAME, "shine") == 0 && chk(PARAMS, 1, tf, cache))
		triangle->shine = ft_atof(PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "reflection") == 0
		&& chk(PARAMS, 1, tf, cache))
		triangle->reflection = ft_atof(PARAMS[0]);
	else if (ft_strcmp(PARAM_NAME, "vertex_a") == 0
		&& chk(PARAMS, 3, parsetest_vector, cache))
		triangle->a = init_vector(TWO_ATOF, ft_atof(PARAMS[2]), 1);
	else if (ft_strcmp(PARAM_NAME, "vertex_b") == 0
		&& chk(PARAMS, 3, parsetest_vector, cache))
		triangle->b = init_vector(TWO_ATOF, ft_atof(PARAMS[2]), 1);
	else if (ft_strcmp(PARAM_NAME, "vertex_c") == 0
		&& chk(PARAMS, 3, parsetest_vector, cache))
		triangle->c = init_vector(TWO_ATOF, ft_atof(PARAMS[2]), 1);
	else
		transform(&triangle->tf_list, PARAM_NAME, PARAMS, cache);
}
