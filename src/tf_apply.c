/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 16:55:02 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:39:59 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		apply_tf(t_obj *obj, t_vect *v, t_data *d, int type)
{
	t_tf_list	*tf_list;
	t_matrix	inverse;

	tf_list = NULL;
	if (d->func->get_obj_tf_list[obj->type] == NULL)
		return ;
	tf_list =
		((t_tf_list *(*)(t_obj *))d->func->get_obj_tf_list[obj->type])(obj);
	while (tf_list)
	{
		if (tf_list->type == SCALE && type == TF_NORMAL)
		{
			inverse = get_inverse_matrix(tf_list->tf);
			apply_matrix(inverse, v);
			normalize_vector(v);
		}
		else if (!((tf_list->type == TRANSLATION) && v->w == 0))
			apply_matrix(tf_list->tf, v);
		tf_list = tf_list->next;
	}
}

void		apply_inverse_tf(t_obj *obj, t_vect *v, t_data *d)
{
	t_tf_list	*tf_list;
	t_matrix	inverse;

	tf_list = NULL;
	if (obj->type == 10)
		return ;
	tf_list =
		((t_tf_list *(*)(t_obj *))d->func->get_obj_tf_list[obj->type])(obj);
	if (tf_list)
		while (tf_list->next)
			tf_list = tf_list->next;
	else
		return ;
	while (tf_list)
	{
		inverse = get_inverse_matrix(tf_list->tf);
		if (!(tf_list->type == TRANSLATION && v->w == 0))
			apply_matrix(inverse, v);
		tf_list = tf_list->previous;
	}
}
