/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 10:57:04 by zmiantud          #+#    #+#             */
/*   Updated: 2018/09/27 12:12:15 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		num_of_str(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		is_valid_link(t_data *d, char *line)
{
	int		i;
	char	**s;

	i = 0;
	s = ft_strsplit(line, '-');
	if (search_in_arr(d->node_lst, s[0]) && \
			search_in_arr(d->node_lst, s[1]))
	{
		arraydel(&s);
		return (1);
	}
	arraydel(&s);
	return (0);
}

int		is_valid_room(char **s, t_data *d)
{
	int	i;

	i = -1;
	while (s[0][++i])
	{
		if (s[0][i] == '-')
		{
			ft_putstr("\033[31mError: Non compliant room name: \033[33m");
			ft_putstr(s[0]);
			ft_putstr("\033[0m");
			ft_free(d, 0);
		}
	}
	i = num_of_str(d->node_lst);
	while (--i >= 0)
		if (ft_strequ(s[0], d->node_lst[i]))
		{
			ft_putstr("\033[31mError: Duplicate room found: \033[0m");
			ft_putendl(s[0]);
			ft_free(d, 0);
		}
	if (s[0][0] != 'L' && is_int(s[1]) && is_int(s[2]))
		return (1);
	return (0);
}

int		is_start_end(char *line)
{
	if (ft_strequ(line, "##start") == 1 || ft_strequ(line, "##end") == 1)
		return (1);
	return (0);
}

int		is_int(char *s)
{
	int		num;
	char	*temp;
	char	*trim;

	num = ft_atoi(s);
	temp = ft_itoa(num);
	trim = ft_strtrim2(s);
	if (ft_strcmp(temp, trim) == 0)
	{
		free(trim);
		free(temp);
		return (1);
	}
	free(trim);
	free(temp);
	return (0);
}
