/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 10:52:41 by zmiantud          #+#    #+#             */
/*   Updated: 2018/09/21 16:45:30 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index;
	int		index2;
	char	*hold;

	hold = NULL;
	if (!s1 || !s2)
		return (hold);
	index = ft_strlen(s1);
	index2 = ft_strlen(s2);
	if ((hold = (char *)malloc(sizeof(char) * 1 + (index + index2))))
	{
		hold = ft_strcpy(hold, s1);
		hold = ft_strcat(hold, s2);
	}
	return (hold);
}
