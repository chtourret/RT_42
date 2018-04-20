/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 10:57:04 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:45:55 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	unsigned int	k;

	if (len > (ft_strlen(s) - start) || start > ft_strlen(s))
		return (NULL);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	k = start;
	i = 0;
	while (i < len)
	{
		str[i] = s[k];
		i++;
		k++;
	}
	return (str);
}
