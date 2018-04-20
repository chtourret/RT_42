/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:37:47 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:45:55 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *desti;
	char *source;

	desti = (char*)dst;
	source = (char*)src;
	if (source <= desti)
	{
		while (len > 0)
		{
			*(desti + len - 1) = *(source + len - 1);
			len--;
		}
	}
	else
		ft_memcpy(desti, source, len);
	return (dst);
}
