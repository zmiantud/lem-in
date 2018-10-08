/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 10:27:44 by zmiantud          #+#    #+#             */
/*   Updated: 2018/09/27 12:15:42 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		is_room(char *line, t_data *d)
{
	char	**s;
	int		i;

	i = 0;
	s = ft_strsplit(line, ' ');
	while (s[i])
		i++;
	if (i == 3)
		if (is_valid_room(s, d) == 1)
		{
			arraydel(&s);
			return (1);
		}
	arraydel(&s);
	return (0);
}

int		is_start(char *line)
{
	if (ft_strequ(line, "##start") == 1)
		return (1);
	return (0);
}

int		is_end(char *line)
{
	if (ft_strequ(line, "##end") == 1)
		return (1);
	return (0);
}

int		is_comment(char *line)
{
	if (line[0] == '#' && !is_start_end(line) && \
			line[1] != '\0' && line[1] != '#' \
			&& !ft_isspace(line[1]))
		return (1);
	return (0);
}

int		is_link(char *line)
{
	char	**s;
	int		i;

	s = ft_strsplit(line, '-');
	i = 0;
	while (s[i])
		i++;
	if (i == 2)
	{
		arraydel(&s);
		return (1);
	}
	arraydel(&s);
	return (0);
}
