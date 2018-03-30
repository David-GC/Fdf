/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguy-caz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 20:12:37 by dguy-caz          #+#    #+#             */
/*   Updated: 2017/06/16 19:50:51 by dguy-caz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		bresenham_datas(t_s *s, int orientation)
{
	s->box.x0 = s->box.w - s->box.h;
	s->box.y0 = (s->box.w + s->box.h
		- s->tab_nb[s->box.j][s->box.i] * s->p_depth) / 2;
	if (orientation == 1)
	{
		s->box.x1 = s->box.w + s->p_dist - s->box.h;
		s->box.y1 = (s->box.w + s->p_dist + s->box.h
			- s->tab_nb[s->box.j][s->box.i + 1] * s->p_depth) / 2;
	}
	else
	{
		s->box.x1 = s->box.w - s->p_dist - s->box.h;
		s->box.y1 = (s->box.w + s->p_dist + s->box.h
			- s->tab_nb[s->box.j + 1][s->box.i] * s->p_depth) / 2;
	}
	s->box.dx = abs(s->box.x1 - s->box.x0);
	s->box.dy = abs(s->box.y1 - s->box.y0);
	s->box.sx = (s->box.x0 < s->box.x1) ? 1 : -1;
	s->box.sy = (s->box.y0 < s->box.y1) ? 1 : -1;
	s->box.err = ((s->box.dx > s->box.dy) ? s->box.dx : -s->box.dy) / 2;
}

void		bresenham(int *data, t_s *s, int nb)
{
	int		color;

	while (1)
	{
		rotate(s);
		if (s->box.xrot > 0 && s->box.xrot < WIN_WIDTH
			&& s->box.yrot > 0 && s->box.yrot < WIN_HEIGHT)
		{
			color = colors(s->mini, s->maxi, nb);
			data[s->box.xrot + s->box.yrot * WIN_WIDTH] = color;
		}
		if (s->box.x0 == s->box.x1 && s->box.y0 == s->box.y1)
			break ;
		s->box.err2 = s->box.err;
		if (s->box.err2 > -s->box.dx)
		{
			s->box.err -= s->box.dy;
			s->box.x0 += s->box.sx;
		}
		if (s->box.err2 < s->box.dy)
		{
			s->box.err += s->box.dx;
			s->box.y0 += s->box.sy;
		}
	}
}
