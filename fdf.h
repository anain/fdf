/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 21:21:34 by anain             #+#    #+#             */
/*   Updated: 2017/06/22 17:01:39 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define TILEWIDTH 30
# define TILEHEIGHT 15
# define MARGIN 10

# define LOW 0x00FFFFFF
# define HIGH 0x00FF0000
# define ELSE 0x00FF7F7F

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_coord
{
	int		l;
	int		c;
	char	***str;
	int		**ftab;
	int		max;
	int		min;
	int		isomax;
}				t_coord;

typedef struct	s_tile
{
	int	height;
	int width;
}				t_tile;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_coord		tab;
	t_point		screen;
	int			pos;
	int			s;
	int			h;
	void		*p;
	char		*image;
	t_tile		tile;
}				t_env;

typedef struct	s_param
{
	int	dx;
	int dy;
	int incx;
	int incy;
	int tab;
}				t_param;

int				ft_color(int param);
t_env			ft_a_init(t_env a, t_coord tab, t_point screen, int i);
t_param			ft_param(t_point f, t_point i, t_coord tab);
t_point			ft_screen(t_coord tab);
void			ft_free_str(t_coord tab);
void			ft_free_tab(t_coord *tab);
void			ft_draw(t_coord tab, t_env a, t_point p, int k);
int				ft_iscolor(char *str);
t_coord			ft_take_coord(int fd, t_coord tab);
int				ft_col(char **str);
t_tile			ft_tile(t_env a);
int				ft_graph(t_coord tab);
t_coord			ft_tab_coord(t_coord tab);
t_point			ft_screen(t_coord tab);
t_env			ft_a_init(t_env a, t_coord tab, t_point screen, int i);
int				ft_pic(t_env a, int x, int y, int color);
void			ft_views(int keycode, t_env *a);
int				key_hook(int keycode, t_env *a);
t_point			ft_rot(t_point p0, int **mat);

#endif
