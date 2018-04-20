/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_line_identifier.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:40:38 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:09 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char	isdeclarator(char *str, int scope)
{
	if (accepted_types(str, scope))
		return (0);
	if (ft_strncmp("CSG", str, 3) != 0)
		return (1);
	else if ((str = ft_strchr(str, ',')) == 0)
		return (0);
	str++;
	if (!(ft_strcmp("UNION", str) == 0 || ft_strcmp("INTER", str) == 0
				|| ft_strcmp("DIFF", str) == 0))
		return (0);
	return (1);
}

char	check_param_valid(char *name, int *paramtype)
{
	*paramtype = DOUBLE;
	if (three_double_required(name))
		return (3);
	if (one_double_required(name))
		return (1);
	if (ft_strcmp("texscale", name) == 0 || ft_strcmp("texoffset", name) == 0)
		return (2);
	*paramtype = STRING;
	if (ft_strcmp("light_type", name) == 0 || ft_strcmp("texture", name) == 0
			|| ft_strcmp("bumpmap", name) == 0)
		return (1);
	return (-1);
}

int		get_words_qty(char *str)
{
	char	prec;
	int		words;
	int		tmp;

	words = 0;
	prec = 0;
	while (str[0] != '\0')
	{
		tmp = ft_isnumeric(str[0]);
		if (tmp != 0 && prec == 0)
		{
			words++;
			prec = 1;
		}
		if (tmp == 0 && prec == 1)
			prec = 0;
		str++;
	}
	return (words);
}

char	isparameter(char *str, int line, char *filename)
{
	char	*delimiter;
	char	params;
	int		paramtype;

	if ((delimiter = ft_strchr(str, ':')) == NULL)
		return (0);
	*delimiter = '\0';
	delimiter++;
	if ((params = check_param_valid(str, &paramtype)) < 0)
		ft_parsing_error(line, "unrecognised parameter", filename);
	if (get_words_qty(delimiter) != params)
		ft_parsing_error(line, "inconsistent number of arguments", filename);
	while (*delimiter != 0)
	{
		if (paramtype == DOUBLE && ft_isalpha(delimiter[0]) == 1)
			ft_parsing_error(line, "inconsistent type of arguments", filename);
		delimiter++;
	}
	return (1);
}

char	line_identifier(t_p_cache *cache)
{
	if (ft_strncmp(cache->line, "//", 2) == 0)
		return (0);
	else if (ft_strcmp(cache->line, "{") == 0)
		return (CONTEXT_OPENER);
	else if (ft_strcmp(cache->line, "}") == 0)
		return (CONTEXT_CLOSER);
	else if (isdeclarator(cache->line, cache->scope) == 1)
		return (DECLARATOR);
	else if (isparameter(cache->line, cache->pos, FN) == 1)
		return (PARAMETER);
	else if (isempty(cache->line) == 0)
		ft_parsing_error(cache->pos, "unrecognised line", FN);
	return (0);
}
