/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguy-caz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 20:12:37 by dguy-caz          #+#    #+#             */
/*   Updated: 2017/06/16 19:50:51 by dguy-caz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fill_segments_horizontal(int *data, t_s *s)
{
	int *save;

	save = data;
	s->box.j = 0;
	s->box.h = -s->p_dist + s->move_y;
	while (s->box.j < s->size_height)
	{
		s->box.i = 0;
		s->box.w = (WIN_WIDTH / 2) + s->move_x;
		while (s->box.i < s->size_width - 1)
		{
			bresenham_datas(s, 1);
			if (s->tab_nb[s->box.j][s->box.i] >=
				s->tab_nb[s->box.j][s->box.i + 1])
				bresenham(data, s, s->tab_nb[s->box.j][s->box.i]);
			else
				bresenham(data, s, s->tab_nb[s->box.j][s->box.i + 1]);
			s->box.w += s->p_dist;
			s->box.i++;
		}
		s->box.h += s->p_dist;
		s->box.j++;
	}
}

void		fill_segments_vertical(int *data, t_s *s)
{
	s->box.i = 0;
	s->box.w = (WIN_WIDTH / 2) + s->move_x;
	while (s->box.i < s->size_width)
	{
		s->box.j = 0;
		s->box.h = -s->p_dist + s->move_y;
		while (s->box.j < s->size_height - 1)
		{
			bresenham_datas(s, 2);
			if (s->tab_nb[s->box.j][s->box.i] >=
				s->tab_nb[s->box.j + 1][s->box.i])
				bresenham(data, s, s->tab_nb[s->box.j][s->box.i]);
			else
				bresenham(data, s, s->tab_nb[s->box.j + 1][s->box.i]);
			s->box.h += s->p_dist;
			s->box.j++;
		}
		s->box.w += s->p_dist;
		s->box.i++;
	}
}
