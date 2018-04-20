/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 00:43:22 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:23 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

static t_matrix		transposed_matrix(t_matrix m)
{
	t_matrix matrix;

	matrix.type = m.type;
	matrix.m11 = m.m11;
	matrix.m12 = m.m21;
	matrix.m13 = m.m31;
	matrix.m14 = m.m41;
	matrix.m21 = m.m12;
	matrix.m22 = m.m22;
	matrix.m23 = m.m32;
	matrix.m24 = m.m42;
	matrix.m31 = m.m13;
	matrix.m32 = m.m23;
	matrix.m33 = m.m33;
	matrix.m34 = m.m43;
	matrix.m41 = m.m14;
	matrix.m42 = m.m24;
	matrix.m43 = m.m34;
	matrix.m44 = m.m44;
	return (matrix);
}

void				apply_matrix(t_matrix matrix, t_vect *v)
{
	double x;
	double y;
	double z;
	double w;

	x = v->x;
	y = v->y;
	z = v->z;
	w = v->w;
	v->x = matrix.m11 * x + matrix.m12 * y + matrix.m13 * z + matrix.m14 * w;
	v->y = matrix.m21 * x + matrix.m22 * y + matrix.m23 * z + matrix.m24 * w;
	v->z = matrix.m31 * x + matrix.m32 * y + matrix.m33 * z + matrix.m34 * w;
	v->w = matrix.m41 * x + matrix.m42 * y + matrix.m43 * z + matrix.m44 * w;
}

t_matrix			get_inverse_matrix(t_matrix m)
{
	t_matrix inverse;

	if (m.type == ROTATION_Y || m.type == ROTATION_X
		|| m.type == ROTATION_Z || m.type == ROTATION_XYZ)
		inverse = transposed_matrix(m);
	else if (m.type == SCALE)
		inverse = init_scale_matrix(1 / m.m11, 1 / m.m22, 1 / m.m33);
	else
		inverse = init_translation_matrix(-m.m14, -m.m24, -m.m34);
	return (inverse);
}
