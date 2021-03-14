/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:43:03 by sabrenda          #+#    #+#             */
/*   Updated: 2021/03/13 15:17:30 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_check_line_end(char *line)
{
	int		i;
	char	*line2;

	i = ft_strlen(line);
	if (line[i - 4] == '.' && line[i - 3] == 'x' && line[i - 2] == 'p'
		&& line[i - 1] == 'm')
		return (1);
	return (0);
}

void	ft_free_content(void *str)
{
	if ((char *)str)
	{
		free((char *)str);
		str = 0;
	}
}

void	ft_destroy_list(t_list **head, void (*del)(void *))
{
	t_list	*cur;
	t_list	*prev;

	if (head)
	{
		cur = *head;
		while (cur)
		{
			prev = cur;
			cur = cur->next;
			(*del)(prev->content);
			free(prev);
			prev = 0;
		}
	}
	*head = 0;
}

void	ft_newmap(t_all *a)
{
	int		x;
	int		y;

	x = -1;
	while (a->map[++x])
	{
		y = -1;
		while (a->map[x][++y])
		{
			if (a->map[x][y] == ' ')
				a->map[x][y] = '1';
		}
	}
}

int		check_player_in_map(t_all *a)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = -1;
	while (a->map[++x])
	{
		y = 0;
		while (a->map[x][y])
		{
			if (ft_strchr("NSEW", a->map[x][y]))
			{
				a->plr.pos = a->map[x][y];
				i++;
			}
			y++;
		}
	}
	if (i != 1)
		return (0);
	return (1);
}
