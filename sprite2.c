/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:33:09 by sabrenda          #+#    #+#             */
/*   Updated: 2021/03/13 01:42:50 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_sort_sprite(t_all *a)
{
	t_sprite_2	temp;
	int			count_y;
	int			count_x;

	count_x = -1;
	while (count_x++ < a->spr.nb_sprite)
	{
		count_y = count_x + 1;
		while (count_y < a->spr.nb_sprite)
		{
			if (a->spr.distance[count_y] > a->spr.distance[count_x])
			{
				temp.i = a->spr.distance[count_y];
				temp.j = a->spr.x[count_y];
				temp.y = a->spr.y[count_y];
				a->spr.distance[count_y] = a->spr.distance[count_x];
				a->spr.x[count_y] = a->spr.x[count_x];
				a->spr.y[count_y] = a->spr.y[count_x];
				a->spr.distance[count_x] = temp.i;
				a->spr.x[count_x] = temp.j;
				a->spr.y[count_x] = temp.y;
			}
			count_y++;
		}
	}
}

void	ft_spr_distan(t_all *a)
{
	int	i;

	i = -1;
	while (++i < a->spr.nb_sprite)
		a->spr.distance[i] = sqrt((a->spr.x[i] - a->plr.x) *
		(a->spr.x[i] - a->plr.x) + (a->spr.y[i] - a->plr.y) *
		(a->spr.y[i] - a->plr.y));
	ft_sort_sprite(a);
}

void	ft_set_spr(t_all *a)
{
	t_sprite_2	sprr;
	int			y;

	sprr.i = -1;
	ft_spr_distan(a);
	while (++sprr.i < a->spr.nb_sprite)
	{
		sprr.distan_proj = (a->window_width * 0.5) / tan(a->fov_angle * 0.5);
		sprr.size = (((a->tile_size / 2) / a->spr.distance[sprr.i])
			* sprr.distan_proj);
		if (ft_spr_vision(a, sprr.i, sprr.size) == 1)
		{
			sprr.transfer = ft_transfer_spr(a, sprr.i);
			ft_get_start(a, sprr.size);
			while (++a->spr.draw_start_x - 1 < a->spr.draw_end_x)
			{
				y = a->spr.draw_start_y;
				if (sprr.transfer > 0 && a->spr.draw_start_x > 0 &&
				a->spr.draw_start_x < a->window_width && sprr.transfer
				< a->spr.buffer[a->spr.draw_start_x])
					while (++y - 1 < a->spr.draw_end_y)
						drow_txt(a, a->spr.draw_start_x, y, sprr.size);
			}
		}
	}
}
