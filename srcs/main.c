/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguy-caz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 20:12:37 by dguy-caz          #+#    #+#             */
/*   Updated: 2017/06/16 19:50:51 by dguy-caz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			main(int argc, char **argv)
{
	t_s		*s;
	int		error;

	if (!(s = (t_s*)ft_memalloc(sizeof(t_s))))
		return (0);
	s->p_depth = 1;
	s->move_x = 1;
	s->move_y = 1;
	if (argc == 2)
	{
		if ((error = parcing(s, argv[1], 0, 0)))
		{
			display_errors(error);
			return (-1);
		}
		ft_display_window(s);
	}
	else
	{
		write(2, "usage: ./fdf \"map\"\n", 19);
		return (-1);
	}
	return (0);
}
