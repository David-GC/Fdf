/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interactions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguy-caz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 20:12:37 by dguy-caz          #+#    #+#             */
/*   Updated: 2017/06/16 19:50:51 by dguy-caz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		key_move(int keycode, t_s *s)
{
	if (keycode == 2)
	{
		s->move_x += 5;
		s->move_y -= 5;
	}
	if (keycode == 0)
	{
		s->move_x -= 5;
		s->move_y += 5;
	}
	if (keycode == 13)
	{
		s->move_x -= 10;
		s->move_y -= 10;
	}
	if (keycode == 1)
	{
		s->move_x += 10;
		s->move_y += 10;
	}
}

void		key_rotation(int keycode, t_s *s)
{
	if (keycode == 124)
		s->box.angle += 0.02;
	if (keycode == 123)
		s->box.angle -= 0.02;
}

void		key_height(int keycode, t_s *s)
{
	if (keycode == 126)
		s->p_depth *= 1.1;
	if (keycode == 125)
	{
		if (s->p_depth >= 0.05 || s->p_depth <= -0.05)
			s->p_depth *= 0.9;
	}
	if (keycode == 14)
		s->p_depth *= -1;
}

void		key_zoom(int keycode, t_s *s)
{
	if (keycode == 27)
	{
		s->p_dist /= 1.1;
		s->p_depth /= 1.1;
	}
	if (keycode == 24)
	{
		s->p_dist *= 1.1;
		s->p_depth *= 1.1;
	}
}

int			key_functions(int keycode, t_s *s)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	else if (keycode == 24 || keycode == 27)
		key_zoom(keycode, s);
	else if (keycode == 125 || keycode == 126 || keycode == 14)
		key_height(keycode, s);
	else if (keycode == 123 || keycode == 124)
		key_rotation(keycode, s);
	else if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
		key_move(keycode, s);
	else
		return (0);
	ft_bzero(s->mlx.img.data, WIN_WIDTH * WIN_HEIGHT * 4);
	fill_segments_horizontal(s->mlx.img.data, s);
	fill_segments_vertical(s->mlx.img.data, s);
	mlx_put_image_to_window(s->mlx.mlx_ptr,
		s->mlx.win_ptr, s->mlx.img.img_ptr, 0, 0);
	display_commands(s);
	display_last_command_1(keycode, s);
	display_last_command_2(keycode, s);
	return (0);
}
