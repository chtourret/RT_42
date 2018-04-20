/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 14:47:44 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:10 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		one_double_required(char *name)
{
	return (ft_strcmp("reflection", name) == 0
			|| ft_strcmp("transparence", name) == 0
			|| ft_strcmp("ambient", name) == 0
			|| ft_strcmp("anti-aliasing", name) == 0
			|| ft_strcmp("rotate_x", name) == 0
			|| ft_strcmp("rotate_y", name) == 0
			|| ft_strcmp("rotate_z", name) == 0
			|| ft_strcmp("shine", name) == 0
			|| ft_strcmp("sheetmode", name) == 0
			|| ft_strcmp("AAlvl", name) == 0
			|| ft_strcmp("reflections", name) == 0\
			|| ft_strcmp("offset_x", name) == 0
			|| ft_strcmp("offset_y", name) == 0
			|| ft_strcmp("texmodifier", name) == 0
			|| ft_strcmp("absolute", name) == 0);
}

int		three_double_required(char *name)
{
	return (ft_strcmp("translate", name) == 0
			|| ft_strcmp("color", name) == 0
			|| ft_strcmp("position", name) == 0
			|| ft_strcmp("orientation", name) == 0
			|| ft_strcmp("vertex_a", name) == 0
			|| ft_strcmp("vertex_b", name) == 0
			|| ft_strcmp("vertex_c", name) == 0
			|| ft_strcmp("vertex_d", name) == 0
			|| ft_strcmp("scale", name) == 0
			|| ft_strcmp("look_at", name) == 0);
}

int		accepted_types(char *str, int scope)
{
	return (ft_strncmp("SPHERE", str, 6) != 0
			&& ft_strncmp("CONE", str, 4) != 0
			&& ft_strncmp("CYLINDER", str, 8) != 0
			&& ft_strncmp("PLANE", str, 5) != 0
			&& ft_strncmp("PRISM", str, 5) != 0
			&& ft_strncmp("TRIANGLE", str, 6) != 0
			&& ft_strncmp("CUBE", str, 4) != 0
			&& ft_strncmp("PARABOLOID", str, 10) != 0
			&& ft_strncmp("HYPERBOLOID", str, 11) != 0
			&& ft_strncmp("CUT", str, 3) != 0
			&& (ft_strncmp("CAMERA", str, 4) != 0 || scope > 1)
			&& (ft_strncmp("LIGHT", str, 5) != 0 || scope > 1)
			&& ft_strncmp("CSG", str, 3) != 0);
}
