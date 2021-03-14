/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:33:14 by sabrenda          #+#    #+#             */
/*   Updated: 2021/03/13 01:33:15 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drow_txt(t_all *a, int x, int y, float spr_size)
{
	int	color;
	int	txt_y;
	int	txt_x;

	txt_y = (int)(((256 * y - a->window_height * 128 + spr_size * 128)
	* a->spr.height) / spr_size) / 256;
	txt_x = (int)(256 * (x - (-spr_size / 2 + a->spr.spritescreenx))
		* a->spr.width / spr_size) / 256;
	if (((txt_y * a->spr.width) + txt_x) < sizeof(a->spr.data))
		return ;
	color = a->spr.data[(txt_y * a->spr.width) + txt_x];
	if (color != 0x000000)
		a->win.addr[y * a->window_width + x] = color;
}

void	ft_get_start(t_all *a, float spr_size)
{
	int		w_2;

	w_2 = a->window_height * 0.5;
	a->spr.draw_start_x = -spr_size * 0.5 + a->spr.spritescreenx;
	if (a->spr.draw_start_x < 0)
		a->spr.draw_start_x = 0;
	a->spr.draw_end_x = spr_size * 0.5 + a->spr.spritescreenx;
	if (a->spr.draw_end_x >= a->window_width)
		a->spr.draw_end_x = a->window_width - 1;
	a->spr.draw_start_y = -spr_size * 0.5 + w_2;
	if (a->spr.draw_start_y < 0)
		a->spr.draw_start_y = 0;
	a->spr.draw_end_y = spr_size * 0.5 + w_2;
	if (a->spr.draw_end_y >= a->window_height)
		a->spr.draw_end_y = a->window_height - 1;
}

float	ft_transfer_spr(t_all *a, int i)
{
	float		x;
	float		y;
	float		invdet;

	invdet = 1.0 / (a->spr.plan_x * a->spr.dir_y - a->spr.dir_x
		* a->spr.plan_y);
	x = invdet * (a->spr.dir_y * (a->spr.x[i] - a->plr.x) - a->spr.dir_x
		* (a->spr.y[i] - a->plr.y));
	y = invdet * (-a->spr.plan_y * (a->spr.x[i] - a->plr.x) + a->spr.plan_x
		* (a->spr.y[i] - a->plr.y));
	a->spr.spritescreenx = (int)((a->window_width / 2) * (1 + -x / y));
	return (invdet * (-a->spr.plan_y * (a->spr.x[i] - a->plr.x)
		+ a->spr.plan_x * (a->spr.y[i] - a->plr.y)));
}

float	ft_sprite_calc_angle(t_player *player, float x, float y)
{
	float	spr_ang;

	spr_ang = ft_normalize(player->rot_angle) -
		atan2(y - player->y, x - player->x);
	if (spr_ang > M_PI)
		spr_ang -= PI_TWO;
	if (spr_ang < -M_PI)
		spr_ang += PI_TWO;
	return (fabs(spr_ang));
}

int		ft_spr_vision(t_all *a, int i, float spr_size)
{
	float	spr_angle;
	float	spr_angle_end;

	spr_angle = ft_sprite_calc_angle(&a->plr, a->spr.x[i], a->spr.y[i]);
	spr_angle_end = ft_sprite_calc_angle(&a->plr, (a->spr.x[i] + spr_size)
		, (a->spr.y[i] + spr_size));
	if (spr_angle < (a->fov_angle / 2 + fabs(spr_angle_end - spr_angle)))
		return (1);
	return (0);
}
