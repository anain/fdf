/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_and_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:57:32 by anain             #+#    #+#             */
/*   Updated: 2017/04/11 19:14:12 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_and_free(char *s1, char *s2, int c)
{
	char *str;

	if (!s1 || !s2)
		return (0);
	if (!(str = (char *)malloc(sizeof(char)
		* (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1))))
		return (0);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	if (c == 1)
		free(s1);
	if (c == 2)
		free(s2);
	if (c == 3)
	{
		free(s1);
		free(s2);
	}
	return (str);
}
