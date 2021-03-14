/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 02:03:38 by sabrenda          #+#    #+#             */
/*   Updated: 2021/03/13 02:03:39 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vector_e(t_all *a)
{
	a->spr.dir_x = 1;
	a->spr.dir_y = 0;
	a->spr.plan_x = 0;
	a->spr.plan_y = -0.6;
}

void	vector_s(t_all *a)
{
	a->spr.dir_x = 0;
	a->spr.dir_y = 1;
	a->spr.plan_x = 0.6;
	a->spr.plan_y = 0;
}

void	vector_w(t_all *a)
{
	a->spr.dir_x = -1;
	a->spr.dir_y = 0;
	a->spr.plan_x = 0;
	a->spr.plan_y = 0.6;
}

void	vector_n(t_all *a)
{
	a->spr.dir_x = 0;
	a->spr.dir_y = -1;
	a->spr.plan_x = -0.6;
	a->spr.plan_y = 0;
}

void	ft_vector_sprite(t_all *a)
{
	if (a->plr.pos == 'E')
		vector_e(a);
	if (a->plr.pos == 'S')
		vector_s(a);
	if (a->plr.pos == 'W')
		vector_w(a);
	if (a->plr.pos == 'N')
		vector_n(a);
}
