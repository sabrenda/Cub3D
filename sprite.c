/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:33:03 by sabrenda          #+#    #+#             */
/*   Updated: 2021/03/13 02:03:00 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_allocation_sprite(t_all *a)
{
	a->spr.ptr = mlx_xpm_file_to_image(a->win.mlx, a->spr.path,
	&a->spr.width, &a->spr.height);
	if (!a->spr.ptr)
		return (0);
	a->spr.data = (int *)mlx_get_data_addr(a->spr.ptr,
	&a->spr.bpp, &a->spr.size_l, &a->spr.endian);
	if (!a->spr.data)
		return (0);
	if (!(a->spr.buffer = (float *)malloc(sizeof(float) * a->window_height)))
		return (0);
	ft_bzero(a->spr.buffer, sizeof(float) * a->window_width);
	if (!(a->spr.distance = (float *)malloc(sizeof(float) * a->spr.nb_sprite)))
		return (0);
	if (!(a->spr.x = (float *)malloc(sizeof(float) * a->spr.nb_sprite)))
		return (0);
	if (!(a->spr.y = (float *)malloc(sizeof(float) * a->spr.nb_sprite)))
		return (0);
	return (1);
}

void	ft_pos_sprite(t_all *a)
{
	int		x;
	int		y;
	int		count;

	count = 0;
	x = 0;
	while (a->map[x])
	{
		y = 0;
		while (a->map[x][y])
		{
			if (a->map[x][y] == '2')
			{
				a->spr.distance[count] = 0;
				a->spr.x[count] = y * a->tile_size + a->tile_size / 2;
				a->spr.y[count] = x * a->tile_size + a->tile_size / 2;
				count++;
			}
			y++;
		}
		x++;
	}
}

int		ft_init_sprite(t_all *a)
{
	if (!(ft_allocation_sprite(a)))
		return (0);
	ft_pos_sprite(a);
	ft_vector_sprite(a);
	return (1);
}
