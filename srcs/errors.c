/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguy-caz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 20:12:37 by dguy-caz          #+#    #+#             */
/*   Updated: 2017/06/16 19:50:51 by dguy-caz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		display_errors(int error)
{
	if (error == -1)
	{
		write(2, "Open failed : file not exist\n", 29);
		write(2, "              or permission denied\n", 35);
	}
	if (error == -2)
	{
		write(2,
			"Malloc failed : not enough spaces for this alloc\n", 49);
		write(2, "                or parameter is a directory\n", 44);
	}
	if (error == -3)
		write(2, "invalid map\n", 12);
}
