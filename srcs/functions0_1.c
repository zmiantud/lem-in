/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions0_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 12:19:17 by zmiantud          #+#    #+#             */
/*   Updated: 2018/09/25 12:37:02 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_err2_line_free(char *l, t_data *d, int n)
{
	if (n == 0)
	{
		ft_putstr("\033[031mError: ##end command not followed");
		ft_putendl(" by a room or a comment\033[0m");
		free(l);
		ft_free(d, 0);
	}
	else if (n == 1)
	{
		ft_putstr("\033[31mError: Comment not followed");
		ft_putendl(" by the end room\033[0m");
		free(l);
		ft_free(d, 0);
	}
}
