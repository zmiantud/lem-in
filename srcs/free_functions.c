/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 14:41:25 by zmiantud          #+#    #+#             */
/*   Updated: 2018/09/24 17:22:29 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	set_line_null(char **line)
{
	*line = NULL;
}

void	int_ptr(int ***tab)
{
	free(*tab);
	*tab = NULL;
}

void	arraydel(char ***arr)
{
	int	i;

	i = 0;
	while ((*arr)[i])
		i++;
	i--;
	while (i >= 0)
	{
		ft_strdel(&(*arr)[i]);
		i--;
	}
	free(*arr);
	*arr = NULL;
}

void	int_arrdel(t_data *d)
{
	int	i;

	i = num_of_str(d->node_lst);
	while (--i >= 0)
		free(d->adj_matrix[i]);
	int_ptr(&d->adj_matrix);
}

void	free_node_strs(t_data *d)
{
	int	i;

	i = num_of_str(d->node_lst);
	while (--i >= 0)
	{
		ft_strdel(&d->vis_nod[i].s);
		d->vis_nod[i].visited = 0;
	}
	free(d->vis_nod);
	d->vis_nod = NULL;
}
