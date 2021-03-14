/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:32:08 by sabrenda          #+#    #+#             */
/*   Updated: 2021/03/13 02:00:31 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_for_trash_map(t_all *a)
{
	int		x;
	int		y;
	int		sprite;

	sprite = 0;
	x = 0;
	while (a->map[x])
	{
		y = 0;
		while (a->map[x][y])
		{
			if (!(ft_strchr("012NSEW ", a->map[x][y])))
				return (0);
			if (a->map[x][y] == '2')
				sprite++;
			y++;
		}
		x++;
	}
	a->spr.nb_sprite = sprite;
	return (1);
}

int		ft_pars_map(t_all *a)
{
	if (!(ft_pars_map_1(a)))
		return (0);
	if (!(ft_pars_west_map(a->map_num_rows, a->map_num_cols, a)))
		return (0);
	if (!(ft_pars_east_map(a->map_num_rows, a->map_num_cols, a)))
		return (0);
	if (!(ft_pars_north_map(a->map_num_rows, a->map_num_cols, a)))
		return (0);
	if (!(ft_pars_south_map(a->map_num_rows, a->map_num_cols, a)))
		return (0);
	if (!(check_for_trash_map(a)))
		return (0);
	if (!(check_player_in_map(a)))
		return (0);
	ft_newmap(a);
	return (1);
}

int		ft_map_copy(int start, int size, int lenght, t_all *a)
{
	char	**like;
	int		x;
	int		i;

	i = 0;
	like = NULL;
	if (!(like = (char **)malloc(sizeof(char *) * size)))
		return (0);
	while (a->file[start])
	{
		if (!(like[i] = ft_strdup_2(a->file[start], lenght)))
			return (0);
		i++;
		start++;
	}
	like[i] = NULL;
	a->map = like;
	ft_destroy_list(&a->gnl_head, &ft_free_content);
	return (1);
}

int		ft_max_lenght_map(int start, t_all *a)
{
	int		i;
	int		x;
	int		point;

	point = 0;
	i = 0;
	x = 0;
	while (a->file[start])
	{
		x = 0;
		while (a->file[start][x])
		{
			if (x > point)
				point = x;
			x++;
		}
		start++;
	}
	a->map_num_cols = point + 1;
	return (point);
}

int		get_map(t_all *a)
{
	int		x;
	int		y;
	int		start;

	x = -1;
	y = 0;
	start = 0;
	while (a->file[y++])
		y = y;
	while (a->file[++x][0])
		if (a->file[x][0] == ' ' || a->file[x][0] == '1')
		{
			start = x;
			break ;
		}
	if (y - start < 3)
		return (0);
	x = ft_max_lenght_map(start, a);
	if (!(ft_map_copy(start, y - start + 1, x, a)))
		return (0);
	a->map_num_rows = (y - start - 1);
	if (!(ft_pars_map(a)))
		return (0);
	return (1);
}
