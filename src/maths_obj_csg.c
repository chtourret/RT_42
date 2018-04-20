/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_obj_csg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 00:39:49 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:22 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		transform_double(double *p, double *n)
{
	if (p[0] == 0 && p[1] == 0 && p[2] == 0)
	{
		p[0] = -1;
		p[1] = -1;
		p[2] = -1;
	}
	if (n[0] == 0 && n[1] == 0 && n[2] == 0)
	{
		n[0] = -1;
		n[1] = -1;
		n[2] = -1;
	}
}

void			init_conditions_diff(t_research *r, double *p, double *n,
		int type)
{
	if (type != UNION)
		transform_double(p, n);
	r->c.c1 = ((n[0] <= n[1] && p[0] < p[1]
				&& n[1] < p[0]) || (n[0] <= n[1]
				&& n[1] <= p[0] && p[0] == p[1]));
	r->c.c2 = (n[0] <= p[0] && p[0] <= n[1]
			&& n[1] <= p[1]);
	r->c.c3 = (n[0] <= p[0] && p[0] <= p[1]
			&& p[1] <= n[1]);
	r->c.c4 = (p[0] <= n[0] && n[0] <= p[1]
			&& n[1] <= p[1]);
	r->c.c5 = (p[0] <= n[0] && n[0] <= p[1]
			&& p[1] <= n[1]);
	r->c.c6 = (p[0] <= p[1] && p[1] <= n[0]
			&& n[0] <= n[1]);
	r->c.in_neg = (n[0] < 0 && n[1] > ACC);
	r->c.neg_behind = n[0] < 0 && n[1] < 0;
	r->c.neg_front = n[0] > ACC && n[1] > ACC;
	r->c.p1 = p[0] > ACC && p[1] > p[0];
	r->c.p2 = p[0] < 0 && p[1] > ACC;
	r->c.p3 = p[0] < p[1] && p[1] < 0;
}

void			calculate_first_and_second(t_research *rp,
	t_research *rn, t_data *d, t_thread *thread)
{
	apply_inverse_tf(rp->current_obj, &(rp->modified_ray.ori), d);
	apply_inverse_tf(rp->current_obj, &(rp->modified_ray.dir), d);
	((void (*)(t_ray ray, t_obj *, t_thread *, double *))
	d->func->get_obj_n[rp->current_obj->type])
		(rp->modified_ray, rp->current_obj, thread, rp->dist);
	apply_inverse_tf(rn->current_obj, &(rn->modified_ray.ori), d);
	apply_inverse_tf(rn->current_obj, &(rn->modified_ray.dir), d);
	((void (*)(t_ray ray, t_obj *, t_thread *, double *))
	d->func->get_obj_n[rn->current_obj->type])
		(rn->modified_ray, rn->current_obj, thread, rn->dist);
}

void			get_csg_n(t_research *r, t_thread *thread, t_data *d)
{
	t_obj		*obj;
	t_research	rn;
	t_research	rp;

	obj = r->current_obj;
	rp = *r;
	rp.current_obj = TO_CSG->first;
	rn = *r;
	rn.current_obj = TO_CSG->second;
	if (TO_CSG->operation == DIFF)
		*(rn.current_obj->reflectionx) = 0;
	calculate_first_and_second(&rp, &rn, d, thread);
	if (rp.current_obj->type == PLANE)
		rp.dist[1] += ACC;
	init_conditions_diff(r, rp.dist, rn.dist, TO_CSG->operation);
	if (TO_CSG->operation == DIFF)
		check_diff(r, &rp, &rn);
	else if (TO_CSG->operation == INTER)
		check_inter(r, &rp, &rn);
	else if (TO_CSG->operation == UNION)
		check_add(r, &rp, &rn);
}
