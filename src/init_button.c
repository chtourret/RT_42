/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 04:12:56 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:31:14 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_butt			*new_butt(int nb, int xmin, int ymin)
{
	t_butt		*new;

	new = (t_butt*)ft_memalloc(sizeof(t_butt));
	new->xmin = xmin;
	new->xmax = xmin + 275;
	new->ymin = ymin;
	new->ymax = ymin + 200;
	new->moon = nb;
	new->next = NULL;
	return (new);
}

void			butt_pushback(t_butt **alst, t_butt *new)
{
	t_butt		*tmp;

	if (!(*alst))
		*alst = new;
	else
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_butt			*init_butt(void)
{
	t_butt		*moon;
	static int	x[6] = {80, 380, 680, 80, 380, 680};
	static int	y[6] = {100, 100, 100, 350, 350, 350};
	int			pone;

	pone = 0;
	moon = NULL;
	while (pone < 6)
	{
		butt_pushback(&moon, new_butt(pone, x[pone], y[pone]));
		pone++;
	}
	return (moon);
}
