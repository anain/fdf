/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:32:22 by anain             #+#    #+#             */
/*   Updated: 2017/06/22 16:35:07 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		ft_iso(t_env a, int x, int y, int z)
{
	t_point p;
	int		i;
	int		o;

	i = 0;
	o = a.tab.max;
	if (a.screen.y > (a.tab.l + a.tab.isomax) * a.tile.height)
		o = a.tab.isomax;
	if (z == 1)
		p.z = a.tab.ftab[y][x];
	else
		p.z = z;
	if (a.pos == 1)
		i = p.z;
	if (a.pos == 1 || a.pos == 3)
	{
		p.x = ((x - y + a.tab.l + a.s)) * a.tile.width + MARGIN;
		p.y = (x + y - i * 2 - o + a.h) * a.tile.height + MARGIN;
	}
	if (a.pos == 2)
	{
		p.x = (x + a.tab.l + a.s) * a.tile.width + MARGIN;
		p.y = (y + a.h) * a.tile.height * 2 + MARGIN;
	}
	return (p);
}

void		ft_light_slope(t_env a, t_point i, t_param param)
{
	t_point		p;
	int			err;
	int			j;
	int			c;

	p.x = i.x;
	p.y = i.y;
	err = param.dy / 2;
	j = 0;
	c = ft_color(param.tab);
	while (j++ < param.dx)
	{
		p.x = p.x + param.incx;
		err = err + param.dy;
		if (err > param.dx)
		{
			err = err - param.dx;
			p.y = p.y + param.incy;
		}
		if (p.x + a.s < a.screen.x && p.y + a.h < a.screen.y)
			ft_pic(a, p.x, p.y, c);
	}
}

void		ft_hard_slope(t_env a, t_point i, t_param param)
{
	t_point		p;
	int			err;
	int			j;
	int			c;

	p.x = i.x;
	p.y = i.y;
	err = param.dx / 2;
	j = 0;
	c = ft_color(param.tab);
	while (j++ < param.dy)
	{
		p.y = p.y + param.incy;
		err = err + param.dx;
		if (err > param.dy)
		{
			err = err - param.dy;
			p.x = p.x + param.incx;
		}
		if (p.x + a.s < a.screen.x && p.y + a.h < a.screen.y)
			ft_pic(a, p.x, p.y, c);
	}
}

void		ft_draw(t_coord tab, t_env a, t_point p, int k)
{
	t_point f;
	t_point i;
	t_param param;

	f = ft_iso(a, p.x, p.y, p.z);
	i = ft_iso(a, p.x + k / 10, p.y + k % 10, p.z);
	param = ft_param(f, i, tab);
	if (param.dx > param.dy)
		ft_light_slope(a, i, param);
	else
		ft_hard_slope(a, i, param);
}
