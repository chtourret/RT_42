/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:04:09 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:39:56 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			swap_double(double *a, double *b)
{
	double		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
