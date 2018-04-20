/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctourret <ctourret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:10:24 by ctourret          #+#    #+#             */
/*   Updated: 2017/06/21 12:43:58 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_atof(char *str)
{
	float	rez[2];
	int		dot_seen;

	rez[0] = 0;
	rez[1] = 1;
	dot_seen = 0;
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		rez[1] *= *(str) == '-' ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while ((ft_isdigit(*str) || *str == '.') && *str != '\0')
	{
		if (dot_seen == 0 && *str == '.')
			dot_seen = 1;
		else if (ft_isdigit(*str))
		{
			if (dot_seen)
				rez[1] /= 10.0f;
			rez[0] = rez[0] * 10.0f + (float)(*str - '0');
		}
		str++;
	}
	return (rez[0] * rez[1]);
}
