/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:09:57 by anain             #+#    #+#             */
/*   Updated: 2017/06/23 16:34:06 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coord	ft_check(char *argv, t_coord tab)
{
	char	*line;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		tab.c = -1;
		close(fd);
		return (tab);
	}
	while (get_next_line(fd, &line) == 1 && line != NULL
		&& ft_strcmp(line, "\n") != 0)
	{
		tab.l++;
		ft_strdel(&line);
	}
	close(fd);
	fd = open(argv, O_RDONLY);
	tab = ft_take_coord(fd, tab);
	close(fd);
	return (tab);
}

int				main(int argc, char **argv)
{
	t_coord	tab;

	tab.l = 0;
	tab.c = 0;
	tab.str = NULL;
	tab.ftab = NULL;
	tab.max = 0;
	tab = ft_check(argv[1], tab);
	if (argc != 2)
	{
		write(2, "usage: ./fdf [map]\n", 19);
		exit(EXIT_FAILURE);
	}
	if (tab.c == -1 || tab.l == 0)
	{
		write(2, "error : invalid file", 20);
		return (-1);
	}
	tab = ft_tab_coord(tab);
	if (tab.c == -1)
		return (-1);
	ft_graph(tab);
	return (0);
}
