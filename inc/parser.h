/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboualav <aboualav@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:41:38 by aboualav            #+#    #+#             */
/*   Updated: 2017/06/21 12:36:01 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

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

# define TWO_ATOF ft_atof(cache->params[0]), ft_atof(cache->params[1])

# define POS cache->pos
# define FN cache->filename
# define PARAM_NAME cache->param_name
# define PARAMS cache->params
# define CAC cache

# include "rt.h"
#endif
