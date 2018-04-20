/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_research_in_cone.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 22:11:26 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:25:59 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		research_in_cone(t_research *r, t_cut *cut)
{
	if ((cut->c.b && cut->dot > 0) ||
			(cut->c.c2 && cut->c.f && cut->c.p2 && cut->dot > 0) ||
			(cut->c.c4 && cut->c.f && cut->c.p1 && cut->dot > 0) ||
			(cut->c.c4 && cut->c.f && cut->c.p3 && cut->dot <= 0) ||
			(cut->c.c5 && cut->c.f && cut->c.p3 && cut->dot <= 0) ||
			(cut->c.c6 && cut->c.f && cut->dot <= 0))
		return (keep_nothing(r, cut));
	else if (((cut->c.c1 || cut->c.c3) && cut->c.f) ||
			(cut->c.c2 && cut->c.f && cut->dot > 0 && cut->c.p3) ||
			(cut->c.c2 && cut->c.f && cut->dot <= 0) ||
			(cut->c.c4 && cut->c.f && cut->dot > 0 && cut->c.p2) ||
			(cut->c.c4 && cut->c.f && cut->dot <= 0 && cut->c.p2) ||
			(cut->c.c5 && cut->c.f && cut->dot > 0 && cut->c.p2) ||
			(cut->c.c5 && cut->c.f && cut->dot <= 0 && cut->c.p2))
		return (keep_plane(cut));
	else if (((cut->c.c1 || cut->c.c2) && cut->c.b && cut->dot <= 0) ||
			((cut->c.c3 || cut->c.c4) && cut->c.b && cut->dot <= 0) ||
			(cut->c.c4 && cut->c.f && cut->dot > 0 && cut->c.p3) ||
			(cut->c.c4 && cut->c.f && cut->dot <= 0 && cut->c.p1) ||
			(cut->c.c5 && cut->c.f && cut->dot > 0 && cut->c.p3) ||
			((cut->c.c5 || cut->c.c6) && cut->c.b && cut->dot <= 0) ||
			(cut->c.c6 && cut->c.f && cut->dot > 0))
		return (NEXT);
	return (0);
}

int		research_in_others(t_research *r, t_cut *cut)
{
	if ((cut->c.b && cut->dot > 0) ||
			(cut->c.c1 && cut->c.f && cut->c.p1 && cut->dot > 0) ||
			(cut->c.c1 && cut->c.f && cut->c.p3 && cut->dot <= 0) ||
			(cut->c.c2 && cut->c.f && cut->c.p3 && cut->dot <= 0) ||
			(cut->c.c3 && cut->c.f && cut->dot <= 0))
		return (keep_nothing(r, cut));
	else if ((cut->c.c1 && cut->c.f && cut->dot > 0 && cut->c.p2) ||
			(cut->c.c1 && cut->c.f && cut->dot <= 0 && cut->c.p2) ||
			(cut->c.c2 && cut->c.f && cut->dot > 0 && cut->c.p2) ||
			(cut->c.c2 && cut->c.f && cut->dot <= 0 && cut->c.p2))
		return (keep_plane(cut));
	else if (((cut->c.c1) && cut->c.b && cut->dot <= 0) ||
			(cut->c.c1 && cut->c.f && cut->dot > 0 && cut->c.p3) ||
			(cut->c.c1 && cut->c.f && cut->dot <= 0 && cut->c.p1) ||
			(cut->c.c2 && cut->c.f && cut->dot > 0 && cut->c.p3) ||
			((cut->c.c2 || cut->c.c3) && cut->c.b && cut->dot <= 0) ||
			(cut->c.c3 && cut->c.f && cut->dot > 0))
		return (NEXT);
	return (0);
}
