/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cut_condition.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctourret <ctourret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:15:37 by ctourret          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:49 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			init_cut_condition_cone(t_research *r, t_cut *cut)
{
	cut->c.c1 = (r->dist[0] > ACC && r->dist[1] > ACC && cut->c.in);
	cut->c.c2 = (r->dist[0] < 0 && r->dist[1] > ACC && !cut->c.in);
	cut->c.c3 = (r->dist[0] < 0 && r->dist[1] < 0 && cut->c.in);
	cut->c.c4 = (r->dist[0] > ACC && r->dist[1] > ACC && !cut->c.in);
	cut->c.c5 = (r->dist[0] < 0 && r->dist[1] > ACC && cut->c.in);
	cut->c.c6 = (r->dist[0] < 0 && r->dist[1] < 0 && !cut->c.in);
	cut->c.f = cut->plane[2] > ACC;
	cut->c.b = cut->plane[2] < 0;
	cut->c.p1 = cut->plane[2] < r->dist[0];
	cut->c.p2 = cut->plane[2] > r->dist[0] && cut->plane[2] < r->dist[1];
	cut->c.p3 = cut->plane[2] > r->dist[1];
}

void			init_cut_condition_others(t_research *r, t_cut *cut)
{
	cut->c.c1 = (r->dist[0] > ACC && r->dist[1] > ACC);
	cut->c.c2 = (r->dist[0] < 0 && r->dist[1] > ACC);
	cut->c.c3 = (r->dist[0] < 0 && r->dist[1] < 0);
	cut->c.c4 = 0;
	cut->c.c5 = 0;
	cut->c.c6 = 0;
	cut->c.f = cut->plane[2] > ACC;
	cut->c.b = cut->plane[2] < 0;
	cut->c.p1 = cut->plane[2] < r->dist[0];
	cut->c.p2 = cut->plane[2] > r->dist[0] && cut->plane[2] < r->dist[1];
	cut->c.p3 = cut->plane[2] > r->dist[1];
}
