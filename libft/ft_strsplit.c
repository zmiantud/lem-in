/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 08:51:32 by zmiantud          #+#    #+#             */
/*   Updated: 2018/09/21 11:02:08 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**m;
	int		m_w;
	int		m_ch;
	int		s_ch;

	m_w = -1;
	s_ch = 0;
	if (s && (m = (char**)malloc(sizeof(char*) * (ft_wordcount(s, c) + 1))))
	{
		while (++m_w < ft_wordcount(s, c))
		{
			m_ch = 0;
			if ((m[m_w] = ft_strnew(ft_wordlen(&s[s_ch], c) + 1)))
			{
				while (s[s_ch] && s[s_ch] == c)
					s_ch++;
				while (s[s_ch] && s[s_ch] != c)
					m[m_w][m_ch++] = s[s_ch++];
				m[m_w][m_ch] = '\0';
			}
		}
		m[m_w] = 0;
		return (m);
	}
	return (NULL);
}
