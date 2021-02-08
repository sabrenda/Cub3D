/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:52:47 by sabrenda          #+#    #+#             */
/*   Updated: 2021/02/09 00:14:33 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_opengl_20191021/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// #include "libft/libft/libft.h"

int main(void)
{
	void *mlx = NULL;
	void *win = NULL;
	int x = 100;
	int y = 100;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1200, 700, "cub3d");
	while (y++ < 200)
	{
		x = 100;
		while (x++ < 200)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
		}

	}

	mlx_loop(mlx);
}
