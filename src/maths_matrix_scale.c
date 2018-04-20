/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_matrix_scale.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 00:34:45 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:27 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

t_matrix	init_scale_matrix(double x, double y, double z)
{
	t_matrix matrix;

	matrix.type = SCALE;
	matrix.m11 = x;
	matrix.m12 = 0;
	matrix.m13 = 0;
	matrix.m14 = 0;
	matrix.m21 = 0;
	matrix.m22 = y;
	matrix.m23 = 0;
	matrix.m24 = 0;
	matrix.m31 = 0;
	matrix.m32 = 0;
	matrix.m33 = z;
	matrix.m34 = 0;
	matrix.m41 = 0;
	matrix.m42 = 0;
	matrix.m43 = 0;
	matrix.m44 = 1;
	return (matrix);
}
