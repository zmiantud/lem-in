/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 16:14:29 by zmiantud          #+#    #+#             */
/*   Updated: 2018/06/08 10:51:43 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*map;

	i = -1;
	if (s && f)
	{
		map = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (map)
		{
			while (s[++i])
				map[i] = f(s[i]);
			map[i] = '\0';
			return (map);
		}
	}
	return (NULL);
}
