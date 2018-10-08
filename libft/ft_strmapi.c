/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 16:45:08 by zmiantud          #+#    #+#             */
/*   Updated: 2018/06/08 10:52:03 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*cp_s;
	char	*mapi;

	i = -1;
	if (s && f)
	{
		cp_s = (char*)s;
		mapi = (char*)malloc(sizeof(char) * (ft_strlen(cp_s) + 1));
		if (mapi)
		{
			while (cp_s[++i])
				mapi[i] = f(i, cp_s[i]);
			mapi[i] = '\0';
			return (mapi);
		}
	}
	return (NULL);
}
