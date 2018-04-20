/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboualav <aboualav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 15:46:16 by aboualav          #+#    #+#             */
/*   Updated: 2017/06/21 12:30:48 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color		get_cylinder_color(t_obj *obj)
{
	return (TO_CYLINDER->color);
}

t_color		get_sphere_color(t_obj *obj)
{
	return (TO_SPHERE->color);
}

t_color		get_plane_color(t_obj *obj)
{
	return (TO_PLANE->color);
}

t_color		get_cone_color(t_obj *obj)
{
	return (TO_CONE->color);
}
