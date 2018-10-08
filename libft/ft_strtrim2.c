/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:40:10 by zmiantud          #+#    #+#             */
/*   Updated: 2018/09/21 10:08:29 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_zero(char c, int *k)
{
	if (c == '0')
	{
		*k = *k + 1;
		return (1);
	}
	return (0);
}

static char	*ft_make_string(char *str)
{
	str = (char*)malloc(sizeof(char) * 2);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char		*ft_strtrim2(char const *s)
{
	size_t	len;
	char	*s_trim;
	int		k;

	k = 0;
	s_trim = NULL;
	if (s == NULL)
		return (NULL);
	while (*s != '\0' && ft_isspace(*s))
		s++;
	while (*s != '\0' && ft_is_zero(*s, &k))
	{
		if (k > 0 && (*(s + 1) == '\0'))
			return (ft_make_string(s_trim));
		s++;
	}
	len = ft_strlen(s);
	while (len && ft_isspace(s[len - 1]))
		len--;
	s_trim = (char*)malloc(sizeof(char) * (len + 1));
	if (!s_trim)
		return (NULL);
	ft_strncpy(s_trim, s, len);
	s_trim[len] = '\0';
	return (s_trim);
}
