/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:42:59 by zmiantud          #+#    #+#             */
/*   Updated: 2018/09/24 17:21:27 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		ft_free_a(t_data *d)
{
	free(d->nod_i);
	free(d->l_i);
	arraydel(&d->map);
	arraydel(&d->node_lst);
	arraydel(&d->links);
	if (d->start != 0)
	{
		free(d->start_node);
		d->start_node = NULL;
	}
	if (d->end != 0)
	{
		free(d->end_node);
		d->end_node = NULL;
	}
}

static void		ft_free_b(t_data *d)
{
	int_arrdel(d);
	free_node_strs(d);
	ft_free_a(d);
	free(d->stack);
	d->stack = NULL;
	exit(1);
}

static void		ft_free2(t_data *d)
{
	ft_free_b(d);
	exit(1);
}

static void		ft_free1(t_data *d)
{
	ft_free_a(d);
	exit(1);
}

void			ft_free(t_data *d, int n)
{
	if (n == 0)
		ft_free1(d);
	else if (n == 1)
		ft_free2(d);
}
