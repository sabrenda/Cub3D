/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:52:47 by sabrenda          #+#    #+#             */
/*   Updated: 2021/02/11 00:15:53 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_opengl_20191021/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "cub3d.h"
// #include "libft/libft/libft.h"

void	ft_screen(t_all *all)
{
	t_point point;

	point.x = 0;
	point.y = 0;

}
int main(void)
{

	t_all	all;
	t_point point;

	all.win.mlx = NULL;
	all.win.win = NULL;
	// all.map = NULL;
	point.x = 100;
	point.y = 100;

	all.win.mlx = mlx_init();
	all.win.win = mlx_new_window(all.win.mlx, 1200, 700, "cub3d");
	while (point.y++ < 200)
	{
		point.x = 100;
		while (point.x++ < 200)
		{
			mlx_pixel_put(all.win.mlx, all.win.win, point.x, point.y, 0xFFFFFF);
		}
	}
	mlx_loop(all.win.mlx);
}
