/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguy-caz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 20:12:37 by dguy-caz          #+#    #+#             */
/*   Updated: 2017/06/16 19:50:51 by dguy-caz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_s			*tab_nb_creation(t_s *s, char *line, int j)
{
	int		i;
	int		save;

	i = 0;
	save = s->size_width;
	s->size_width = 0;
	s->tab_line = ft_strsplit(line, ' ');
	while (s->tab_line[s->size_width])
		s->size_width++;
	if (!(s->tab_nb[j] = (int*)malloc(sizeof(int) * s->size_width)))
		return (0);
	i = 0;
	if (save && save != s->size_width)
		return (0);
	while (i < s->size_width)
	{
		s->tab_nb[j][i] = ft_atoi(s->tab_line[i]);
		if (abs(s->tab_nb[j][i]) > s->size_depth)
			s->size_depth = abs(s->tab_nb[j][i]);
		free(s->tab_line[i]);
		i++;
	}
	free(s->tab_line);
	return (s);
}

int			parcing(t_s *s, char *src_file, int fd, int j)
{
	char		*line;
	int			ret;

	if (((fd = open(src_file, O_RDONLY)) <= 0))
		return (-1);
	while ((ret = get_next_line(fd, &line)) > 0)
		if (++s->size_height)
			ft_strdel(&line);
	close(fd);
	if (!s->size_height ||
		!(s->tab_nb = (int**)malloc(sizeof(int*) * s->size_height)))
		return (-2);
	if (!(fd = open(src_file, O_RDONLY)))
		return (-1);
	j = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(s = tab_nb_creation(s, line, j++)))
			return (-3);
		ft_strdel(&line);
	}
	s->tab_nb[j] = NULL;
	close(fd);
	count_range_depth(s, j);
	return (0);
}
