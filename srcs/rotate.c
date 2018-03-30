/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguy-caz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 20:12:37 by dguy-caz          #+#    #+#             */
/*   Updated: 2017/06/16 19:50:51 by dguy-caz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		rotate(t_s *s)
{
	int		cx;
	int		cy;
	int		x;
	int		y;

	x = s->box.x0;
	y = s->box.y0;
	cx = WIN_WIDTH / 2;
	cy = WIN_HEIGHT / 2;
	s->box.xrot = (x - cx) * cos(s->box.angle)
	- (y - cy) * sin(s->box.angle) + cx;
	s->box.yrot = (x - cx) * sin(s->box.angle)
	+ (y - cy) * cos(s->box.angle) + cy;
}
