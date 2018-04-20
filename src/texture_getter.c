/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_getter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:42:08 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:01 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_texture			*texturegetter(char type, t_obj *obj)
{
	if (type == CONE)
		return (TO_CONE->texture);
	else if (type == CYLINDER)
		return (TO_CYLINDER->texture);
	else if (type == SPHERE)
		return (TO_SPHERE->texture);
	else if (type == PLANE)
		return (TO_PLANE->texture);
	else if (type == PARABOLOID)
		return (TO_PARABOLOID->texture);
	else if (type == HYPERBOLOID)
		return (TO_HYPERBOLOID->texture);
	return (NULL);
}

t_texture			*bumpmapgetter(char type, t_obj *obj)
{
	if (type == CONE)
		return (TO_CONE->bumpmap);
	else if (type == CYLINDER)
		return (TO_CYLINDER->bumpmap);
	else if (type == SPHERE)
		return (TO_SPHERE->bumpmap);
	else if (type == PLANE)
		return (TO_PLANE->bumpmap);
	else if (type == PARABOLOID)
		return (TO_PARABOLOID->bumpmap);
	else if (type == HYPERBOLOID)
		return (TO_HYPERBOLOID->bumpmap);
	return (NULL);
}

char				texmodifiergetter(char type, t_obj *obj)
{
	if (type == CONE)
		return (TO_CONE->texmodifier);
	else if (type == CYLINDER)
		return (TO_CYLINDER->texmodifier);
	else if (type == SPHERE)
		return (TO_SPHERE->texmodifier);
	else if (type == PLANE)
		return (TO_PLANE->texmodifier);
	else if (type == PARABOLOID)
		return (TO_PARABOLOID->texmodifier);
	else if (type == HYPERBOLOID)
		return (TO_HYPERBOLOID->texmodifier);
	return (0);
}
