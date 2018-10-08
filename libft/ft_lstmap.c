/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:27:58 by zmiantud          #+#    #+#             */
/*   Updated: 2018/06/01 10:19:47 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*t;
	t_list	*res;

	res = NULL;
	if (lst)
	{
		res = f(lst);
		t = res;
		while (lst->next)
		{
			if (!(t->next = f(lst->next)))
				return (NULL);
			t = t->next;
			lst = lst->next;
		}
	}
	return (res);
}
