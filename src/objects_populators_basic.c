/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_populators_basic.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 13:02:02 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:12 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		populatesphere(int fd, t_p_cache *cache, t_obj **lst)
{
	t_sphere	*sphere;
	char		lineid;
	t_obj		*obj;

	sphere = init_sphere(1);
	while ((cache->linelen = get_next_line(fd, &cache->line)) > 0)
	{
		POS++;
		lineid = line_identifier(cache);
		if (lineid == CONTEXT_CLOSER)
			break ;
		else if (lineid == DECLARATOR && ft_strncmp("CUT", cache->line, 3) == 0
			&& cache->scope == 1)
			declarator_redirect(fd, cache, NULL, &sphere->cut);
		else if (lineid == DECLARATOR)
			ft_parsing_error(POS, "sphere cannot support items", FN);
		else if (lineid == PARAMETER)
			manage_sphere_params(cache, sphere);
		free(cache->line);
	}
	obj = push_sphere(lst, sphere);
}

void		populatecylinder(int fd, t_p_cache *cache, t_obj **lst)
{
	t_cylinder	*cylinder;
	char		lineid;
	t_obj		*obj;

	cylinder = init_cylinder();
	while ((cache->linelen = get_next_line(fd, &cache->line)) > 0)
	{
		POS++;
		lineid = line_identifier(cache);
		if (lineid == CONTEXT_CLOSER)
			break ;
		else if (lineid == DECLARATOR && ft_strncmp("CUT", cache->line, 3) == 0
			&& cache->scope == 1)
			declarator_redirect(fd, cache, NULL, &cylinder->cut);
		else if (lineid == DECLARATOR)
			ft_parsing_error(POS, "cylinder cannot support items", FN);
		else if (lineid == PARAMETER)
			manage_cylinder_params(cache, cylinder);
		free(cache->line);
	}
	obj = push_cylinder(lst, cylinder);
}

void		populatecone(int fd, t_p_cache *cache, t_obj **lst)
{
	t_cone	*cone;
	char	lineid;
	t_obj	*obj;

	if (cache->scope > 1)
		ft_parsing_error(POS, "cone does not support CSG", FN);
	cone = init_cone(10);
	while ((cache->linelen = get_next_line(fd, &cache->line)) > 0)
	{
		POS++;
		lineid = line_identifier(cache);
		if (lineid == CONTEXT_CLOSER)
			break ;
		else if (lineid == DECLARATOR && ft_strncmp("CUT", cache->line, 3) == 0
			&& cache->scope == 1)
			declarator_redirect(fd, cache, NULL, &cone->cut);
		else if (lineid == DECLARATOR)
			ft_parsing_error(POS, "cone cannot support items", FN);
		else if (lineid == PARAMETER)
			manage_cone_params(cache, cone);
		free(cache->line);
	}
	obj = push_cone(lst, cone);
}

void		populateplane(int fd, t_p_cache *cache, t_obj **lst)
{
	t_plane	*plane;
	char	lineid;
	t_obj	*obj;

	plane = init_plane();
	while ((cache->linelen = get_next_line(fd, &cache->line)) > 0)
	{
		POS++;
		lineid = line_identifier(cache);
		if (lineid == CONTEXT_CLOSER)
			break ;
		else if (lineid == DECLARATOR && ft_strncmp("CUT", cache->line, 3) == 0
			&& cache->scope == 1)
			declarator_redirect(fd, cache, NULL, &plane->cut);
		else if (lineid == DECLARATOR)
			ft_parsing_error(POS, "plane cannot support items", FN);
		else if (lineid == PARAMETER)
			manage_plane_params(cache, plane);
		free(cache->line);
	}
	obj = push_plane(lst, plane);
}

void		populatetriangle(int fd, t_p_cache *cache, t_obj **lst)
{
	t_triangle	*triangle;
	char		lineid;
	t_obj		*obj;

	triangle = init_triangle();
	while ((cache->linelen = get_next_line(fd, &cache->line)) > 0)
	{
		POS++;
		lineid = line_identifier(cache);
		if (lineid == CONTEXT_CLOSER)
			break ;
		else if (lineid == DECLARATOR && ft_strncmp("CUT", cache->line, 3) == 0
			&& cache->scope == 1)
			declarator_redirect(fd, cache, NULL, &triangle->cut);
		else if (lineid == DECLARATOR)
			ft_parsing_error(POS, "triangle cannot support items", FN);
		else if (lineid == PARAMETER)
			manage_triangle_params(cache, triangle);
		free(cache->line);
	}
	compute_triangle(triangle);
	obj = push_triangle(lst, triangle);
}
