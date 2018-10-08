/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 13:29:25 by zmiantud          #+#    #+#             */
/*   Updated: 2018/08/31 12:53:28 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		res;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i])
	{
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		if (!str[i])
			return (0);
		if (str[i] == '-' || str[i] == '+')
		{
			sign = (str[i] == '-') ? -1 : 1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
			res = (res * 10) + str[i++] - '0';
	}
	return (sign * res);
}
