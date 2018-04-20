/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_names.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:57:26 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:27:03 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			print_page_string(t_env *e)
{
	char		*str;
	char		*tmp;

	if (!(str = (char *)ft_memalloc(sizeof(char) * 15)))
		ft_malloc_error();
	str = ft_strcat(str, "Page : ");
	tmp = ft_itoa(e->page + 1);
	str = ft_strcat(str, tmp);
	free(tmp);
	str = ft_strcat(str, " / ");
	tmp = ft_itoa(e->page_m);
	str = ft_strcat(str, tmp);
	mlx_string_put(e->mlx, e->win, 10, 10, 0xFFFFFF, str);
	free(tmp);
	free(str);
}

char			*get_scene_name(int nb, char *name)
{
	char		*str;
	char		*tmp;

	if (!(str = (char *)malloc(sizeof(char) * 18)))
		ft_malloc_error();
	ft_bzero(str, 18);
	tmp = ft_itoa(nb + 1);
	ft_strcat(str, tmp);
	free(tmp);
	ft_strcat(str, ". ");
	ft_strncat(str, name, 14);
	return (str);
}
