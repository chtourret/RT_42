/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:04:25 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:45:55 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char *source;
	char *desti;

	source = (char *)src;
	desti = (char *)dest;
	while (n > 0 && *source != c)
	{
		*desti++ = *source++;
		n--;
	}
	if (n > 0)
	{
		*desti = *source;
		desti++;
		return ((void*)desti);
	}
	return (NULL);
}
