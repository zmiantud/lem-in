/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 17:12:58 by zmiantud          #+#    #+#             */
/*   Updated: 2018/06/01 18:13:58 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		len;
	size_t		i;

	len = ft_strlen(s1);
	i = 0;
	while ((i < n) && s2[i])
		s1[len++] = s2[i++];
	s1[len] = '\0';
	return (s1);
}
