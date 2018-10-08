/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 08:41:39 by zmiantud          #+#    #+#             */
/*   Updated: 2018/05/23 09:20:14 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*t_s1;
	char	*t_s2;

	i = 0;
	t_s1 = (char*)s1;
	t_s2 = (char*)s2;
	if (n)
	{
		while (i < n)
		{
			if (t_s1[i] != t_s2[i])
				return ((unsigned char)t_s1[i] - (unsigned char)t_s2[i]);
			i++;
		}
	}
	return (0);
}
