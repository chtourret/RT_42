/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 16:30:30 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:44:29 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat_new(char *s1, const char *s2)
{
	char	*str;
	int		a;
	int		b;
	int		i;

	i = 0;
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (a + b + 1));
	while (s1[i])
	{
		*(str + i) = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		*(str + a + i) = s2[i];
		i++;
	}
	str[a + b] = '\0';
	return (str);
}
