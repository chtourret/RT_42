/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_apply_parameters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 04:57:15 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:13 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		tf(char *lolilol, int line, t_p_cache *cache)
{
	(void)cache;
	(void)lolilol;
	(void)line;
	return (1);
}

void	attributeboth(double *xa, double *ya, float xb, float yb)
{
	*xa = xb;
	*ya = yb;
}

void	transform(t_tf_list **lst, char *param_name, char **params,
	t_p_cache *cache)
{
	if (ft_strcmp(param_name, "translate") == 0 &&
			chk(params, 3, parsetest_vector, cache))
		push_trans_tf(lst, ft_atof(params[0]),
				ft_atof(params[1]), ft_atof(params[2]));
	else if (ft_strcmp(param_name, "rotate_x") == 0 &&
			chk(params, 1, tf, cache))
		push_xrot_tf(lst, ft_atof(params[0]));
	else if (ft_strcmp(param_name, "rotate_y") == 0 &&
			chk(params, 1, tf, cache))
		push_yrot_tf(lst, ft_atof(params[0]));
	else if (ft_strcmp(param_name, "rotate_z") == 0 &&
			chk(params, 1, tf, cache))
		push_zrot_tf(lst, ft_atof(params[0]));
	else if (ft_strcmp(param_name, "scale") == 0 &&
			chk(params, 3, parsetest_vector, cache))
		push_scale_tf(lst, TWO_ATOF,
				ft_atof(params[2]));
	else
		ft_parsing_error(cache->pos, "unsupported parameter passed to object",
		cache->filename);
}
