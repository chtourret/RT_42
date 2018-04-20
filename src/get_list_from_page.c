/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list_from_page.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:12:14 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:30:27 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_scene			*get_list_from_page(t_scene *lst, int p)
{
	int			cpt;
	t_scene		*tmp;

	tmp = lst;
	cpt = 0;
	while (tmp && (cpt++ / 6 < p))
		tmp = tmp->next;
	return (tmp);
}
