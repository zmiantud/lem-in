/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mand_part_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:04:03 by zmiantud          #+#    #+#             */
/*   Updated: 2018/09/26 12:08:04 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		mand_part_check(t_data *d)
{
	if (d->start == 0)
	{
		ft_putendl("\033[31mNo start room found\033[0m");
		ft_free(d, 0);
		return (0);
	}
	else if (d->end == 0)
	{
		ft_putendl("\033[31mNo end room found\033[0m");
		ft_free(d, 0);
		return (0);
	}
	else if (d->link == 0)
	{
		ft_putendl("\033[31mNo link found\033[0m");
		ft_free(d, 0);
		return (0);
	}
	else
		return (1);
}
