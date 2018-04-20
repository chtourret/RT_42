/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_select_positive.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctourret <ctourret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 22:31:17 by ctourret          #+#    #+#             */
/*   Updated: 2017/06/21 12:26:49 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			save_positive_case_cone(t_research *r, t_cut *cut)
{
	if ((cut->c_p.c1 && cut->c_p.p1 && cut->c_p.f)
			|| (cut->c_p.c3 && cut->c_p.p3 && cut->c_p.f)
			|| (cut->c_p.c5 && cut->c_p.p2 && cut->c_p.f))
		save_positive_plane(r, cut);
	else if ((cut->c_p.c1 && cut->c_p.b)
			|| (cut->c_p.c2 && cut->c_p.b)
			|| (cut->c_p.c2 && cut->c_p.f && cut->c_p.p2)
			|| (cut->c_p.c3 && cut->c_p.b)
			|| (cut->c_p.c4 && cut->c_p.b)
			|| (cut->c_p.c4 && cut->c_p.f && cut->c_p.p1)
			|| (cut->c_p.c5 && cut->c_p.b)
			|| (cut->c_p.c6 && cut->c_p.b))
		save_nothing(r, cut);
	else if ((cut->c_p.c1 && cut->c_p.p2 && cut->c_p.f)
			|| (cut->c_p.c1 && cut->c_p.p3 && cut->c_p.f)
			|| (cut->c_p.c2 && cut->c_p.p3 && cut->c_p.f)
			|| (cut->c_p.c4 && cut->c_p.p1 && cut->c_p.f)
			|| (cut->c_p.c4 && cut->c_p.p3 && cut->c_p.f))
		save_cutted_object(r, cut);
}

static void			save_positive_case(t_research *r, t_cut *cut)
{
	if ((cut->c_p.c2 && cut->c_p.p2 && cut->c_p.f))
		save_positive_plane(r, cut);
	if ((cut->c_p.c1 && cut->c_p.b)
			|| (cut->c_p.c1 && cut->c_p.f && cut->c_p.p1)
			|| (cut->c_p.c2 && cut->c_p.b)
			|| (cut->c_p.c3 && cut->c_p.b))
		save_nothing(r, cut);
	if ((cut->c_p.c1 && cut->c_p.p1 && cut->c_p.f)
			|| (cut->c_p.c1 && cut->c_p.p3 && cut->c_p.f))
		save_cutted_object(r, cut);
}

void				select_positive_case(t_research *r, t_cut *cut)
{
	if (cut->cutted_obj->type == CONE)
		save_positive_case_cone(r, cut);
	else
		save_positive_case(r, cut);
}
