/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_cel_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:31:20 by sabrenda          #+#    #+#             */
/*   Updated: 2021/03/13 01:31:22 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_floor_and_ceiling(t_all *a)
{
	int		i;
	int		j;

	i = -1;
	while (++i < (a->window_height / 2))
	{
		j = -1;
		while (++j < a->window_width)
			a->win.addr[(i + a->window_height / 2)
			* a->window_width + (j + 0)] = a->inf.color_floor;
	}
	i = -1;
	while (++i < (a->window_height / 2))
	{
		j = -1;
		while (++j < a->window_width)
			a->win.addr[(i + 0) * a->window_width
			+ (j + 0)] = a->inf.color_ceiling;
	}
}
