/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:32:38 by sabrenda          #+#    #+#             */
/*   Updated: 2021/03/13 01:57:38 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_pars_west_map(int rows, int cols, t_all *a)
{
	int		x;
	int		y;
	int		flag;

	x = -1;
	while (++x < rows)
	{
		y = -1;
		flag = 0;
		while (++y < cols)
		{
			if (a->map[x][y] == '1')
				flag = 1;
			if (a->map[x][y] == ' ')
				flag = 0;
			if (a->map[x][y] == '0' && flag == 0)
				return (0);
		}
	}
	return (1);
}

int		ft_pars_east_map(int rows, int cols, t_all *a)
{
	int		x;
	int		y;
	int		flag;

	x = rows;
	while (--x >= 0)
	{
		y = cols;
		flag = 0;
		while (--y >= 0)
		{
			if (a->map[x][y] == '1')
				flag = 1;
			if (a->map[x][y] == ' ')
				flag = 0;
			if (a->map[x][y] == '0' && flag == 0)
				return (0);
		}
	}
	return (1);
}

int		ft_pars_north_map(int rows, int cols, t_all *a)
{
	int		x;
	int		y;
	int		flag;

	x = -1;
	flag = 0;
	while (++x < cols)
	{
		y = -1;
		flag = 0;
		while (++y < rows)
		{
			if (a->map[y][x] == '1')
				flag = 1;
			if (a->map[y][x] == ' ')
				flag = 0;
			if (a->map[y][x] == '0' && flag == 0)
				return (0);
		}
	}
	return (1);
}

int		ft_pars_south_map(int rows, int cols, t_all *a)
{
	int		x;
	int		y;
	int		flag;

	y = cols;
	while (--y >= 0)
	{
		x = rows;
		flag = 0;
		while (--x >= 0)
		{
			if (a->map[x][y] == '1')
				flag = 1;
			if (a->map[x][y] == ' ')
				flag = 0;
			if (a->map[x][y] == '0' && flag == 0)
				return (0);
		}
	}
	return (1);
}

int		ft_pars_map_1(t_all *a)
{
	int		x;

	x = -1;
	while (++x < a->map_num_rows)
		if (a->map[x][0] != ' ' && a->map[x][0] != '1')
			return (0);
	x = -1;
	while (++x < a->map_num_cols)
		if (a->map[0][x] != ' ' && a->map[0][x] != '1')
			return (0);
	x = -1;
	while (++x < a->map_num_cols)
		if (a->map[a->map_num_rows - 1][x] != ' ' &&
			a->map[a->map_num_rows - 1][x] != '1')
			return (0);
	x = -1;
	while (++x < a->map_num_rows)
		if (a->map[x][a->map_num_cols - 1] != ' ' &&
			a->map[x][a->map_num_cols - 1] != '1')
			return (0);
	return (1);
}
