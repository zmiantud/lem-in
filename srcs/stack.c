/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 17:38:24 by zmiantud          #+#    #+#             */
/*   Updated: 2018/09/24 17:33:27 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_push(t_data *d, int nod_i)
{
	d->stack[++d->s_top] = nod_i;
}

int		ft_pop(t_data *d)
{
	return (d->stack[d->s_top--]);
}

int		ft_peek(t_data *d)
{
	return (d->stack[d->s_top]);
}

int		stack_is_empty(t_data *d)
{
	if (d->s_top == -1)
		return (1);
	return (0);
}
