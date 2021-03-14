/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:32:42 by sabrenda          #+#    #+#             */
/*   Updated: 2021/03/13 01:42:14 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotation_player(t_player *pl)
{
	if (pl->pos == 'N')
		pl->rot_angle = 3 * M_PI_2;
	if (pl->pos == 'S')
		pl->rot_angle = M_PI_2;
	if (pl->pos == 'E')
		pl->rot_angle = 0;
	if (pl->pos == 'W')
		pl->rot_angle = M_PI;
}

void	ft_init_player(t_all *a)
{
	int		y;
	int		x;

	y = -1;
	while (a->map[++y])
	{
		x = -1;
		while (a->map[y][++x])
		{
			if (ft_strchr("NEWS", a->map[y][x]))
			{
				a->plr.x = a->tile_size * x + a->tile_size / 2;
				a->plr.y = a->tile_size * y + a->tile_size / 2;
				rotation_player(&a->plr);
				a->map[y][x] = '0';
			}
		}
	}
}
