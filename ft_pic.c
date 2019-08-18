/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 21:04:56 by anain             #+#    #+#             */
/*   Updated: 2017/06/21 16:54:30 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_pic(t_env a, int x, int y, int color)
{
	int i;

	i = y * 4 * a.screen.x + x * 4;
	if (i >= 0 && i < a.screen.x * 4 * a.screen.y)
	{
		a.image[i] = color;
		a.image[++i] = color >> 8;
		a.image[++i] = color >> 16;
	}
	return (1);
}
