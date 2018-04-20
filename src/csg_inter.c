/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csg_inter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 22:06:38 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:25:36 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		positive_condition_inter(t_research *r, t_research *rp)
{
	if ((r->c.c2 || r->c.c3) && r->c.p1)
	{
		r->modified_ray = rp->modified_ray;
		r->current_obj = rp->current_obj;
		r->dist[2] = rp->dist[0];
		return (1);
	}
	if (((r->c.c3) && r->c.p2)
			|| ((r->c.c5) && r->c.p2 && r->c.in_neg))
	{
		r->modified_ray = rp->modified_ray;
		r->current_obj = rp->current_obj;
		r->dist[2] = rp->dist[1];
		return (1);
	}
	return (0);
}

int		negative_condition_inter(t_research *r, t_research *rn)
{
	if ((r->c.c4 || r->c.c5) && r->c.neg_front)
	{
		r->modified_ray = rn->modified_ray;
		r->current_obj = rn->current_obj;
		r->dist[2] = rn->dist[0];
		return (1);
	}
	if ((r->c.c2 || r->c.c4) && r->c.in_neg)
	{
		r->modified_ray = rn->modified_ray;
		r->current_obj = rn->current_obj;
		r->dist[2] = rn->dist[1];
		return (1);
	}
	return (0);
}

int		check_inter(t_research *r, t_research *rp, t_research *rn)
{
	if (positive_condition_inter(r, rp))
		return (1);
	else if (negative_condition_inter(r, rn))
		return (1);
	else
	{
		r->dist[2] = 0;
		return (1);
	}
}
