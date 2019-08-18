/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 21:17:18 by anain             #+#    #+#             */
/*   Updated: 2017/06/23 16:22:15 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

int			ft_iscolor(char *str)
{
	int i;

	i = 0;
	while (ft_isdigit(str[i]) == 1)
		i++;
	if (str[i] != ',' || str[i + 1] != '0' || (str[i + 2] != 'X'
	&& str[i + 2] != 'x'))
		return (-1);
	i = i + 3;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0 && !((str[i] >= 'A' && str[i] <= 'F')
		|| (str[i] >= 'a' && str[i] <= 'f')))
			return (-1);
		i++;
	}
	return (1);
}

static int	ft_check(char **str)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (str[j])
	{
		while (str[j][k])
		{
			if (ft_isdigit(str[j][k]) == 0 && !(str[j][k] == '-' & k == 0))
			{
				if (ft_iscolor(str[j]) == -1)
					return (-1);
			}
			k++;
		}
		j++;
		k = 0;
	}
	return (j);
}

t_coord		ft_take_coord(int fd, t_coord tab)
{
	int		i;
	char	*line;
	int		j;

	i = 0;
	j = 0;
	tab.str = (char ***)malloc(sizeof(char **) * (tab.l));
	while (get_next_line(fd, &line) == 1)
	{
		tab.str[i] = ft_strsplit(line, ' ');
		ft_strdel(&line);
		if (tab.c == 0)
			tab.c = ft_check(tab.str[i]);
		else if (ft_check(tab.str[i]) != tab.c)
			tab.c = -1;
		if (tab.c == -1)
			return (tab);
		i++;
	}
	return (tab);
}

t_coord		ft_tab_case(t_coord tab, int x, int y)
{
	tab.ftab[y][x] = ft_atoi(tab.str[y][x]);
	if (tab.ftab[y][x] > tab.max)
		tab.max = tab.ftab[y][x];
	if (x + y - tab.ftab[y][x] * 2 < tab.isomax)
		tab.isomax = x + y - tab.ftab[y][x] * 2;
	if (tab.min == 0 || tab.min > tab.ftab[y][x])
		tab.min = tab.ftab[y][x];
	return (tab);
}

t_coord		ft_tab_coord(t_coord tab)
{
	int x;
	int y;

	x = 0;
	y = 0;
	tab.ftab = (int **)malloc(sizeof(int *) * (tab.l + 1));
	tab.isomax = 0;
	tab.max = 0;
	tab.min = 0;
	while (y < tab.l)
	{
		tab.ftab[y] = (int *)malloc(sizeof(int) * (tab.c + 1));
		while (x < tab.c)
		{
			tab = ft_tab_case(tab, x, y);
			x++;
		}
		y++;
		x = 0;
	}
	ft_free_str(tab);
	return (tab);
}
