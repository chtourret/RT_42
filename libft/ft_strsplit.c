/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 02:35:48 by tglandai          #+#    #+#             */
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

char		**ft_strsplit(char const *s, char c)
{
	char	**ss;
	int		new_word_start;
	int		i;
	int		index;

	i = 0;
	index = 0;
	ss = (char **)malloc(sizeof(char *) * (ft_count((char *)s, c) + 1));
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		new_word_start = i;
		while (s[i] && s[i] != c)
			i++;
		ss[index++] = ft_strsub(s, new_word_start, i - new_word_start);
		new_word_start = i;
	}
	ss[index] = NULL;
	return (ss);
}
