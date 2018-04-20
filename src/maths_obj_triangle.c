/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_obj_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 00:40:29 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:15 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		first_check(t_triangle *t, t_vect n)
{
	t_vect an;
	t_vect ab_x_an;
	t_vect an_x_ac;
	double dot;

	an = init_vector(n.x - t->a.x,
			n.y - t->a.y,
			n.z - t->a.z, 0);
	ab_x_an = cross_product_vector(t->ab, an);
	an_x_ac = cross_product_vector(an, t->ac);
	dot = dot_product_vector(ab_x_an, an_x_ac);
	if (dot >= 0)
		return (1);
	else
		return (0);
}

static int		second_check(t_triangle *t, t_vect n)
{
	t_vect bn;
	t_vect ba_x_bn;
	t_vect bn_x_bc;
	double dot;

	bn = init_vector(n.x - t->b.x,
			n.y - t->b.y,
			n.z - t->b.z, 0);
	ba_x_bn = cross_product_vector(t->ba, bn);
	bn_x_bc = cross_product_vector(bn, t->bc);
	dot = dot_product_vector(ba_x_bn, bn_x_bc);
	if (dot >= 0)
		return (1);
	else
		return (0);
}

static int		third_check(t_triangle *t, t_vect n)
{
	t_vect cn;
	t_vect cb_x_cn;
	t_vect cn_x_ca;
	double dot;

	cn = init_vector(n.x - t->c.x,
			n.y - t->c.y,
			n.z - t->c.z, 0);
	cb_x_cn = cross_product_vector(t->cb, cn);
	cn_x_ca = cross_product_vector(cn, t->ca);
	dot = dot_product_vector(cb_x_cn, cn_x_ca);
	if (dot >= 0)
		return (1);
	else
		return (0);
}

char			is_in_triangle(t_triangle *t, t_ray ray, double dist)
{
	t_vect n_pos;
	t_vect tmp_raydir;

	n_pos = ray.ori;
	tmp_raydir = ray.dir;
	mult_vector(&tmp_raydir, dist);
	add_to_vector(&n_pos, tmp_raydir);
	if (first_check(t, n_pos) && second_check(t, n_pos)
		&& third_check(t, n_pos))
		return (1);
	else
		return (0);
}

void			get_triangle_n(t_ray ray, t_obj *obj,
	t_thread *thread, double *dist)
{
	t_vect vector;
	t_vect normal;
	double dot_dir_normal;
	double dot_vector_normal;
	double result;

	(void)thread;
	dot_dir_normal = dot_product_vector(ray.dir, TO_TRIANGLE->normal);
	dot_vector_normal = 0;
	vector = ray.ori;
	normal = TO_TRIANGLE->normal;
	if (dot_dir_normal != 0)
	{
		mult_vector(&normal, TO_TRIANGLE->distance);
		negative_vector(&normal);
		add_to_vector(&vector, normal);
		dot_vector_normal = dot_product_vector(TO_TRIANGLE->normal, vector);
		result = -1 * dot_vector_normal / dot_dir_normal;
		if (is_in_triangle(TO_TRIANGLE, ray, result))
		{
			dist[0] = result;
			dist[1] = result;
			dist[2] = result;
		}
	}
}
