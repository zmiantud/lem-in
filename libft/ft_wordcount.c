/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 10:38:07 by zmiantud          #+#    #+#             */
/*   Updated: 2018/06/04 16:34:20 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordcount(const char *s, char c)
{
	int		i;
	int		nbr_w;

	i = 0;
	nbr_w = 0;
	if (s)
	{
		while (s[i])
		{
			while (s[i] == c)
				i++;
			if (s[i] && s[i] != c)
				nbr_w++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (nbr_w);
}
