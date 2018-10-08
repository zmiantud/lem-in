/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:48:15 by zmiantud          #+#    #+#             */
/*   Updated: 2018/09/24 17:26:13 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		is_duplicate(t_data *d, char *line)
{
	int		i;

	i = 0;
	while (d->links[i])
	{
		if (ft_strequ(d->links[i], line))
			return (1);
		i++;
	}
	return (0);
}

static void		save_link(t_data *d, char *line)
{
	if (*d->l_i == 0 && is_valid_link(d, line))
	{
		d->links[*d->l_i] = ft_strdup(line);
		*d->l_i = *d->l_i + 1;
		d->link = 1;
		return ;
	}
	else if (*d->l_i != 0)
	{
		d->links[*d->l_i] = ft_strdup(line);
		*d->l_i = *d->l_i + 1;
		d->link = 1;
	}
	else
	{
		ft_putstr("\033[31mError: first link is invalid: \033[31m");
		ft_putendl(line);
		ft_putstr("\033[0m");
		free(line);
		ft_free(d, 0);
	}
}

static int		ft_rev_duplicate(t_data *d, char *line)
{
	char	*rev;

	rev = reverse_link(line);
	if (!is_duplicate(d, rev))
	{
		free(rev);
		return (1);
	}
	free(rev);
	return (0);
}

void			ft_get_link(t_data *d, char *line, int *i)
{
	update_map2(d, line, i);
	if (d->room == 0)
	{
		ft_putendl("\033[31mError: Links found before any room\033[0m");
		free(line);
		ft_free(d, 0);
	}
	if (*d->l_i == 0)
		save_link(d, line);
	else
	{
		if (!is_duplicate(d, line) && \
				ft_rev_duplicate(d, line))
		{
			if (!is_valid_link(d, line))
			{
				ft_putendl("\033[31mError: Invalid link found\033[0m");
				free(line);
				ft_free(d, 0);
			}
			save_link(d, line);
		}
	}
}
