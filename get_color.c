/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:31:54 by sabrenda          #+#    #+#             */
/*   Updated: 2021/03/13 01:31:56 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_get_color_ceiling(char *r, t_info *inf)
{
	int		i;
	int		point;
	int		res;
	int		color[3];

	i = 0;
	point = 0;
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
		while (r[i] && (r[i] >= '0' && r[i] <= '9'))
			res = res * 10 + (r[i++] - '0');
		if (point < 3 && ((color[point++] = res) && !(res <= 255)))
			return (0);
	}
	inf->color_ceiling = (((color[0]) << 16) + ((color[1]) << 8) + (color[2]));
	return (1);
}

int	ft_get_color_floor(char *r, t_info *inf)
{
	int		i;
	int		point;
	int		res;
	int		color[3];

	i = 0;
	point = 0;
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
		while (r[i] && (r[i] >= '0' && r[i] <= '9'))
			res = res * 10 + (r[i++] - '0');
		if (point < 3 && ((color[point++] = res) && !(res <= 255)))
			return (0);
	}
	inf->color_floor = (((color[0]) << 16) + ((color[1]) << 8) + (color[2]));
	return (1);
}

int	ft_get_color(t_info *inf, char **file, char sym)
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
	if (sym == 'C' && !(ft_get_color_ceiling(file[line_num], inf)))
		return (0);
	if (sym == 'F' && !(ft_get_color_floor(file[line_num], inf)))
		return (0);
	return (1);
}
