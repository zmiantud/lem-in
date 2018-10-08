/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:43:39 by zmiantud          #+#    #+#             */
/*   Updated: 2018/09/21 10:52:00 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	i = -1;
	s = NULL;
	if ((s = (char*)malloc(sizeof(char) * (size + 1))))
	{
		while (++i <= size)
			s[i] = '\0';
	}
	return (s);
}
