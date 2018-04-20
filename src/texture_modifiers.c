/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_modifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:58:53 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:41:29 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double				texscalex(char type, t_obj *obj, double in)
{
	if (type == CONE)
		return (in * TO_CONE->scale_x);
	else if (type == CYLINDER)
		return (in * TO_CYLINDER->scale_x);
	else if (type == SPHERE)
		return (in * TO_SPHERE->scale_x);
	else if (type == PLANE)
		return (in * TO_PLANE->scale_x);
	else if (type == PARABOLOID)
		return (in * TO_PARABOLOID->scale_x);
	else if (type == HYPERBOLOID)
		return (in * TO_HYPERBOLOID->scale_x);
	return (1);
}

double				texscaley(char type, t_obj *obj, double in)
{
	if (type == CONE)
		return (in * TO_CONE->scale_y);
	else if (type == CYLINDER)
		return (in * TO_CYLINDER->scale_y);
	else if (type == SPHERE)
		return (in * TO_SPHERE->scale_y);
	else if (type == PLANE)
		return (in * TO_PLANE->scale_y);
	else if (type == PARABOLOID)
		return (in * TO_PARABOLOID->scale_y);
	else if (type == HYPERBOLOID)
		return (in * TO_HYPERBOLOID->scale_y);
	return (1);
}

double				texoffx(char type, t_obj *obj, double in)
{
	if (type == CONE)
		return (in + TO_CONE->off_x);
	else if (type == CYLINDER)
		return (in + TO_CYLINDER->off_x);
	else if (type == SPHERE)
		return (in + TO_SPHERE->off_x);
	else if (type == PLANE)
		return (in + TO_PLANE->off_x);
	else if (type == PARABOLOID)
		return (in + TO_PARABOLOID->off_x);
	else if (type == HYPERBOLOID)
		return (in + TO_HYPERBOLOID->off_x);
	return (0);
}

double				texoffy(char type, t_obj *obj, double in)
{
	if (type == CONE)
		return (in + TO_CONE->off_y);
	else if (type == CYLINDER)
		return (in + TO_CYLINDER->off_y);
	else if (type == SPHERE)
		return (in + TO_SPHERE->off_y);
	else if (type == PLANE)
		return (in + TO_PLANE->off_y);
	else if (type == PARABOLOID)
		return (in + TO_PARABOLOID->off_y);
	else if (type == HYPERBOLOID)
		return (in + TO_HYPERBOLOID->off_y);
	return (0);
}
