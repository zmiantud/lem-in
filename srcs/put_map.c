/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 13:23:36 by zmiantud          #+#    #+#             */
/*   Updated: 2018/09/25 18:40:09 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	put_num_ants(t_data *d)
{
	ft_putendl("\033[32m*********printing the number of ants*********\033[0m");
	ft_putstr("\033[33mNumber of ants: \033[0m");
	ft_putnbr(d->no_ants);
	ft_putchar('\n');
	ft_putchar('\n');
}

void	put_start_end(t_data *data)
{
	ft_putendl("\033[32m*********Printing start and end nodes*********\033[0m");
	ft_putstr("\033[33mStart node: \033[0m");
	ft_putstr(data->start_node);
	ft_putstr("   ");
	ft_putstr("\033[33mEnd node: \033[0m");
	ft_putendl(data->end_node);
	ft_putchar('\n');
}

void	put_map(char **m)
{
	int	i;

	i = -1;
	ft_putendl("\033[32m*********Printing map*********\033[0m");
	while (m[++i])
	{
		if (ft_strequ(m[i], "##start") || \
				ft_strequ(m[i], "##end") || \
				is_int(m[i]))
		{
			ft_putstr("\033[33m");
			ft_putendl(m[i]);
			ft_putstr("\033[0m");
		}
		else
			ft_putendl(m[i]);
	}
}

void	put_node(t_node *n, int node_index)
{
	ft_putstr(n[node_index].s);
}
