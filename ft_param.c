/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 17:00:02 by anain             #+#    #+#             */
/*   Updated: 2017/06/22 17:01:45 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_env		ft_a_init(t_env a, t_coord tab, t_point screen, int i)
{
	int bpp;
	int s_l;
	int endian;

	a.screen = screen;
	a.tab = tab;
	a.p = mlx_new_image(a.mlx, screen.x, screen.y);
	a.image = mlx_get_data_addr(a.p, &(bpp), &(s_l), &(endian));
	a.pos = i;
	a.tile = ft_tile(a);
	return (a);
}

t_point		ft_screen(t_coord tab)
{
	t_point screen;

	screen.x = TILEWIDTH * (tab.c * 2 + tab.c / 2) + 2 * MARGIN;
	if (screen.x > 2560)
		screen.x = 2560;
	screen.y = TILEWIDTH * tab.c + (tab.max - tab.min + tab.l) * TILEHEIGHT
	* 2 + MARGIN * 2;
	if (screen.y > 1440)
		screen.y = 1440;
	return (screen);
}

void		ft_free_tab(t_coord *tab)
{
	int j;

	j = -1;
	while (++j < tab->l)
		free(tab->ftab[j]);
	free(tab->ftab);
}

void		ft_free_str(t_coord tab)
{
	int j;
	int i;

	i = 0;
	j = 0;
	while (j < tab.l)
	{
		while (i < tab.c)
		{
			ft_strclr(tab.str[j][i]);
			free(tab.str[j][i]);
			i++;
		}
		free(tab.str[j]);
		j++;
		i = 0;
	}
	free(tab.str);
}

t_param		ft_param(t_point f, t_point i, t_coord tab)
{
	t_param param;

	param.dx = abs(f.x - i.x);
	param.dy = abs(f.y - i.y);
	param.incx = (i.x < f.x) ? 1 : -1;
	param.incy = (i.y < f.y) ? 1 : -1;
	if (f.z == tab.max && i.z == tab.max)
		param.tab = 1;
	else if (f.z == tab.min)
		param.tab = 2;
	else
		param.tab = 0;
	return (param);
}
