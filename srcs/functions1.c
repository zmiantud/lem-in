/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:17:52 by zmiantud          #+#    #+#             */
/*   Updated: 2018/09/25 18:25:35 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				ft_start_index(t_data *d)
{
	int i;

	i = -1;
	while (d->node_lst[++i])
	{
		if (ft_strequ(d->node_lst[i], d->start_node))
			return (i);
	}
	return (-1);
}

static int		strs_found(char *s1, char *s2, char **str, int n)
{
	char	**s3;

	s3 = ft_strsplit(str[n], '-');
	if ((ft_strequ(s3[0], s1) && ft_strequ(s3[1], s2)) \
			|| (ft_strequ(s3[0], s2) && ft_strequ(s3[1], s1)))
	{
		arraydel(&s3);
		return (1);
	}
	arraydel(&s3);
	return (0);
}

int				is_edge(t_data *d, int i, int j)
{
	int		n;
	char	*s1;
	char	*s2;
	char	*s3;

	n = -1;
	s1 = d->node_lst[i];
	s2 = d->node_lst[j];
	while (++n < num_of_str(d->links))
	{
		if (strs_found(s1, s2, d->links, n))
			return (1);
	}
	return (0);
}

void			update_map1(t_data *d, char *line, int *i)
{
	d->map[*i] = ft_strnew(ft_strlen(line));
	d->map[*i] = ft_strcpy(d->map[*i], line);
	*i = *i + 1;
	d->map[*i] = NULL;
	d->no_ants = ft_atoi(line);
}

void			update_map2(t_data *d, char *line, int *i)
{
	d->map[*i] = ft_strnew(ft_strlen(line));
	d->map[*i] = ft_strcpy(d->map[*i], line);
	*i = *i + 1;
	d->map[*i] = NULL;
}
