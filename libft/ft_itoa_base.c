/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:50:02 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:44:09 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base(int nb, int base)
{
	char	*s;
	char	*mem;
	int		neg;

	if (!(s = ft_strnew(35)) || base < 2 || base > 16)
		return (NULL);
	mem = s;
	neg = (nb < 0);
	if (!nb)
		*s = '0';
	while (nb != 0)
	{
		*s = "0123456789ABCDEF"[(nb % base) * (neg ? -1 : 1)];
		nb /= base;
		s++;
	}
	if (neg)
		*s = '-';
	ft_strrev(mem);
	return (mem);
}
