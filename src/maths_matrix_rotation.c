/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_matrix_rotation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 00:43:14 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:27 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

t_matrix	init_yrotation_matrix(double theta)
{
	t_matrix	matrix;
	double		rad;

	rad = theta * M_PI / 180;
	matrix.type = ROTATION_Y;
	matrix.m11 = cos(rad);
	matrix.m12 = 0;
	matrix.m13 = sin(rad);
	matrix.m14 = 0;
	matrix.m21 = 0;
	matrix.m22 = 1;
	matrix.m23 = 0;
	matrix.m24 = 0;
	matrix.m31 = -1 * sin(rad);
	matrix.m32 = 0;
	matrix.m33 = cos(rad);
	matrix.m34 = 0;
	matrix.m41 = 0;
	matrix.m42 = 0;
	matrix.m43 = 0;
	matrix.m44 = 1;
	return (matrix);
}

t_matrix	init_xrotation_matrix(double theta)
{
	t_matrix	matrix;
	double		rad;

	rad = theta * M_PI / 180;
	matrix.type = ROTATION_X;
	matrix.m11 = 1;
	matrix.m12 = 0;
	matrix.m13 = 0;
	matrix.m14 = 0;
	matrix.m21 = 0;
	matrix.m22 = cos(rad);
	matrix.m23 = -1 * sin(rad);
	matrix.m24 = 0;
	matrix.m31 = 0;
	matrix.m32 = sin(rad);
	matrix.m33 = cos(rad);
	matrix.m34 = 0;
	matrix.m41 = 0;
	matrix.m42 = 0;
	matrix.m43 = 0;
	matrix.m44 = 1;
	return (matrix);
}

t_matrix	init_zrotation_matrix(double theta)
{
	t_matrix	matrix;
	double		rad;

	matrix.type = ROTATION_Z;
	rad = theta * M_PI / 180;
	matrix.m11 = cos(rad);
	matrix.m12 = -1 * sin(rad);
	matrix.m13 = 0;
	matrix.m14 = 0;
	matrix.m21 = sin(rad);
	matrix.m22 = cos(rad);
	matrix.m23 = 0;
	matrix.m24 = 0;
	matrix.m31 = 0;
	matrix.m32 = 0;
	matrix.m33 = 1;
	matrix.m34 = 0;
	matrix.m41 = 0;
	matrix.m42 = 0;
	matrix.m43 = 0;
	matrix.m44 = 1;
	return (matrix);
}

t_matrix	init_xyzrotation_matrix(double theta, double x, double y, double z)
{
	t_matrix	matrix;
	double		rad;

	matrix.type = ROTATION_XYZ;
	rad = theta * M_PI / 180;
	matrix.m11 = x * x * (1 - cos(rad)) + cos(rad);
	matrix.m12 = x * y * (1 - cos(rad)) - z * sin(rad);
	matrix.m13 = x * z * (1 - cos(rad)) + y * sin(rad);
	matrix.m14 = 0;
	matrix.m21 = y * x * (1 - cos(rad)) + z * sin(rad);
	matrix.m22 = y * y * (1 - cos(rad)) + cos(rad);
	matrix.m23 = y * z * (1 - cos(rad)) - x * sin(rad);
	matrix.m24 = 0;
	matrix.m31 = x * z * (1 - cos(rad)) - y * sin(rad);
	matrix.m32 = y * z * (1 - cos(rad)) + x * sin(rad);
	matrix.m33 = z * z * (1 - cos(rad)) + cos(rad);
	matrix.m34 = 0;
	matrix.m41 = 0;
	matrix.m42 = 0;
	matrix.m43 = 0;
	matrix.m44 = 1;
	return (matrix);
}

t_vect		get_bumped_vect(t_vect normal, t_vect transformed)
{
	t_vect		base;
	t_vect		axe;
	t_vect		new_normal;
	t_matrix	xyz;
	double		angle;

	base = init_vector(0, 1, 0, 0);
	apply_matrix(init_yrotation_matrix((atan2(normal.x, normal.z)
		/ (2 * M_PI) * 360)), &transformed);
	if (dot_product_vector(base, transformed) == 1)
		return (transformed);
	normalize_vector(&transformed);
	new_normal = transformed;
	axe = cross_product_vector(base, normal);
	normalize_vector(&axe);
	angle = dot_product_vector(base, normal);
	angle = acos(angle);
	angle = 180 * angle / M_PI;
	xyz = init_xyzrotation_matrix(angle, axe.x, axe.y, axe.z);
	apply_matrix(xyz, &new_normal);
	return (new_normal);
}
