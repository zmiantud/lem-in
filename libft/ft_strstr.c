/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 09:28:07 by zmiantud          #+#    #+#             */
/*   Updated: 2018/05/30 08:50:42 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	nlen;

	i = -1;
	nlen = ft_strlen(needle);
	if (nlen == 0)
		return ((char*)haystack);
	while (haystack[++i])
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
