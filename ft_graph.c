/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:56:29 by anain             #+#    #+#             */
/*   Updated: 2017/06/21 17:03:34 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_global_pic(t_coord tab, t_env a)
{
	t_point p;

	p.x = -1;
	p.y = -1;
	p.z = 1;
	while (++p.x < tab.c - 1)
	{
		while (++p.y < tab.l)
			ft_draw(tab, a, p, 10);
		p.y = -1;
	}
	p.x = -1;
	while (++p.y < tab.l - 1)
	{
		while (++p.x < tab.c)
			ft_draw(tab, a, p, 1);
		p.x = -1;
	}
	mlx_put_image_to_window(a.mlx, a.win, a.p, 0, 0);
	mlx_loop(a.mlx);
	return (1);
}

void	ft_views(int keycode, t_env *a)
{
	mlx_destroy_image(a->mlx, a->image);
	if (keycode == 2)
		*a = ft_a_init(*a, a->tab, a->screen, 3);
	else if (keycode == 84)
		*a = ft_a_init(*a, a->tab, a->screen, 2);
	else
		*a = ft_a_init(*a, a->tab, a->screen, 1);
	ft_global_pic(a->tab, *a);
}

void	ft_move(int keycode, t_env *a)
{
	int bpp;
	int s_l;
	int endian;

	mlx_destroy_image(a->mlx, a->image);
	a->p = mlx_new_image(a->mlx, a->screen.x, a->screen.y);
	a->image = mlx_get_data_addr(a->p, &(bpp), &(s_l), &(endian));
	if (keycode == 125)
		a->h++;
	else if (keycode == 123)
		a->s--;
	else if (keycode == 124)
		a->s++;
	else if (keycode == 126)
		a->h--;
	ft_global_pic(a->tab, *a);
}

int		key_hook(int keycode, t_env *a)
{
	if (keycode == 53)
	{
		mlx_destroy_image(a->mlx, a->image);
		mlx_destroy_window(a->mlx, a->win);
		ft_free_tab(&a->tab);
		exit(0);
	}
	if (keycode == 83 || keycode == 84 || keycode == 32 || keycode == 2)
		ft_views(keycode, a);
	if (keycode == 125 || keycode == 126 || keycode == 123 || keycode == 124)
		ft_move(keycode, a);
	return (0);
}

int		ft_graph(t_coord tab)
{
	t_point		screen;
	t_env		a;

	screen = ft_screen(tab);
	a.mlx = mlx_init();
	a.win = mlx_new_window(a.mlx, screen.x, screen.y, "Fdf");
	a = ft_a_init(a, tab, screen, 1);
	a.s = 0;
	a.h = 0;
	mlx_key_hook(a.win, key_hook, &a);
	ft_global_pic(tab, a);
	return (0);
}
