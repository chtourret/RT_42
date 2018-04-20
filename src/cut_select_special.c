/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_select_special.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctourret <ctourret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 22:31:36 by ctourret          #+#    #+#             */
/*   Updated: 2017/06/21 12:26:57 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			save_special_case_cone(t_research *r, t_cut *cut)
{
	if ((cut->c_n.c1 && cut->c_n.p2 && cut->c_n.f)
			|| (cut->c_n.c2 && cut->c_n.p2 && cut->c_n.f)
			|| (cut->c_n.c4 && cut->c_n.p1 && cut->c_n.f))
		save_cutted_object(r, cut);
	else
		save_negative_plane(r, cut);
}

void				select_special_case(t_research *r, t_cut *cut)
{
	if (cut->cutted_obj->type == CONE)
		save_special_case_cone(r, cut);
	else
	{
		if ((cut->c_n.c1 && cut->c_n.p1 && cut->c_n.f))
			save_cutted_object(r, cut);
		else
			save_negative_plane(r, cut);
	}
}
