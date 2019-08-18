/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_layout.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:48:15 by anain             #+#    #+#             */
/*   Updated: 2017/06/22 17:02:36 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_tile		ft_tile(t_env a)
{
	t_tile	tile;
	int		max;

	max = ft_max(a.tab.c, a.tab.l);
	if (a.screen.x == 2560 || a.screen.y == 1440)
	{
		tile.width = a.screen.x / (max * 2);
		if (tile.width % 2 != 0)
			tile.width++;
		tile.height = tile.width / 2;
	}
	else
	{
		tile.width = TILEWIDTH;
		tile.height = TILEHEIGHT;
	}
	return (tile);
}

int			ft_color(int param)
{
	if (param == 1)
		return (HIGH);
	if (param == 2)
		return (LOW);
	else
		return (ELSE);
}
