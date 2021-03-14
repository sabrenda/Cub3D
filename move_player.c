/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:32:29 by sabrenda          #+#    #+#             */
/*   Updated: 2021/03/13 02:04:18 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		player_finding_angle(float angle)
{
	angle = ft_normalize(angle);
	if (((angle > M_PI_4) && (angle < 0.75 * M_PI)) ||
		((angle > M_PI * 1.25) && (angle < 1.75 * M_PI)))
		return (1);
	return (0);
}

void	ft_update_pos(t_all *a)
{
	float	dir_x;
	float	plan_x;
	float	v_ang;

	dir_x = a->spr.dir_x;
	plan_x = a->spr.plan_x;
	v_ang = a->plr.turn_dir * a->plr.rot_speed;
	a->spr.plan_x = a->spr.plan_x * cos(v_ang) - a->spr.plan_y * sin(v_ang);
	a->spr.plan_y = a->spr.plan_y * cos(v_ang) + plan_x * sin(v_ang);
	a->spr.dir_x = a->spr.dir_x * cos(v_ang) - a->spr.dir_y * sin(v_ang);
	a->spr.dir_y = a->spr.dir_y * cos(v_ang) + dir_x * sin(v_ang);
}

void	ft_move_plus(float *new_plr_y, float *new_plr_x, float step, t_all *a)
{
	*new_plr_y = a->plr.y + sin(a->plr.angle_angle) * step;
	*new_plr_x = a->plr.x - cos(a->plr.angle_angle) * step;
}

void	ft_move_minus(float *new_plr_y, float *new_plr_x, float step, t_all *a)
{
	*new_plr_y = a->plr.y - sin(a->plr.angle_angle) * -step;
	*new_plr_x = a->plr.x + cos(a->plr.angle_angle) * -step;
}

void	ft_move_player(t_all *a)
{
	int		plr_finding;
	float	plr_x;
	float	plr_y;
	float	move;

	move = a->plr.walk_dir * a->plr.move_speed;
	plr_finding = player_finding_angle(a->plr.rot_angle);
	a->plr.rot_angle += a->plr.turn_dir * a->plr.rot_speed;
	plr_y = sin(a->plr.rot_angle) * move + a->plr.y;
	plr_x = cos(a->plr.rot_angle) * move + a->plr.x;
	if (a->plr.movement == 1 || a->plr.movement == -1)
	{
		a->plr.angle_angle = (M_PI / 2) - a->plr.rot_angle;
		if (plr_finding == 1)
			ft_move_plus(&plr_y, &plr_x, move, a);
		if (plr_finding == 0)
			ft_move_minus(&plr_y, &plr_x, move, a);
	}
	ft_update_pos(a);
	if (!ft_map_has_wallat(plr_x, plr_y, a))
	{
		a->plr.y = plr_y;
		a->plr.x = plr_x;
	}
}
