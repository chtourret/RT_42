/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:24:21 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:37 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

t_vect		init_vector(double x, double y, double z, double w)
{
	t_vect v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.w = w;
	return (v);
}
