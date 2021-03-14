/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:31:27 by sabrenda          #+#    #+#             */
/*   Updated: 2021/03/13 01:37:23 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	destroy_all(t_all *a, const char *str)
{
	printf("%s", str);
	free_sprite(a);
	if (a->win.win)
	{
		mlx_clear_window(a->win.mlx, a->win.win);
		mlx_destroy_window(a->win.mlx, a->win.win);
		if (a->win.img)
			mlx_destroy_image(a->win.mlx, a->win.img);
	}
	a->win.mlx = 0;
	a->win.win = 0;
	a->win.img = 0;
	exit(0);
	return (0);
}

int	destroy_all_2(t_all *a)
{
	printf("game end\n");
	free_sprite(a);
	if (a->win.win)
	{
		mlx_clear_window(a->win.mlx, a->win.win);
		mlx_destroy_window(a->win.mlx, a->win.win);
		if (a->win.img)
			mlx_destroy_image(a->win.mlx, a->win.img);
	}
	a->win.mlx = 0;
	a->win.win = 0;
	a->win.img = 0;
	exit(0);
	return (0);
}

int	ft_key_hit(int key, t_all *a)
{
	if (key == KEY_UP)
		a->plr.walk_dir = 1;
	if (key == KEY_DOWN)
		a->plr.walk_dir = -1;
	if (key == KEY_LEFT)
		a->plr.turn_dir = -1;
	if (key == KEY_RIGHT)
		a->plr.turn_dir = 1;
	if (key == 123)
	{
		a->plr.movement = -1;
		a->plr.walk_dir = -1;
	}
	if (key == 124)
	{
		a->plr.movement = 1;
		a->plr.walk_dir = 1;
	}
	if (key == KEY_EXIT)
		destroy_all(a, "game end\n");
	return (0);
}

int	ft_key_release(int key, t_all *a)
{
	if (key == KEY_UP)
		a->plr.walk_dir = 0;
	if (key == KEY_DOWN)
		a->plr.walk_dir = 0;
	if (key == KEY_LEFT)
		a->plr.turn_dir = 0;
	if (key == KEY_RIGHT)
		a->plr.turn_dir = 0;
	if (key == 123 || key == 124)
	{
		a->plr.movement = 0;
		a->plr.walk_dir = 0;
	}
	return (0);
}
