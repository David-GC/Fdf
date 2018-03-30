/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguy-caz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 20:12:37 by dguy-caz          #+#    #+#             */
/*   Updated: 2017/06/16 19:50:51 by dguy-caz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			light_colors(int nb_color, int color)
{
	if (nb_color == 12)
		color = 0x3D99D6;
	if (nb_color == 13)
		color = 0x42A6DB;
	if (nb_color == 14)
		color = 0x47B2E0;
	if (nb_color == 15)
		color = 0x4CBFE6;
	if (nb_color == 16)
		color = 0x52CCEB;
	if (nb_color == 17)
		color = 0x57D9F0;
	if (nb_color == 18)
		color = 0x5CE6F5;
	if (nb_color == 19)
		color = 0x61F2FA;
	if (nb_color == 20)
		color = 0x66FFFF;
	if (nb_color == 21)
		color = 0xA3FFFF;
	if (nb_color == 22)
		color = 0xD9FFFF;
	return (color);
}

int			dark_colors(int nb_color, int color)
{
	if (nb_color == 0)
		color = 0x000099;
	if (nb_color == 1)
		color = 0x050D9E;
	if (nb_color == 2)
		color = 0x0A1AA3;
	if (nb_color == 3)
		color = 0x0F26A8;
	if (nb_color == 4)
		color = 0x1433AD;
	if (nb_color == 5)
		color = 0x1A40B2;
	if (nb_color == 6)
		color = 0x1F4CB8;
	if (nb_color == 7)
		color = 0x2459BD;
	if (nb_color == 8)
		color = 0x2966C2;
	if (nb_color == 9)
		color = 0x2E73C7;
	if (nb_color == 10)
		color = 0x3380CC;
	if (nb_color == 11)
		color = 0x388CD1;
	return (color);
}

int			colors(int mini, int maxi, int nb)
{
	int range;
	int nb_color;
	int color;

	color = 0;
	range = maxi - mini;
	if (nb == 0 && range == 0)
		return (0x000099);
	if (mini >= 0)
		nb_color = round((abs(nb) * 22) / range);
	else
		nb_color = round(((nb - mini) * 22) / range);
	if (nb_color <= 11)
		color = dark_colors(nb_color, color);
	else
		color = light_colors(nb_color, color);
	return (color);
}
