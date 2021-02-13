/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:52:47 by sabrenda          #+#    #+#             */
/*   Updated: 2021/02/12 15:59:05 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include "minilibx_opengl_20191021/mlx.h"
#include "libft/libft/libft.h"
#include "cub3d.h"
#include "get_next_line.h"

void ft_drow_img(t_win win, t_point point)
{
	t_point end;

	end.y = (point.y + 1) * SCALE;
	end.x = (point.x + 1) * SCALE;
	point.y *= SCALE;
	point.x *= SCALE;
	while (point.y < end.y)
	{
		while (point.x < end.x)
		{
			mlx_pixel_put(win.mlx, win.win, point.x, point.y, 0xFFFFFF);
			point.x++;
		}
		point.x -= SCALE;
		point.y++;
	}
}

void	ft_screen(t_all *all)
{
	t_point point;

	point.y = 0;
	point.x = 0;

	while (all->map[point.y])
	{
		point.x = 0;
		while (all->map[point.y][point.x])
		{
			if (all->map[point.y][point.x] == '1')
			{
				ft_drow_img(all->win, point);
			}
			point.x++;
		}
		point.y++;
	}
}

void ft_general(char **mapi)
{
	t_all	all;
	int i = 0;

	all.win.win = NULL;
	all.win.mlx = NULL;
	all.map = mapi;
	all.win.mlx = mlx_init();
	all.win.win = mlx_new_window(all.win.mlx, 1440, 900, "cub3d");
	ft_screen(&all);
	mlx_loop(all.win.mlx);
}

// void	ft_mylstclear(t_list **lst)
// {
// 	t_list	*next;
// 	t_list	*tmp;

// 	if (!lst || !*lst)
// 		return ;
// 	tmp = *lst;
// 	while (tmp)
// 	{
// 		next = tmp->next;
// 		free (tmp->content);
// 		tmp = next;
// 	}
// 	free(*lst);
// 	*lst = NULL;
// }

void make_map(t_list **head, int size)
{
	char **map = ft_calloc(size + 1, sizeof(char *));
	int i = 0;
	t_list *tmp = *head;

	while (tmp)
	{
		map[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	map[i] = NULL;
	i = 0;
	// ft_mylstclear(head);
	// while (map[i])
	// 	printf("%s\n", map[i++]);
	ft_general(map);
}
void	ft_readmap_with_gnl(int fd)
{
	int	check;
	char *line = NULL;
	t_list *head = NULL;
	while (check = get_next_line(fd, &line))
	{
		ft_lstadd_back(&head, ft_lstnew(line));
	}
	if (check == -1)
	{
		write(1,"FILE_READ_ERROR\n",16);
		return ;
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	make_map(&head, ft_lstsize(head));
}

int		main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);

	if (argc != 2)
	{
		write(1, "i need map\n", 11);
		close(fd);
		return (0);
	}
	ft_readmap_with_gnl(fd);
	close(fd);
	return (0);
}
