/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_vector_calc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 00:45:27 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:42:04 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

t_vect		copy_vector(t_vect v)
{
	t_vect v_new;

	v_new.x = v.x;
	v_new.y = v.y;
	v_new.z = v.z;
	v_new.w = v.w;
	return (v_new);
}

void		negative_vector(t_vect *v)
{
	v->x *= -1;
	v->y *= -1;
	v->z *= -1;
}

double		vector_magnitude(t_vect v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

void		normalize_vector(t_vect *v)
{
	double magnitude;

	magnitude = vector_magnitude(*v);
	v->x /= magnitude;
	v->y /= magnitude;
	v->z /= magnitude;
}

void		mult_vector(t_vect *v, double d)
{
	v->x *= d;
	v->y *= d;
	v->z *= d;
}
