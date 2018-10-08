/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:30:12 by zmiantud          #+#    #+#             */
/*   Updated: 2018/05/23 08:34:17 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*t_s;

	i = 0;
	t_s = (char*)s;
	while (i < n)
	{
		if (t_s[i] == (char)c)
			return ((void*)&t_s[i]);
		i++;
	}
	return (NULL);
}
