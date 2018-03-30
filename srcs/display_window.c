/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguy-caz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 20:12:37 by dguy-caz          #+#    #+#             */
/*   Updated: 2017/06/16 19:50:51 by dguy-caz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_display_window(t_s *s)
{
	s->mlx.mlx_ptr = mlx_init();
	s->mlx.win_ptr = mlx_new_window(s->mlx.mlx_ptr,
		WIN_WIDTH, WIN_HEIGHT, "fdf");
	s->mlx.img.img_ptr = mlx_new_image(s->mlx.mlx_ptr,
		WIN_WIDTH, WIN_HEIGHT);
	s->mlx.img.data = (int*)mlx_get_data_addr(s->mlx.img.img_ptr,
		&s->mlx.img.bpp, &s->mlx.img.l_size, &s->mlx.img.endian);
	s_distance(s);
	fill_segments_horizontal(s->mlx.img.data, s);
	fill_segments_vertical(s->mlx.img.data, s);
	mlx_put_image_to_window(s->mlx.mlx_ptr,
		s->mlx.win_ptr, s->mlx.img.img_ptr, 0, 0);
	mlx_hook(s->mlx.win_ptr, 2, (1L << 0), key_functions, s);
	display_commands(s);
	mlx_loop(s->mlx.mlx_ptr);
}
