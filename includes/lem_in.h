/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 13:50:57 by zmiantud          #+#    #+#             */
/*   Updated: 2018/09/27 14:09:09 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"

typedef struct	s_node
{
	char	*s;
	int		visited;
}				t_node;

typedef struct	s_data
{
	int			no_ants;
	char		**node_lst;
	int			*nod_i;
	int			**adj_matrix;
	char		**map;
	char		**links;
	int			*l_i;
	char		*start_node;
	char		*end_node;
	int			start;
	int			end;
	int			room;
	int			link;
	int			*stack;
	int			s_top;
	int			k;
	t_node		*vis_nod;
}				t_data;

/*
**put_map.c
*/

void			put_num_ants(t_data *d);
void			put_start_end(t_data *data);
void			put_map(char **s);
void			put_node(t_node *n, int i);

/*
**find_path.c
*/

void			find_path(t_data *d);

/*
**functions0.c
*/

void			ft_update_free(t_data *d, char *l, int *i, int n);
void			ft_line_free(char *line, t_data *d);
void			ft_err1_line_free(char *l, t_data *d, int n);
void			ft_first_line(char *line, t_data *d, int *i);

/*
**functions0_1.c
*/

void			ft_err2_line_free(char *l, t_data *d, int n);

/*
**functions1.c
*/

int				ft_start_index(t_data *d);
int				is_edge(t_data *d, int i, int j);
void			update_map1(t_data *d, char *line, int *i);
void			update_map2(t_data *d, char *line, int *i);

/*
**functions2.c
*/

int				is_room(char *line, t_data *d);
int				is_start(char *line);
int				is_end(char *line);
int				is_comment(char *line);
int				is_link(char *line);

/*
**functions3.c
*/

int				num_of_str(char **s);
int				is_valid_link(t_data *d, char *line);
int				is_valid_room(char **s, t_data *d);
int				is_start_end(char *line);
int				is_int(char *s);

/*
**functions4.c
*/

void			make_matrix(t_data *d);
char			*reverse_link(char *line);
int				search_in_arr(char **m_s, char *s);
void			check_line(t_data *d, char *line, int *i);

/*
**mand_part_check.c
*/

int				mand_part_check(t_data *d);

/*
**room.c
*/

void			ft_get_room(t_data *d, char *line, int *i);
void			ft_get_room2(t_data *d, char *line, int *i);

/*
**start.c
*/

void			ft_get_start(t_data *d, char *line, int *i);

/*
**end.c
*/

void			ft_get_end(t_data *d, char *line, int *i);

/*
**link.c
*/

void			ft_get_link(t_data *d, char *line, int *i);

/*
**stack.c
*/

void			ft_push(t_data *d, int n);
int				ft_pop(t_data *d);
int				ft_peek(t_data *d);
int				stack_is_empty(t_data *d);

/*
**send_ants.c
*/

void			send_ants(t_data *d, t_node *n);

/*
**ft_putmatrix.c
*/

void			ft_putmatrix(t_data *d);

/*
**ft_free.c
*/

void			ft_free(t_data *d, int n);

/*
**free_functions.c
*/
void			arraydel(char ***arr);
void			int_arrdel(t_data *d);
void			free_node_strs(t_data *d);
void			set_line_null(char **line);

#endif
