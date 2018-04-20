/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 00:31:23 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:28 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <dirent.h>

t_scene		*new_scene(char *str)
{
	t_scene	*new;

	new = (t_scene *)ft_memalloc(sizeof(t_scene));
	new->name = ft_strdup(str);
	new->d = NULL;
	new->next = NULL;
	return (new);
}

void		pushback_scene(t_scene **a_lst, t_scene *new)
{
	t_scene		*tmp;

	tmp = *a_lst;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*a_lst = new;
}

t_scene		*get_scene_list(void)
{
	DIR				*dirp;
	struct dirent	*dp;
	t_scene			*lst_scenes;
	int				limit;

	limit = 0;
	lst_scenes = NULL;
	if (!(dirp = opendir("scenes/")))
		ft_error();
	while ((dp = readdir(dirp)) != NULL)
		if (dp->d_name[0] != '.')
			pushback_scene(&lst_scenes, new_scene(dp->d_name));
	closedir(dirp);
	return (lst_scenes);
}
