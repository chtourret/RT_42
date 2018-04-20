/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj_normal_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboualav <aboualav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:08:07 by aboualav          #+#    #+#             */
/*   Updated: 2017/06/21 12:30:54 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vect	get_triangle_normal(t_obj *obj, t_vect n, t_thread *thread)
{
	(void)thread;
	(void)n;
	return (TO_TRIANGLE->normal);
}

t_vect	get_prism_normal(t_obj *obj, t_vect n, t_thread *thread)
{
	int i;

	(void)n;
	i = TO_PRISM->closest_triangle[thread->num];
	return (TO_PRISM->triangle[i]->solid->triangle->normal);
}

t_vect	get_cube_normal(t_obj *obj, t_vect n, t_thread *thread)
{
	int i;

	(void)n;
	i = TO_CUBE->closest_triangle[thread->num];
	return (TO_CUBE->triangle[i]->solid->triangle->normal);
}

t_vect	get_paraboloid_normal(t_obj *obj, t_vect n, t_thread *thread)
{
	t_vect normal;

	(void)obj;
	(void)thread;
	normal = init_vector(2 * n.x, 0, 2 * n.z, 0);
	normalize_vector(&normal);
	return (normal);
}

t_vect	get_hyperboloid_normal(t_obj *obj, t_vect n, t_thread *thread)
{
	t_vect normal;

	(void)obj;
	(void)thread;
	normal = init_vector(2 * n.x, -2 * n.y, 2 * n.z, 0);
	normalize_vector(&normal);
	return (normal);
}
