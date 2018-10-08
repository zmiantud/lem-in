/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 13:40:35 by zmiantud          #+#    #+#             */
/*   Updated: 2018/09/24 13:25:01 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int		ft_check(int fd, char **line, char **s)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	if (s[fd][i] == '\0')
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	else if (s[fd][i] == '\n')
	{
		*line = ft_strsub(s[fd], 0, i);
		tmp = ft_strdup(&s[fd][i + 1]);
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*s[512];
	char			buf[BUFF_SIZE + 1];
	t_memb			data;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((data.i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[data.i] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		data.str = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = data.str;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (data.i < 0)
		return (-1);
	else if (data.i == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (ft_check(fd, line, s));
}
