/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguy-caz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:53:25 by dguy-caz          #+#    #+#             */
/*   Updated: 2017/06/16 22:53:27 by dguy-caz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define WIN_WIDTH 1600
# define WIN_HEIGHT 1000

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				l_size;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
}					t_mlx;

typedef struct		s_variables
{
	double			h;
	double			w;
	int				i;
	int				j;
	int				x1;
	int				x0;
	int				y1;
	int				y0;
	int				z0;
	int				z1;
	int				xrot;
	int				yrot;
	int				zrot;
	double			angle;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				err2;
	int				p_depth;
}					t_variables;

typedef struct		s_s
{
	char			**tab_line;
	int				**tab_nb;
	int				*init_tab_nb;
	int				size_width;
	int				size_height;
	int				size_depth;
	int				maxi;
	int				mini;
	double			p_dist;
	double			p_depth;
	int				move_x;
	int				move_y;
	t_mlx			mlx;
	t_variables		box;
}					t_s;

int					light_colors(int nb_color, int color);
int					dark_colors(int nb_color, int color);
int					colors(int mini, int maxi, int nb);
void				s_distance(t_s *s);
void				rotate(t_s *s);
void				bresenham_datas(t_s *s, int orientation);
void				bresenham(int *data, t_s *s, int nb);
void				fill_segments_horizontal(int *data, t_s *s);
void				fill_segments_vertical(int *data, t_s *s);
void				key_move(int keycode, t_s *s);
void				key_height(int keycode, t_s *s);
void				key_rotation(int keycode, t_s *s);
void				key_zoom(int keycode, t_s *s);
void				display_commands(t_s *s);
void				display_last_command_1(int keycode, t_s *s);
void				display_last_command_2(int keycode, t_s *s);
int					key_functions(int keycode, t_s *s);
void				ft_display_window(t_s *s);
t_s					*tab_nb_creation(t_s *s, char *line, int j);
void				count_range_depth(t_s *s, int j);
int					parcing(t_s *s, char *fichier_source, int fd, int j);
void				display_errors(int error);

#endif
