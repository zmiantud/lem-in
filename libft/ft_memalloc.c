/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:22:21 by zmiantud          #+#    #+#             */
/*   Updated: 2018/06/04 17:11:35 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*v;

	if (!size)
		return (0);
	v = malloc(size);
	if (!v)
		return (0);
	ft_bzero(v, size);
	return (v);
}
