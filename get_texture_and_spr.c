/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_and_spr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:32:13 by sabrenda          #+#    #+#             */
/*   Updated: 2021/03/13 01:56:05 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_image_3(t_all *all, char *r, int num)
{
	int		i;
	int		j;
	char	*line;
	int		res;

	line = &r[3];
	if (ft_strlen(line) < 6)
		return (0);
	line = NULL;
	if (!(line = (char *)malloc(sizeof(char *) * ft_strlen(r) + 1)))
		return (0);
	i = 2;
	j = -1;
	while (r[++i] && r[i])
	{
		if (r[i] == ' ' || r[i] == '\t')
			continue ;
		line[++j] = r[i];
	}
	line[++j] = '\0';
	if (!(ft_check_line_end(line)))
		return (0);
	all->txt[num].path = ft_strdup(line);
	free(line);
	return (1);
}

int		ft_get_sprite_2(t_all *a, char *r)
{
	int		i;
	int		j;
	char	*line;
	int		res;

	line = &r[2];
	if (ft_strlen(line) < 6)
		return (0);
	line = NULL;
	if (!(line = (char *)malloc(sizeof(char *) * ft_strlen(r) + 1)))
		return (0);
	i = 1;
	j = -1;
	while (r[++i] && r[i])
	{
		if (r[i] == ' ' || r[i] == '\t')
			continue ;
		line[++j] = r[i];
	}
	line[++j] = '\0';
	if (!(ft_check_line_end(line)))
		return (0);
	a->spr.path = ft_strdup(line);
	free(line);
	return (1);
}

int		ft_image_2(t_all *a, char q, char w, char *line)
{
	if (q == 'N' && w == 'O' && !(ft_image_3(a, line, 0)))
		return (0);
	if (q == 'S' && w == 'O' && !(ft_image_3(a, line, 1)))
		return (0);
	if (q == 'W' && w == 'E' && !(ft_image_3(a, line, 2)))
		return (0);
	if (q == 'E' && w == 'A' && !(ft_image_3(a, line, 3)))
		return (0);
	if (q == 'S' && w == ' ' && !(ft_get_sprite_2(a, line)))
		return (0);
	return (1);
}

int		get_image_1(t_all *a, char q, char w, char e)
{
	int		x;
	int		count;
	int		line_num;

	x = -1;
	count = 0;
	line_num = 0;
	while (a->file[++x])
	{
		if (a->file[x][0] == q && a->file[x][1] == w && a->file[x][2] == e)
		{
			line_num = x;
			count++;
		}
	}
	if (count != 1 || !(ft_image_2(a, q, w, a->file[line_num])))
		return (0);
	return (1);
}

int		get_sprite(t_all *a, char q, char w)
{
	int		x;
	int		count;
	int		line_num;

	x = -1;
	count = 0;
	line_num = 0;
	while (a->file[++x])
	{
		if (a->file[x][0] == q && a->file[x][1] == w)
		{
			line_num = x;
			count++;
		}
	}
	if (count != 1 || !(ft_image_2(a, q, w, a->file[line_num])))
		return (0);
	return (1);
}
