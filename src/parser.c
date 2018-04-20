/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 18:30:23 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:08 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	cache_init(t_p_cache *cache, char *filename)
{
	cache->pos = 1;
	cache->scope = 0;
	cache->line = NULL;
	cache->linelen = 0;
	cache->prec = 0;
	cache->d = NULL;
	cache->param_name = NULL;
	cache->params = NULL;
	FN = filename;
}

char	getboolop(t_p_cache *cache)
{
	char	*tmp;
	char	booltype;

	booltype = 0;
	tmp = ft_strchr(cache->line, ',');
	if (ft_strcmp(",UNION", tmp) == 0)
		booltype = UNION;
	else if (ft_strcmp(",INTER", tmp) == 0)
		booltype = INTER;
	else if (ft_strcmp(",DIFF", tmp) == 0)
		booltype = DIFF;
	else
		ft_parsing_error(cache->pos,
				"boolean operation for csg is inconsistant", FN);
	return (booltype);
}

void	dec_redir_2(int fd, t_p_cache *cache, t_obj **lst, t_obj **cut)
{
	if (ft_strncmp("CUBE", cache->line, 4) == 0)
		populatecube(fd, cache, lst);
	else if (ft_strncmp("PARABOLOID", cache->line, 10) == 0)
		populateparaboloid(fd, cache, lst);
	else if (ft_strncmp("HYPERBOLOID", cache->line, 11) == 0)
		populatehyperboloid(fd, cache, lst);
	else if (ft_strncmp("LIGHT", cache->line, 5) == 0)
		populatelight(fd, cache, &cache->d->light_list);
	else if (ft_strncmp("CAMERA", cache->line, 6) == 0)
		populatecamera(fd, cache);
	else if (ft_strncmp("CSG", cache->line, 3) == 0)
		populatecsg(fd, cache, lst, getboolop(cache));
	else if (ft_strncmp("CUT", cache->line, 3) == 0 && cut != NULL)
		populateplane(fd, cache, cut);
	else
		ft_parsing_error(cache->pos, "unrecognised declarator", FN);
}

void	declarator_redirect(int fd, t_p_cache *cache, t_obj **lst, t_obj **cut)
{
	free_prec_split(cache);
	cache->scope++;
	if (ft_strncmp("SPHERE", cache->line, 6) == 0)
		populatesphere(fd, cache, lst);
	else if (ft_strncmp("CYLINDER", cache->line, 8) == 0)
		populatecylinder(fd, cache, lst);
	else if (ft_strncmp("CONE", cache->line, 4) == 0)
		populatecone(fd, cache, lst);
	else if (ft_strncmp("PLANE", cache->line, 5) == 0)
		populateplane(fd, cache, lst);
	else if (ft_strncmp("TRIANGLE", cache->line, 7) == 0)
		populatetriangle(fd, cache, lst);
	else if (ft_strncmp("PRISM", cache->line, 5) == 0)
		populateprism(fd, cache, lst);
	else
		dec_redir_2(fd, cache, lst, cut);
	cache->scope--;
}

void	parser(int fd, t_data *d, char *filename)
{
	t_p_cache	cache;
	char		lineid;

	cache_init(&cache, filename);
	cache.d = d;
	while ((cache.linelen = get_next_line(fd, &cache.line)) > 0)
	{
		cache.pos++;
		lineid = line_identifier(&cache);
		if (lineid == DECLARATOR)
			declarator_redirect(fd, &cache, &(d->obj), NULL);
		else if (lineid == PARAMETER)
			manage_root_parameters(&cache, d);
		free(cache.line);
	}
}
