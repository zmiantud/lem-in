/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:57:17 by zmiantud          #+#    #+#             */
/*   Updated: 2018/06/04 11:22:57 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*s;
	char	*d;

	i = 0;
	d = (char*)dst;
	s = (char*)src;
	if (s < d)
		while ((int)--len >= 0)
			d[len] = (s[len]);
	else
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	return (dst);
}
