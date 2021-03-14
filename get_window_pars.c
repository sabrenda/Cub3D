/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_window_pars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:32:18 by sabrenda          #+#    #+#             */
/*   Updated: 2021/03/13 01:45:07 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_get_window_size_3(t_all *a)
{
	if (a->window_height < 100 || a->window_width < 100)
		return (0);
	if (a->window_width > 5120 || a->window_height > 2880)
	{
		a->window_width = 5120;
		a->window_height = 2880;
	}
	return (1);
}

int		ft_get_window_size_2(char *r, t_all *a)
{
	int		i;
	int		res;
	int		flag;

	i = 0;
	flag = 0;
	while (r[++i])
		if ((r[i] >= 'a' && r[i] <= 'z') ||
			(r[i] >= 'A' && r[i] <= 'Z') || (r[i] == '-'))
			return (0);
	i = 1;
	while (r[i])
	{
		res = 0;
		while ((r[i] >= 9 && r[i] <= 47) || (r[i] >= 58 && r[i] <= 127))
			i++;
		while (r[i] >= '0' && r[i] <= '9')
			res = res * 10 + (r[i++] - '0');
		if (flag == 1)
			a->window_height = res;
		if (flag++ == 0)
			a->window_width = res;
	}
	return (1);
}

int		ft_get_window_size(t_all *a, char **file, char sym)
{
	int		x;
	int		count;
	int		line_num;

	x = -1;
	count = 0;
	line_num = 0;
	while (file[++x])
	{
		if (file[x][0] == sym && file[x][1] == ' ')
		{
			line_num = x;
			count++;
		}
	}
	if (count != 1)
		return (0);
	if (!(ft_get_window_size_2(file[line_num], a)))
		return (0);
	if (!(ft_get_window_size_3(a)))
		return (0);
	return (1);
}
