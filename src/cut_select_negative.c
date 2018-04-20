/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_select_negative.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctourret <ctourret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 22:17:54 by ctourret          #+#    #+#             */
/*   Updated: 2017/06/21 12:26:43 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			save_negative_case_cone(t_research *r, t_cut *cut)
{
	if ((cut->c_n.c1 && cut->c_n.p1 && cut->c_n.f)
			|| (cut->c_n.c1 && cut->c_n.p3 && cut->c_n.f)
			|| (cut->c_n.c2 && cut->c_n.p3 && cut->c_n.f)
			|| (cut->c_n.c3 && cut->c_n.p3 && cut->c_n.f)
			|| (cut->c_n.c4 && cut->c_n.p2 && cut->c_n.f)
			|| (cut->c_n.c5 && cut->c_n.p2 && cut->c_n.f))
		save_negative_plane(r, cut);
	else if ((cut->c_n.c4 && cut->c_n.p3)
			|| (cut->c_n.c5 && cut->c_n.p3))
		save_nothing(r, cut);
	else if ((cut->c_n.c1 && cut->c_n.p2)
			|| (cut->c_n.c2 && cut->c_n.p2 && cut->c_n.f))
	{
		save_cutted_object(r, cut);
		r->dist[2] = r->dist[1];
	}
	else if (cut->c_n.c4 && cut->c_n.p1 && cut->c_n.f)
		save_cutted_object(r, cut);
}

static void			save_negative_case(t_research *r, t_cut *cut)
{
	if ((cut->c_n.c1 && cut->c_n.p2 && cut->c_n.f)
			|| (cut->c_n.c2 && cut->c_n.p2 && cut->c_n.f))
		save_negative_plane(r, cut);
	else if ((cut->c_n.c1 && cut->c_n.p3)
			|| (cut->c_n.c2 && cut->c_n.p3))
		save_nothing(r, cut);
	else if (cut->c_n.c1 && cut->c_n.p1 && cut->c_n.f)
		save_cutted_object(r, cut);
}

void				select_negative_case(t_research *r, t_cut *cut)
{
	if (cut->cutted_obj->type == CONE)
		save_negative_case_cone(r, cut);
	else
		save_negative_case(r, cut);
}
