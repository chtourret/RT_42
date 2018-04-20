/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj_cube.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:21:24 by rqueverd          #+#    #+#             */
/*   Updated: 2017/06/21 12:40:45 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			init_cube_triangles(t_cube *cube, t_vect p[6])
{
	t_vect corner1;
	t_vect corner2;

	corner1 = cube->corner1;
	corner2 = cube->corner2;
	cube->triangle[0] = add_triangle(init_tri_w_p(p[3], p[0], corner1));
	cube->triangle[1] = add_triangle(init_tri_w_p(corner1, p[4], p[3]));
	cube->triangle[2] = add_triangle(init_tri_w_p(corner2, p[1], p[0]));
	cube->triangle[3] = add_triangle(init_tri_w_p(p[0], p[3], corner2));
	cube->triangle[4] = add_triangle(init_tri_w_p(p[5], p[2], p[1]));
	cube->triangle[5] = add_triangle(init_tri_w_p(p[1], corner2, p[5]));
	cube->triangle[6] = add_triangle(init_tri_w_p(p[4], corner1, p[2]));
	cube->triangle[7] = add_triangle(init_tri_w_p(p[2], p[5], p[4]));
	cube->triangle[8] = add_triangle(init_tri_w_p(p[3], p[4], p[5]));
	cube->triangle[9] = add_triangle(init_tri_w_p(p[5], corner2, p[3]));
	cube->triangle[10] = add_triangle(init_tri_w_p(corner1, p[0], p[1]));
	cube->triangle[11] = add_triangle(init_tri_w_p(p[1], p[2], corner1));
}

t_cube			*compute_cube(t_cube *cube)
{
	t_vect corner1;
	t_vect corner2;
	t_vect p[6];

	corner1 = cube->corner1;
	corner2 = cube->corner2;
	p[0] = init_vector(corner2.x, corner1.y, corner1.z, 1);
	p[1] = init_vector(corner2.x, corner1.y, corner2.z, 1);
	p[2] = init_vector(corner1.x, corner1.y, corner2.z, 1);
	p[3] = init_vector(corner2.x, corner2.y, corner1.z, 1);
	p[4] = init_vector(corner1.x, corner2.y, corner1.z, 1);
	p[5] = init_vector(corner1.x, corner2.y, corner2.z, 1);
	init_cube_triangles(cube, p);
	return (cube);
}

void			cube_bzero(t_cube *cube)
{
	cube->corner1 = init_vector(-1, -1, 1, 1);
	cube->corner2 = init_vector(1, 1, -1, 1);
	cube->color = set_color(0, 255, 255);
	cube->tf_list = NULL;
	cube->reflection = 0.7;
	cube->shine = 0.7;
	cube->texture = NULL;
	cube->bumpmap = NULL;
	cube->cut = NULL;
}

t_cube			*init_cube(void)
{
	t_cube		*cube;
	int			i;

	i = -1;
	cube = (t_cube *)ft_memalloc(sizeof(t_cube));
	cube->closest_triangle = (int *)ft_memalloc(sizeof(int) * THREADS);
	while (++i < THREADS)
		cube->closest_triangle[i] = -1;
	i = -1;
	cube->triangle = (t_obj **)ft_memalloc(sizeof(t_obj *) * 12);
	while (++i < 12)
		cube->triangle[i] = NULL;
	cube_bzero(cube);
	return (cube);
}

t_solid			*get_cube_solid(void *p)
{
	t_cube		*cube;
	t_solid		*solid;

	cube = (t_cube *)p;
	solid = (t_solid *)ft_memalloc(sizeof(t_solid));
	solid->cube = cube;
	return (solid);
}
