/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csg_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboualav <aboualav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 22:03:10 by aboualav          #+#    #+#             */
/*   Updated: 2017/06/21 12:25:10 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		positive_condition_add(t_research *r, t_research *rp)
{
	if ((r->c.c1 && r->c.p1 && r->c.neg_behind)
			|| ((r->c.c4 || r->c.c5 || r->c.c6) && r->c.p1))
	{
		r->modified_ray = rp->modified_ray;
		r->current_obj = rp->current_obj;
		r->dist[2] = rp->dist[0];
		return (1);
	}
	if (((r->c.c1 || r->c.c4 || r->c.c6) && r->c.p2)
			|| (r->c.c2 && (r->c.p2 || r->c.in_neg)))
	{
		r->modified_ray = rp->modified_ray;
		r->current_obj = rp->current_obj;
		r->dist[2] = rp->dist[1];
		return (1);
	}
	return (0);
}

static int		negative_condition_add(t_research *r, t_research *rn)
{
	if (((r->c.c1 || r->c.c2 || r->c.c3) && r->c.neg_front)
			|| (r->c.c6 && r->c.p3 && r->c.neg_front))
	{
		r->modified_ray = rn->modified_ray;
		r->current_obj = rn->current_obj;
		r->dist[2] = rn->dist[0];
		return (1);
	}
	if (((r->c.c2 || r->c.c3 || r->c.c6) && r->c.in_neg)
			|| (r->c.c5 && (r->c.in_neg || r->c.p2)))
	{
		r->modified_ray = rn->modified_ray;
		r->current_obj = rn->current_obj;
		r->dist[2] = rn->dist[1];
		return (1);
	}
	return (0);
}

int				check_add(t_research *r, t_research *rp, t_research *rn)
{
	if (rp->dist[2] == 0 && rn->dist[2] > ACC)
	{
		r->modified_ray = rn->modified_ray;
		r->current_obj = rn->current_obj;
		r->dist[2] = rn->dist[2];
		return (1);
	}
	else if (rp->dist[2] > ACC && rn->dist[2] == 0)
	{
		r->modified_ray = rp->modified_ray;
		r->current_obj = rp->current_obj;
		r->dist[2] = rp->dist[2];
		return (1);
	}
	if (positive_condition_add(r, rp))
		return (1);
	else if (negative_condition_add(r, rn))
		return (1);
	else
	{
		r->dist[2] = 0;
		return (1);
	}
}
