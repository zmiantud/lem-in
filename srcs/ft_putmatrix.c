/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmatrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 16:34:26 by zmiantud          #+#    #+#             */
/*   Updated: 2018/09/25 18:20:50 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		put_color(int i)
{
	ft_putstr("\033[33m");
	ft_putnbr(i);
	ft_putstr("\033[0m");
}

static void		ft_part_2(t_data *d, int n)
{
	int j;
	int i;

	i = -1;
	while (++i < n)
	{
		ft_putnbr(i);
		ft_putstr("  ");
		j = -1;
		while (++j < n)
		{
			if (d->adj_matrix[i][j] == 0)
				ft_putnbr(d->adj_matrix[i][j]);
			else if (d->adj_matrix[i][j] == 1)
				put_color(d->adj_matrix[i][j]);
			ft_putchar(' ');
		}
		ft_putstr("       ");
		ft_putnbr(i);
		ft_putstr("\033[33m->\033[0m");
		ft_putstr(d->node_lst[i]);
		ft_putchar('\n');
	}
}

void			ft_putmatrix(t_data *d)
{
	int i;
	int j;
	int n;

	i = 0;
	ft_putendl("\033[32m********printing the adjacency matrix********\033[0m");
	ft_putchar('\n');
	n = num_of_str(d->node_lst);
	ft_putstr("   ");
	while (i < n)
	{
		ft_putnbr(i);
		ft_putchar(' ');
		i++;
	}
	ft_putstr("   ");
	ft_putstr("index");
	ft_putstr("\033[33m->\033[0m");
	ft_putstr("room name");
	ft_putchar('\n');
	ft_part_2(d, n);
	ft_putchar('\n');
}
