/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 03:29:45 by tglandai          #+#    #+#             */
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

t_list		*ft_strsplit_lst(char const *s, char c)
{
	t_list	*ss;
	int		start;
	int		i;

	ss = NULL;
	i = 0;
	if (s == (NULL))
		return (NULL);
	if (ft_count((char *)s, c) > 0)
	{
		while (s[i])
		{
			while (s[i] == c)
				i++;
			if (!s[i])
				break ;
			start = i;
			while (s[i] && s[i] != c)
				i++;
			ft_lst_pushback(&ss, ft_strsub(s, start, i - start), i - start + 1);
		}
		return (ss);
	}
	else
		return (ft_lstnew(NULL, 0));
}
