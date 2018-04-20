/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_matrix_translation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 00:43:35 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:23 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

t_matrix	init_translation_matrix(double x, double y, double z)
{
	t_matrix matrix;

	matrix.type = TRANSLATION;
	matrix.m11 = 1;
	matrix.m12 = 0;
	matrix.m13 = 0;
	matrix.m14 = x;
	matrix.m21 = 0;
	matrix.m22 = 1;
	matrix.m23 = 0;
	matrix.m24 = y;
	matrix.m31 = 0;
	matrix.m32 = 0;
	matrix.m33 = 1;
	matrix.m34 = z;
	matrix.m41 = 0;
	matrix.m42 = 0;
	matrix.m43 = 0;
	matrix.m44 = 1;
	return (matrix);
}
