/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_populators_complex.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 13:03:15 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:11 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		populateprism(int fd, t_p_cache *cache, t_obj **lst)
{
	t_prism	*prism;
	char	lineid;
	t_obj	*obj;

	prism = init_prism();
	while ((cache->linelen = get_next_line(fd, &cache->line)) > 0)
	{
		POS++;
		lineid = line_identifier(cache);
		if (lineid == CONTEXT_CLOSER)
			break ;
		else if (lineid == DECLARATOR && ft_strncmp("CUT", cache->line, 3) == 0
			&& cache->scope == 1)
			declarator_redirect(fd, cache, NULL, &prism->cut);
		else if (lineid == DECLARATOR)
			ft_parsing_error(POS, "prism cannot support items", FN);
		else if (lineid == PARAMETER)
			manage_prism_params(cache, prism);
		free(cache->line);
	}
	compute_prism(prism);
	obj = push_prism(lst, prism);
}

void		populatecube(int fd, t_p_cache *cache, t_obj **lst)
{
	t_cube	*cube;
	char	lineid;
	t_obj	*obj;

	cube = init_cube();
	while ((cache->linelen = get_next_line(fd, &cache->line)) > 0)
	{
		POS++;
		lineid = line_identifier(cache);
		if (lineid == CONTEXT_CLOSER)
			break ;
		else if (lineid == DECLARATOR && ft_strncmp("CUT", cache->line, 3) == 0
			&& cache->scope == 1)
			declarator_redirect(fd, cache, NULL, &cube->cut);
		else if (lineid == DECLARATOR)
			ft_parsing_error(POS, "cube cannot support items", FN);
		else if (lineid == PARAMETER)
			manage_cube_params(cache, cube);
		free(cache->line);
	}
	compute_cube(cube);
	obj = push_cube(lst, cube);
}

void		populateparaboloid(int fd, t_p_cache *cache, t_obj **lst)
{
	t_paraboloid	*paraboloid;
	char			lineid;
	t_obj			*obj;

	paraboloid = init_paraboloid();
	while ((cache->linelen = get_next_line(fd, &cache->line)) > 0)
	{
		POS++;
		lineid = line_identifier(cache);
		if (lineid == CONTEXT_CLOSER)
			break ;
		else if (lineid == DECLARATOR && ft_strncmp("CUT", cache->line, 3) == 0
			&& cache->scope == 1)
			declarator_redirect(fd, cache, NULL, &paraboloid->cut);
		else if (lineid == DECLARATOR)
			ft_parsing_error(POS, "paraboloid cannot support items", FN);
		else if (lineid == PARAMETER)
			manage_paraboloid_params(cache, paraboloid);
		free(cache->line);
	}
	obj = push_paraboloid(lst, paraboloid);
}

void		populatehyperboloid(int fd, t_p_cache *cache, t_obj **lst)
{
	t_hyperboloid	*hyperboloid;
	char			lineid;
	t_obj			*obj;

	if (cache->scope > 1)
		ft_parsing_error(POS, "hyperboloid does not support CSG", FN);
	hyperboloid = init_hyperboloid(1);
	while ((cache->linelen = get_next_line(fd, &cache->line)) > 0)
	{
		POS++;
		lineid = line_identifier(cache);
		if (lineid == CONTEXT_CLOSER)
			break ;
		else if (lineid == DECLARATOR)
			ft_parsing_error(POS, "hyperboloid cannot support items", FN);
		else if (lineid == PARAMETER)
			manage_hyperboloid_params(cache, hyperboloid);
		free(cache->line);
	}
	obj = push_hyperboloid(lst, hyperboloid);
}

void		populatecsg(int fd, t_p_cache *cache, t_obj **lst, char booleantype)
{
	t_csg	*csg;
	char	lineid;
	t_obj	*obj;

	csg = init_csg();
	csg->operation = booleantype;
	while ((cache->linelen = get_next_line(fd, &cache->line)) > 0)
	{
		POS++;
		lineid = line_identifier(cache);
		if (lineid == CONTEXT_CLOSER)
			break ;
		else if (lineid == DECLARATOR && csg->first != NULL
			&& csg->second != NULL)
			ft_parsing_error(POS, "csg only support two child", FN);
		else if (lineid == DECLARATOR && csg->first == NULL)
			declarator_redirect(fd, cache, &csg->first, NULL);
		else if (lineid == DECLARATOR && csg->second == NULL)
			declarator_redirect(fd, cache, &csg->second, NULL);
		free(cache->line);
	}
	if (csg->first == NULL || csg->second == NULL)
		ft_parsing_error(POS, "csg only support two child", FN);
	obj = push_csg(lst, csg);
}
