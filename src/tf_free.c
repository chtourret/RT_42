/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 16:55:43 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:39:58 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_tf_list	*free_tf_list(t_tf_list **begin_tf_list)
{
	t_tf_list *tmp;
	t_tf_list *tmp2;

	tmp = *begin_tf_list;
	tmp2 = NULL;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	*begin_tf_list = NULL;
	return (NULL);
}

void		free_texture(void *mlx, t_texture *b_list)
{
	t_texture		*tmp_0;
	t_texture		*tmp_1;

	tmp_0 = b_list;
	if (tmp_0)
		while (tmp_0)
		{
			tmp_1 = tmp_0->next;
			if (tmp_0->img.img)
				mlx_destroy_image(mlx, tmp_0->img.img);
			free(tmp_0->path);
			free(tmp_0);
			tmp_0 = tmp_1;
		}
}

t_obj		*free_cut(t_obj **begin_cut)
{
	t_obj *tmp;
	t_obj *tmp2;

	tmp = *begin_cut;
	tmp2 = NULL;
	while (tmp)
	{
		tmp2 = tmp->next;
		free_obj(&tmp->cut);
		free(tmp);
		tmp = tmp2;
	}
	*begin_cut = NULL;
	return (NULL);
}

t_cube		*free_cube(t_cube *cube)
{
	int i;

	i = 0;
	if (cube)
	{
		free_tf_list(&(cube->tf_list));
		while (i < 12)
		{
			if (cube->triangle[i])
				free_obj(&cube->triangle[i]);
			i++;
		}
		free_cut(&cube->cut);
		free(cube);
		cube = NULL;
	}
	return (NULL);
}

void		select_free_obj(t_obj *tmp)
{
	if (tmp->type == SPHERE && tmp->solid)
		free_sphere(tmp->solid->sphere);
	else if (tmp->type == PLANE && tmp->solid)
		free_plane(tmp->solid->plane);
	else if (tmp->type == CYLINDER && tmp->solid)
		free_cylinder(tmp->solid->cylinder);
	else if (tmp->type == CONE && tmp->solid)
		free_cone(tmp->solid->cone);
	else if (tmp->type == CSG && tmp->solid)
		free_csg(tmp->solid->csg);
	else if (tmp->type == HYPERBOLOID && tmp->solid)
		free_hyperboloid(tmp->solid->hyperboloid);
	else if (tmp->type == PARABOLOID && tmp->solid)
		free_paraboloid(tmp->solid->paraboloid);
	else if (tmp->type == PRISM && tmp->solid)
		free_prism(tmp->solid->prism);
	else if (tmp->type == CUBE && tmp->solid)
		free_cube(tmp->solid->cube);
}
