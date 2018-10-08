/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 17:27:33 by zmiantud          #+#    #+#             */
/*   Updated: 2018/09/25 17:38:29 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		err(t_data *d)
{
	ft_putendl("\033[31mError: No path leading to the end node\033[0m");
	ft_free(d, 1);
}

static int		adj_unvis_node(t_data *d, t_node *n, int nod_i, int num_nodes)
{
	int	i;

	i = -1;
	while (++i < num_nodes)
	{
		if (d->adj_matrix[nod_i][i] == 1 && n[i].visited == 0)
			return (i);
	}
	return (-1);
}

static void		depth_vis_graph(t_data *d, t_node *n, int num_nodes)
{
	int	top_stack;
	int	unvis_nod_i;

	d->stack = (int *)malloc(sizeof(int) * num_nodes);
	n[ft_start_index(d)].visited = 1;
	ft_push(d, ft_start_index(d));
	while (stack_is_empty(d) == 0 && (d->k == 0))
	{
		top_stack = ft_peek(d);
		unvis_nod_i = adj_unvis_node(d, n, top_stack, num_nodes);
		if (unvis_nod_i == -1)
			ft_pop(d);
		else
		{
			n[unvis_nod_i].visited = 1;
			ft_push(d, unvis_nod_i);
			if (ft_strequ(n[unvis_nod_i].s, d->end_node))
				d->k = 1;
		}
	}
	if (d->k == 0)
		err(d);
	else
		send_ants(d, n);
}

static void		popul_lst(t_data *d, t_node *nod, int n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		nod[i].s = ft_strdup(d->node_lst[i]);
		nod[i].visited = 0;
	}
}

void			find_path(t_data *d)
{
	int		num_nodes;
	t_node	*node_vis;

	num_nodes = num_of_str(d->node_lst);
	node_vis = (t_node *)malloc(sizeof(t_node) * num_nodes);
	d->vis_nod = node_vis;
	popul_lst(d, d->vis_nod, num_nodes);
	depth_vis_graph(d, d->vis_nod, num_nodes);
}
