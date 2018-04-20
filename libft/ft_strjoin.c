/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 11:00:52 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:45:55 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	char *start;

	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	start = str;
	if (str == NULL)
		return (NULL);
	while (*s1)
	{
		*str++ = *(char *)s1++;
	}
	while (*s2)
	{
		*str++ = *(char *)s2++;
	}
	*str = '\0';
	return (start);
}
