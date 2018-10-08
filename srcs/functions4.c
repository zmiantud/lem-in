/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:30:07 by zmiantud          #+#    #+#             */
/*   Updated: 2018/09/27 12:04:39 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	make_matrix(t_data *d)
{
	int		**ar;
	int		i;
	int		j;
	int		num_nodes;

	num_nodes = num_of_str(d->node_lst);
	i = -1;
	d->adj_matrix = (int **)malloc(sizeof(int *) * num_nodes);
	while (++i < num_nodes)
	{
		j = -1;
		d->adj_matrix[i] = (int *)malloc(sizeof(int) * num_nodes);
		while (++j < num_nodes)
		{
			if (is_edge(d, i, j))
				d->adj_matrix[i][j] = 1;
			else
				d->adj_matrix[i][j] = 0;
		}
	}
}

char	*reverse_link(char *line)
{
	char	**s;
	char	*ret;
	char	*ret_temp;
	char	*temp;

	s = ft_strsplit(line, '-');
	temp = ft_strjoin(s[1], "-");
	ret_temp = ft_strdup(temp);
	ret = ft_strjoin(ret_temp, s[0]);
	free(temp);
	arraydel(&s);
	free(ret_temp);
	return (ret);
}

int		search_in_arr(char **m_s, char *s)
{
	int	i;

	i = 0;
	while (m_s[i])
	{
		if (ft_strequ(s, m_s[i]))
			return (1);
		i++;
	}
	return (0);
}

void	check_line(t_data *d, char *line, int *i)
{
	if (is_room(line, d))
		ft_get_room(d, line, i);
	else if (is_start(line))
		ft_get_start(d, line, i);
	else if (is_end(line))
		ft_get_end(d, line, i);
	else if (is_link(line))
		ft_get_link(d, line, i);
	else if (is_comment(line))
		update_map2(d, line, i);
	else
	{
		ft_putstr("\033[31mError: Invalid entry found: \033[33m");
		ft_putendl(line);
		ft_putstr("\033[0m");
		free(line);
		ft_free(d, 0);
	}
}
