/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:25:09 by zmiantud          #+#    #+#             */
/*   Updated: 2018/06/04 09:10:24 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ch;

	i = 0;
	ch = NULL;
	while (s[i])
	{
		if (s[i] == c)
			ch = (char*)&s[i];
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		return ((char*)&s[i]);
	return (ch);
}
