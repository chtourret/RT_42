/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_whitespaces.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 02:07:01 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:45:55 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char *s, char c)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (s[i] == c)
	{
		i++;
	}
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			n++;
		i++;
	}
	if (s[i - 1] != c && !s[i])
		n++;
	return (n);
}

char		**ft_strsplit_whitespaces(char const *s)
{
	char	**ss;
	int		start;
	int		i;
	int		index;

	i = 0;
	index = 0;
	if (s == (NULL))
		return (NULL);
	ss = (char **)malloc(sizeof(char *) * (ft_count((char *)s, ' ') + 1));
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != ' ')
			i++;
		ss[index++] = ft_strsub(s, start, i - start);
	}
	ss[index] = NULL;
	return (ss);
}
