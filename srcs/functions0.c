/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 17:09:46 by zmiantud          #+#    #+#             */
/*   Updated: 2018/09/25 12:33:35 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			ft_update_free(t_data *d, char *l, int *i, int n)
{
	if (n == 1)
	{
		update_map1(d, l, i);
		free(l);
	}
	else if (n == 2)
	{
		update_map2(d, l, i);
		free(l);
	}
}

void			ft_line_free(char *line, t_data *d)
{
	free(line);
	ft_free(d, 0);
}

static void		ft_free_func(char *l, t_data *d)
{
	ft_putendl("\033[31mError: Comment not followed by the start room\033[0m");
	free(l);
	ft_free(d, 0);
}

void			ft_err1_line_free(char *l, t_data *d, int n)
{
	if (n == 0)
	{
		ft_putstr("\033[31mError: first comment not");
		ft_putendl(" followed by number of ants\033[0m");
		ft_line_free(l, d);
	}
	else if (n == 1)
	{
		ft_putstr("\033[31mError: first line is neither");
		ft_putendl(" a valid number of ants nor a comment\033[0m");
		ft_line_free(l, d);
	}
	else if (n == 2)
	{
		ft_putendl("\033[31mError: Empty map, nothing to read\033[0m");
		ft_free(d, 0);
	}
	else if (n == 3)
	{
		ft_putstr("\033[31mError: ##start not followed");
		ft_putendl(" a room/comment\033[0m");
		ft_line_free(l, d);
	}
	else if (n == 4)
		ft_free_func(l, d);
}

void			ft_first_line(char *line, t_data *d, int *i)
{
	if (get_next_line(0, &line) != 1)
		ft_err1_line_free(" ", d, 2);
	if (is_int(line) && ft_atoi(line) > 0)
		ft_update_free(d, line, i, 1);
	else if (is_comment(line))
	{
		ft_update_free(d, line, i, 2);
		while (get_next_line(0, &line) > 0 && is_comment(line))
		{
			update_map2(d, line, i);
			free(line);
		}
		if (is_int(line) && ft_atoi(line) > 0)
		{
			update_map1(d, line, i);
			free(line);
		}
		else
			ft_err1_line_free(line, d, 0);
	}
	else
		ft_err1_line_free(line, d, 1);
}
