/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 04:54:32 by tglandai          #+#    #+#             */
/*   Updated: 2017/06/21 12:30:22 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				ft_malloc_error(void)
{
	write(2, "Malloc error. Program will now close.\n", 38);
	exit(0);
}

void				ft_parsing_error(int linenbr, char *line, char *filename)
{
	ft_putstr("Error at line ");
	ft_putnbr(linenbr);
	if (filename != NULL)
	{
		ft_putstr(" of ");
		ft_putstr(filename);
	}
	ft_putstr(": ");
	ft_putendl(line);
	write(2, "Error parsing file. Use a valid file\n", 37);
	exit(0);
}

void				ft_error(void)
{
	write(2, "Program encountered a fatal error.\n", 35);
	exit(0);
}
