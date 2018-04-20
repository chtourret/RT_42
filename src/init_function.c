/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 04:56:13 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:48 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	**init_get_obj_tf_list(void)
{
	void **get_obj_tf_list;

	get_obj_tf_list = (void **)ft_memalloc(sizeof(void *) * OBJECT_NUMBER);
	get_obj_tf_list[CYLINDER] = (void *)get_cylinder_tf_list;
	get_obj_tf_list[SPHERE] = (void *)get_sphere_tf_list;
	get_obj_tf_list[PLANE] = (void *)get_plane_tf_list;
	get_obj_tf_list[CONE] = (void *)get_cone_tf_list;
	get_obj_tf_list[TRIANGLE] = (void *)get_triangle_tf_list;
	get_obj_tf_list[PRISM] = (void *)get_prism_tf_list;
	get_obj_tf_list[CUBE] = (void *)get_cube_tf_list;
	get_obj_tf_list[PARABOLOID] = (void *)get_paraboloid_tf_list;
	get_obj_tf_list[HYPERBOLOID] = (void *)get_hyperboloid_tf_list;
	get_obj_tf_list[CSG] = NULL;
	return (get_obj_tf_list);
}

static void	**init_get_obj_normal(void)
{
	void **get_obj_normal;

	get_obj_normal = (void **)ft_memalloc(sizeof(void *) * OBJECT_NUMBER);
	get_obj_normal[CYLINDER] = (void *)get_cylinder_normal;
	get_obj_normal[SPHERE] = (void *)get_sphere_normal;
	get_obj_normal[PLANE] = (void *)get_plane_normal;
	get_obj_normal[CONE] = (void *)get_cone_normal;
	get_obj_normal[TRIANGLE] = (void *)get_triangle_normal;
	get_obj_normal[PRISM] = (void *)get_prism_normal;
	get_obj_normal[CUBE] = (void *)get_cube_normal;
	get_obj_normal[PARABOLOID] = (void *)get_paraboloid_normal;
	get_obj_normal[HYPERBOLOID] = (void *)get_hyperboloid_normal;
	get_obj_normal[CSG] = NULL;
	return (get_obj_normal);
}

static void	**init_get_obj_color(void)
{
	void **get_obj_color;

	get_obj_color = (void **)ft_memalloc(sizeof(void *) * OBJECT_NUMBER);
	get_obj_color[CYLINDER] = (void *)get_cylinder_color;
	get_obj_color[SPHERE] = (void *)get_sphere_color;
	get_obj_color[PLANE] = (void *)get_plane_color;
	get_obj_color[CONE] = (void *)get_cone_color;
	get_obj_color[TRIANGLE] = (void *)get_triangle_color;
	get_obj_color[PRISM] = (void *)get_prism_color;
	get_obj_color[CUBE] = (void *)get_cube_color;
	get_obj_color[PARABOLOID] = (void *)get_paraboloid_color;
	get_obj_color[HYPERBOLOID] = (void *)get_hyperboloid_color;
	get_obj_color[CSG] = NULL;
	return (get_obj_color);
}

static void	**init_get_obj_n(void)
{
	void **get_obj_n;

	get_obj_n = (void **)ft_memalloc(sizeof(void *) * OBJECT_NUMBER);
	get_obj_n[CYLINDER] = (void *)get_cylinder_n;
	get_obj_n[SPHERE] = (void *)get_sphere_n;
	get_obj_n[PLANE] = (void *)get_plane_n;
	get_obj_n[CONE] = (void *)get_cone_n;
	get_obj_n[TRIANGLE] = (void *)get_triangle_n;
	get_obj_n[PRISM] = (void *)get_prism_n;
	get_obj_n[CUBE] = (void *)get_cube_n;
	get_obj_n[PARABOLOID] = (void *)get_paraboloid_n;
	get_obj_n[HYPERBOLOID] = (void *)get_hyperboloid_n;
	get_obj_n[CSG] = NULL;
	return (get_obj_n);
}

t_func		*init_function(void)
{
	t_func *func;

	func = (t_func *)ft_memalloc(sizeof(t_func));
	func->get_obj_tf_list = init_get_obj_tf_list();
	func->get_obj_normal = init_get_obj_normal();
	func->get_obj_color = init_get_obj_color();
	func->get_obj_n = init_get_obj_n();
	func->post_pro = init_post_pro();
	return (func);
}
