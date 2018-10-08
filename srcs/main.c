/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 10:20:00 by zmiantud          #+#    #+#             */
/*   Updated: 2018/09/27 12:51:10 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		init_data(t_data *d)
{
	d->no_ants = 0;
	d->nod_i = (int *)malloc(sizeof(int));
	*d->nod_i = 0;
	d->l_i = (int *)malloc(sizeof(int));
	*d->l_i = 0;
	d->node_lst = NULL;
	d->adj_matrix = NULL;
	d->map = NULL;
	d->start_node = NULL;
	d->end_node = NULL;
	d->links = NULL;
	d->start = 0;
	d->end = 0;
	d->room = 0;
	d->link = 0;
	d->s_top = -1;
	d->k = 0;
}

static void		get_map(t_data *d)
{
	int		i;
	char	*line;
	char	**s;

	i = 0;
	line = NULL;
	d->map = (char **)malloc(sizeof(char *) * 10000);
	d->node_lst = (char **)malloc(sizeof(char *) * 20000);
	d->links = (char **)malloc(sizeof(char *) * 10000);
	ft_first_line(line, d, &i);
	while (1)
	{
		line = NULL;
		if (get_next_line(0, &line) > 0)
		{
			check_line(d, line, &i);
			free(line);
		}
		else
			break ;
	}
}

int				main(void)
{
	t_data	data;

	init_data(&data);
	get_map(&data);
	mand_part_check(&data);
	put_map(data.map);
	ft_putchar('\n');
	put_num_ants(&data);
	put_start_end(&data);
	make_matrix(&data);
	ft_putmatrix(&data);
	find_path(&data);
	ft_free(&data, 1);
	return (0);
}
