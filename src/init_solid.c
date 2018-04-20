/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_solid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:24:12 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:38 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_solid		*init_solid(void *obj, char type)
{
	t_solid *solid;

	solid = NULL;
	if (type == SPHERE)
		return (get_sphere_solid(obj));
	else if (type == PLANE)
		return (get_plane_solid(obj));
	else if (type == CYLINDER)
		return (get_cylinder_solid(obj));
	else if (type == CONE)
		return (get_cone_solid(obj));
	else if (type == TRIANGLE)
		return (get_triangle_solid(obj));
	else if (type == PRISM)
		return (get_prism_solid(obj));
	else if (type == CUBE)
		return (get_cube_solid(obj));
	else if (type == PARABOLOID)
		return (get_paraboloid_solid(obj));
	else if (type == HYPERBOLOID)
		return (get_hyperboloid_solid(obj));
	else if (type == CSG)
		return (get_csg_solid(obj));
	return (solid);
}
