/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboualav <aboualav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 21:43:48 by aboualav          #+#    #+#             */
/*   Updated: 2017/06/21 12:36:04 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "libft.h"
# include "mlx.h"
# include "keys.h"
# include "threads.h"
# include "rt_structs.h"
# include "rt_proto.h"
# include "parser.h"
# include <math.h>

# define THREADS 8
# define AA_LVL 1
# define ACC 0.000001
# define REFLECTIONS 2
# define AMBIENT 0.5
# define DIFFUSE 1

# define WIDTH 1000
# define HEIGHT 640

# define FOUND 1
# define NOT_FOUND 0

# define ROTATION_X 0
# define ROTATION_Y 1
# define ROTATION_Z 2
# define TRANSLATION 3
# define SCALE 4
# define ROTATION_XYZ 5

# define SPHERE 0
# define PLANE 1
# define CYLINDER 2
# define CONE 3
# define TRIANGLE 4
# define PRISM 5
# define CUBE 6
# define PARABOLOID 7
# define HYPERBOLOID 8
# define CSG 9

# define OBJECT_NUMBER 10
# define TO_SPHERE obj->solid->sphere
# define TO_PLANE obj->solid->plane
# define TO_CYLINDER obj->solid->cylinder
# define TO_CONE obj->solid->cone
# define TO_TRIANGLE obj->solid->triangle
# define TO_PRISM obj->solid->prism
# define TO_CUBE obj->solid->cube
# define TO_PARABOLOID obj->solid->paraboloid
# define TO_HYPERBOLOID obj->solid->hyperboloid
# define TO_CSG obj->solid->csg
# define COLOR ((t_color (*)(t_obj *))d->func->get_obj_color[info->type])

# define GET_COLOR_MOY(X,Y) moy(img_pull_pixel(X, Y, &tex->img)) / (double)255

# define INITIAL_RAY 0
# define SHADOW_RAY 1
# define REFLECTION_RAY 2

# define TF_NORMAL 0
# define TF_RAY 1
# define TF_INTERSECTION 2

# define ABS(X) (X) < 0 ? -(X) : (X)

# define SINX 1
# define SINY 2
# define QUAD 3
# define SINXY 4

# define DOUBLE 0
# define STRING 1
# define NOTHING 0
# define CONTEXT_OPENER 1
# define CONTEXT_CLOSER 2
# define DECLARATOR 3
# define PARAMETER 4

# define UNION 1
# define INTER 2
# define DIFF 3

# define NEXT 1

#endif
