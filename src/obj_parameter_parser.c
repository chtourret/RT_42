/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parameter_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 04:57:25 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:12 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char	get_number_split(char **argc)
{
	int i;

	i = 0;
	while (argc[i] != 0)
		i++;
	return (i);
}

void	disect_param(char *str, char **param, char ***args)
{
	int i;

	i = 0;
	while (str[i] != ':' && str[i] != '\0')
		i++;
	*param = ft_strndup(str, i);
	*args = ft_strsplit_whitespaces(&str[1 + i]);
}

char	chk(char **params, int n, int (*f)(char *, int, struct s_p_cache *),
	t_p_cache *cache)
{
	int i;

	i = 0;
	if (n < get_number_split(params))
		return (0);
	while (*params != 0)
	{
		f(*params, POS, cache);
		i = 0;
		params++;
	}
	return (1);
}
