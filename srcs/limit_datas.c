/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit_datas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguy-caz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 20:12:37 by dguy-caz          #+#    #+#             */
/*   Updated: 2017/06/16 19:50:51 by dguy-caz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		s_distance(t_s *s)
{
	int		res;
	int		ref;
	int		size_win;
	int		size_tab;

	size_win = (WIN_WIDTH >= WIN_HEIGHT) ? WIN_HEIGHT : WIN_WIDTH;
	size_tab = (s->size_width >= s->size_height) ?
	s->size_width : s->size_height;
	ref = 1080 / 19;
	res = size_win / size_tab;
	s->p_dist = (res * 35) / ref;
}

void		count_range_depth(t_s *s, int j)
{
	int			i;

	s->maxi = s->tab_nb[0][0];
	s->mini = s->tab_nb[0][0];
	j = 0;
	while (j < s->size_height)
	{
		i = 0;
		while (i < s->size_width)
		{
			if (s->tab_nb[j][i] > s->maxi)
				s->maxi = s->tab_nb[j][i];
			if (s->tab_nb[j][i] < s->mini)
				s->mini = s->tab_nb[j][i];
			i++;
		}
		j++;
	}
}
