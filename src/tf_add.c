/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 16:54:42 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:00 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_tf_list	*add_zrot_tf(double deg)
{
	t_tf_list *tf_list;

	tf_list = (t_tf_list *)ft_memalloc(sizeof(t_tf_list));
	tf_list->tf = init_zrotation_matrix(deg);
	tf_list->type = ROTATION_Z;
	tf_list->next = NULL;
	tf_list->previous = NULL;
	return (tf_list);
}

t_tf_list	*add_yrot_tf(double deg)
{
	t_tf_list *tf_list;

	tf_list = (t_tf_list *)ft_memalloc(sizeof(t_tf_list));
	tf_list->tf = init_yrotation_matrix(deg);
	tf_list->type = ROTATION_Y;
	tf_list->next = NULL;
	tf_list->previous = NULL;
	return (tf_list);
}

t_tf_list	*add_xrot_tf(double deg)
{
	t_tf_list *tf_list;

	tf_list = (t_tf_list *)ft_memalloc(sizeof(t_tf_list));
	tf_list->tf = init_xrotation_matrix(deg);
	tf_list->type = ROTATION_X;
	tf_list->next = NULL;
	tf_list->previous = NULL;
	return (tf_list);
}

t_tf_list	*add_trans_tf(t_vect t)
{
	t_tf_list *tf_list;

	tf_list = (t_tf_list *)ft_memalloc(sizeof(t_tf_list));
	tf_list->tf = init_translation_matrix(t.x, t.y, t.z);
	tf_list->type = TRANSLATION;
	tf_list->next = NULL;
	tf_list->previous = NULL;
	return (tf_list);
}

t_tf_list	*add_scale_tf(double x, double y, double z)
{
	t_tf_list *tf_list;

	tf_list = (t_tf_list *)ft_memalloc(sizeof(t_tf_list));
	tf_list->tf = init_scale_matrix(x, y, z);
	tf_list->type = SCALE;
	tf_list->next = NULL;
	tf_list->previous = NULL;
	return (tf_list);
}
