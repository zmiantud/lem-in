/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 16:58:17 by zmiantud          #+#    #+#             */
/*   Updated: 2018/06/11 15:04:57 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	int		i;
	size_t	cpdst_len;

	i = -1;
	dst_len = ft_strlen(dst);
	cpdst_len = dst_len;
	src_len = ft_strlen(src);
	if (dst_len > dstsize)
		return (src_len + dstsize);
	else if (dst_len < dstsize)
	{
		while (src[++i] && (cpdst_len < dstsize - 1))
		{
			dst[cpdst_len++] = src[i];
		}
		dst[cpdst_len] = '\0';
	}
	return (dst_len + src_len);
}
