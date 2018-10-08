/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:36:24 by zmiantud          #+#    #+#             */
/*   Updated: 2018/05/25 17:49:22 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	nlen;

	i = -1;
	nlen = ft_strlen(needle);
	if (nlen == 0)
		return ((char*)haystack);
	while (haystack[++i] && (i + nlen <= len))
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (j == nlen - 1)
				return ((char*)haystack + i);
			j++;
		}
	}
	return (NULL);
}
