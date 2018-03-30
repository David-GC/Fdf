/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguy-caz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 20:12:37 by dguy-caz          #+#    #+#             */
/*   Updated: 2017/06/16 19:50:51 by dguy-caz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		display_commands(t_s *s)
{
	mlx_string_put(s->mlx.mlx_ptr, s->mlx.win_ptr,
		30, 30, 0x2459BD, "FDF dguy-caz");
	mlx_string_put(s->mlx.mlx_ptr, s->mlx.win_ptr,
		30, 90, 0x3D99D6, "commmands:");
	mlx_string_put(s->mlx.mlx_ptr, s->mlx.win_ptr,
		50, 120, 0x57D9F0, "rotation:      <- | ->");
	mlx_string_put(s->mlx.mlx_ptr, s->mlx.win_ptr,
		50, 140, 0x57D9F0, "zoom:           - | +");
	mlx_string_put(s->mlx.mlx_ptr, s->mlx.win_ptr,
		50, 160, 0x57D9F0, "height:       bas | haut");
	mlx_string_put(s->mlx.mlx_ptr, s->mlx.win_ptr,
		50, 180, 0x57D9F0, "move:       a | s | w | d");
	mlx_string_put(s->mlx.mlx_ptr, s->mlx.win_ptr,
		50, 200, 0x57D9F0, "reverse:          e");
	mlx_string_put(s->mlx.mlx_ptr, s->mlx.win_ptr,
		50, 230, 0x66FFFF, "exit:            esc");
}

void		display_last_command_1(int keycode, t_s *s)
{
	if (keycode == 123)
		mlx_string_put(s->mlx.mlx_ptr, s->mlx.win_ptr,
			50, 120, 0xff0000, "               <-");
	if (keycode == 124)
		mlx_string_put(s->mlx.mlx_ptr, s->mlx.win_ptr,
			50, 120, 0xff0000, "                    ->");
	if (keycode == 27)
		mlx_string_put(s->mlx.mlx_ptr, s->mlx.win_ptr,
			50, 140, 0xff0000, "                -");
	if (keycode == 24)
		mlx_string_put(s->mlx.mlx_ptr, s->mlx.win_ptr,
			50, 140, 0xff0000, "                    +");
	if (keycode == 126)
		mlx_string_put(s->mlx.mlx_ptr, s->mlx.win_ptr,
			50, 160, 0xff0000, "                    haut");
	if (keycode == 125)
		mlx_string_put(s->mlx.mlx_ptr, s->mlx.win_ptr,
			50, 160, 0xff0000, "              bas");
}

void		display_last_command_2(int keycode, t_s *s)
{
	if (keycode == 0)
		mlx_string_put(s->mlx.mlx_ptr, s->mlx.win_ptr,
			50, 180, 0xff0000, "            a");
	if (keycode == 1)
		mlx_string_put(s->mlx.mlx_ptr, s->mlx.win_ptr,
			50, 180, 0xff0000, "                s");
	if (keycode == 13)
		mlx_string_put(s->mlx.mlx_ptr, s->mlx.win_ptr,
			50, 180, 0xff0000, "                    w");
	if (keycode == 2)
		mlx_string_put(s->mlx.mlx_ptr, s->mlx.win_ptr,
			50, 180, 0xff0000, "                        d");
	if (keycode == 14)
		mlx_string_put(s->mlx.mlx_ptr, s->mlx.win_ptr,
			50, 200, 0xff0000, "                  e");
}
