/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:10:34 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:45:54 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *robin;
	t_list *batman;

	batman = *alst;
	while (batman != NULL)
	{
		robin = batman->next;
		ft_lstdelone(&batman, del);
		batman = robin;
	}
	*alst = NULL;
}
