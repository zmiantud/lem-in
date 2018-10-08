/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:12:52 by zmiantud          #+#    #+#             */
/*   Updated: 2018/05/31 18:38:30 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*l;

	if (!(l = (t_list*)malloc(sizeof(*l))))
		return (NULL);
	if (!content)
	{
		l->content = NULL;
		l->content_size = 0;
	}
	else
	{
		if (!(l->content = (void*)malloc(content_size)))
			return (NULL);
		ft_memmove(l->content, content, content_size);
		l->content_size = content_size;
	}
	l->next = NULL;
	return (l);
}
