/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:11:33 by zmiantud          #+#    #+#             */
/*   Updated: 2018/09/27 11:38:30 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_get_room(t_data *d, char *line, int *i)
{
	char	**s;

	s = ft_strsplit(line, ' ');
	update_map2(d, line, i);
	d->node_lst[*d->nod_i] = ft_strdup(s[0]);
	*d->nod_i = *d->nod_i + 1;
	d->node_lst[*d->nod_i] = NULL;
	d->room = d->room + 1;
	arraydel(&s);
}

void	ft_get_room2(t_data *d, char *line, int *i)
{
	char	**s;

	s = ft_strsplit(line, ' ');
	d->node_lst[*d->nod_i] = ft_strdup(s[0]);
	*d->nod_i = *d->nod_i + 1;
	d->node_lst[*d->nod_i] = NULL;
	d->room = d->room + 1;
	arraydel(&s);
}
