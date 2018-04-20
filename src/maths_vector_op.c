/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_vector_op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 00:45:34 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:41:54 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

void		add_to_vector(t_vect *v1, t_vect v2)
{
	v1->x += v2.x;
	v1->y += v2.y;
	v1->z += v2.z;
}

void		substract_to_vector(t_vect *v1, t_vect v2)
{
	v1->x -= v2.x;
	v1->y -= v2.y;
	v1->z -= v2.z;
}

double		dot_product_vector(t_vect v1, t_vect v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vect		cross_product_vector(t_vect v1, t_vect v2)
{
	t_vect cross_product;

	cross_product = init_vector(v1.y * v2.z - v1.z * v2.y,
			v1.z * v2.x - v1.x * v2.z,
			v1.x * v2.y - v1.y * v2.x, 0);
	return (cross_product);
}

t_vect		define_obj_normal(t_record *info,
		t_data *d, t_thread *thread)
{
	t_vect		obj_normal;

	obj_normal = ((t_vect (*)(t_obj *, t_vect, t_thread *))
			d->func->get_obj_normal[info->type])(info->obj,
				info->n_pos, thread);
	apply_tf(info->obj, &obj_normal, d, TF_NORMAL);
	return (obj_normal);
}
