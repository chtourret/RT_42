/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 16:55:52 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:39:57 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		push_zrot_tf(t_tf_list **begin_tf_list, double deg)
{
	t_tf_list *tmp;

	tmp = *begin_tf_list;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_zrot_tf(deg);
		tmp->next->previous = tmp;
	}
	else
		*begin_tf_list = add_zrot_tf(deg);
}

void		push_yrot_tf(t_tf_list **begin_tf_list, double deg)
{
	t_tf_list *tmp;

	tmp = *begin_tf_list;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_yrot_tf(deg);
		tmp->next->previous = tmp;
	}
	else
		*begin_tf_list = add_yrot_tf(deg);
}

void		push_xrot_tf(t_tf_list **begin_tf_list, double deg)
{
	t_tf_list *tmp;

	tmp = *begin_tf_list;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_xrot_tf(deg);
		tmp->next->previous = tmp;
	}
	else
		*begin_tf_list = add_xrot_tf(deg);
}

void		push_trans_tf(t_tf_list **begin_tf_list, double x, double y,
		double z)
{
	t_tf_list	*tmp;
	t_vect		t;

	t = init_vector(x, y, z, 0);
	tmp = *begin_tf_list;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_trans_tf(t);
		tmp->next->previous = tmp;
	}
	else
		*begin_tf_list = add_trans_tf(t);
}

void		push_scale_tf(t_tf_list **begin_tf_list, double x, double y,
		double z)
{
	t_tf_list	*tmp;
	t_vect		t;

	t = init_vector(x, y, z, 0);
	tmp = *begin_tf_list;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_scale_tf(x, y, z);
		tmp->next->previous = tmp;
	}
	else
		*begin_tf_list = add_scale_tf(x, y, z);
}
