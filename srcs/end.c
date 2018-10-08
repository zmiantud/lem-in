/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:19:02 by zmiantud          #+#    #+#             */
/*   Updated: 2018/09/27 11:08:45 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		save_end(t_data *d, char *line, int *i)
{
	char	**s;

	s = ft_strsplit(line, ' ');
	d->end_node = ft_strdup(s[0]);
	arraydel(&s);
	d->end = 1;
	ft_get_room2(d, line, i);
}

static void		end_saved_already(t_data *d, char *l, int *i)
{
	if (get_next_line(0, &l) > 0)
	{
		if (is_room(l, d))
		{
			ft_putstr("\033[31mError: Two end rooms found");
			ft_putendl(" in the ants' farm\033[0m");
			free(l);
			ft_free(d, 0);
		}
		else
			check_line(d, l, i);
	}
}

static void		no_end_error(t_data *d)
{
	ft_putstr("\033[31mError: ##end command not");
	ft_putendl(" followed by a room\033[0m");
	ft_free(d, 0);
}

static void		no_end_yet(t_data *d, int *i)
{
	char	*line;

	if (get_next_line(0, &line) != 1)
		no_end_error(d);
	update_map2(d, line, i);
	if (is_room(line, d))
		save_end(d, line, i);
	else if (!is_room(line, d) && !is_comment(line))
		ft_err2_line_free(line, d, 0);
	else if (!is_room(line, d) && is_comment(line))
	{
		free(line);
		while (get_next_line(0, &line) > 0 && is_comment(line))
			ft_update_free(d, line, i, 2);
		if (line && is_room(line, d))
		{
			update_map2(d, line, i);
			save_end(d, line, i);
		}
		else
			ft_err2_line_free(line, d, 1);
	}
	free(line);
}

void			ft_get_end(t_data *d, char *line, int *i)
{
	update_map2(d, line, i);
	if (d->end == 0)
		no_end_yet(d, i);
	else if (d->end == 1)
		end_saved_already(d, line, i);
}
