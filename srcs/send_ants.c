/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:33:05 by zmiantud          #+#    #+#             */
/*   Updated: 2018/09/25 18:40:28 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		ft_putpath(t_node *n, t_data *d)
{
	int	i;

	i = -1;
	ft_putendl("\033[32m*********printing the path*********\033[0m");
	while (++i <= d->s_top)
	{
		ft_putstr("\033[33m");
		put_node(n, d->stack[i]);
		ft_putstr("\033[0m");
		if ((i + 1) <= d->s_top)
			ft_putstr("\033[31m->\033[0m");
	}
	ft_putchar('\n');
	ft_putchar('\n');
}

void			send_ants(t_data *d, t_node *n)
{
	int	i;
	int	j;

	i = 0;
	ft_putpath(n, d);
	while (++i <= d->no_ants)
	{
		j = -1;
		while (++j <= d->s_top)
		{
			ft_putchar('L');
			ft_putnbr(i);
			ft_putchar('-');
			put_node(n, d->stack[j]);
			ft_putstr("  ");
		}
		ft_putchar('\n');
	}
}
