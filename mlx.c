/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:52:47 by sabrenda          #+#    #+#             */
/*   Updated: 2021/02/17 00:27:29 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include "minilibx_opengl_20191021/mlx.h"
#include "libft/libft/libft.h"
#include "cub3d.h"
#include "get_next_line.h"


void	my_mlx_pixel_put(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->line_l + x * (win->bpp / 8));
	*(unsigned int*)dst = color;
}

void ft_draw_player(t_all *all)
{
	t_plr	ray = all->plr; // задаем координаты и направление луча равные координатам игрока
	ray.start = ray.dir - M_PI_4; // начало веера лучей
	ray.end = ray.dir + M_PI_4; // край веера лучей

	while (ray.start <= ray.end)
	{
		ray.x = all->plr.x; // каждый раз возвращаемся в точку начала
		ray.y = all->plr.y;
		while (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '1')
		{
			ray.x += cos(ray.start);
			ray.y += sin(ray.start);
			my_mlx_pixel_put(&all->win, ray.x, ray.y, 0xFF0000);
		}
		ray.start += M_PI_2 / 600;
	}
}

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
			// mlx_pixel_put(win.mlx, win.win, point.x, point.y, 0xFFFFFF);
			my_mlx_pixel_put(&win, point.x, point.y, 0xFFFF00);
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
	all->win.img = mlx_new_image(all->win.mlx, 1440, 900);
	all->win.addr = mlx_get_data_addr(all->win.img, &all->win.bpp, &all->win.line_l,
		&all->win.en);
	while (all->map[point.y])
	{
		point.x = 0;
		while (all->map[point.y][point.x])
		{
			if (all->map[point.y][point.x] == '1')
				ft_drow_img(all->win, point);
			point.x++;
		}
		point.y++;
	}
	ft_draw_player(all);
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->win.img, 0, 0);
	mlx_destroy_image(all->win.mlx, all->win.img);
}

int		key_press(int key, t_all *all)
{
	mlx_clear_window(all->win.mlx, all->win.win);
	if (key == 13)
	{
		all->plr.y += sin(all->plr.dir) * 4;
		all->plr.x += cos(all->plr.dir) * 4;
	}
	if (key == 1)
	{
		all->plr.y -= sin(all->plr.dir) * 4;
		all->plr.x -= cos(all->plr.dir) * 4;
	}
	if (key == 0)
		all->plr.dir -= 0.1;
	if (key == 2)
		all->plr.dir += 0.1;
	if (key == 53)
		exit(0);
	ft_screen(all);
	return (0);
}

void	ft_error_player_init(t_all *all)
{
	int y;

	y = 0;
	while (all->map[y])
	{
		free(all->map[y]);
		y++;
	}
	if (all->map)
		free(all->map);
	all->map = NULL;
	write(1, "ERROR, YOU NEED INIT PLAYER\n", 28);
	exit (0);
}

void	ft_init_player(t_all *all)
{
	int		i;
	int		y;
	int		x;

	i = 0;
	y = 0;
	while (all->map[y])
	{
		x = 0;
		while (all->map[y][x])
		{
			if (all->map[y][x] == 'N' || all->map[y][x] == 'S'
				|| all->map[y][x] == 'E' || all->map[y][x] == 'W')
			{
				all->plr.x = x * SCALE;
				all->plr.y = y * SCALE;
				all->plr.dir = 3 * M_PI_2;
				i++;
			}
			x++;
		}
		y++;
	}
	if (i != 1)
		ft_error_player_init(all);
}

void	ft_init(t_all *all)
{
	all->win.win = NULL;
	all->win.mlx = NULL;
	all->win.img = NULL;
}

void	ft_general(char **mapi)
{
	t_all	all;

	all.map = mapi;
	ft_init(&all);
	ft_init_player(&all);
	all.win.mlx = mlx_init();
	all.win.win = mlx_new_window(all.win.mlx, 1440, 900, "cub3d");
	ft_screen(&all);
	mlx_hook(all.win.win, 2, (1L << 0), &key_press, &all);
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
	while ((check = get_next_line(fd, &line)))
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
