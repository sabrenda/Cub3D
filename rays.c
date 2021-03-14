/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:32:47 by sabrenda          #+#    #+#             */
/*   Updated: 2021/03/13 02:02:37 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vertical_intercept(t_all *a, float next_horz_y, float next_horz_x)
{
	float	tmp;

	while (next_horz_x <= a->window_width && next_horz_x >= 0 &&
		next_horz_y <= a->window_height && next_horz_y >= 0)
	{
		if (a->ray.ray_facing_left)
			tmp = 1;
		else
			tmp = 0;
		if (ft_map_has_wallat(next_horz_x - tmp, next_horz_y, a))
		{
			a->ray.vert_wall_hit_x = next_horz_x;
			a->ray.vert_wall_hit_y = next_horz_y;
			a->ray.found_vert_wall_hit = 1;
			break ;
		}
		else
		{
			next_horz_x += a->ray.step_x;
			next_horz_y += a->ray.step_y;
		}
	}
}

void	vertical_ray_grid(t_all *a)
{
	a->ray.intercept_x = a->tile_size * floor(a->plr.x / a->tile_size);
	if (a->ray.ray_facing_right)
		a->ray.intercept_x += a->tile_size;
	else
		a->ray.intercept_x += 0;
	a->ray.intercept_y = a->plr.y + (a->ray.intercept_x - a->plr.x) *
	tan(a->ray.ray_angle);
	a->ray.step_x = a->tile_size;
	if (a->ray.ray_facing_left)
		a->ray.step_x *= -1;
	else
		a->ray.step_x *= 1;
	a->ray.step_y = a->tile_size * tan(a->ray.ray_angle);
	if ((a->ray.ray_facing_up && a->ray.step_y > 0) ||
	(a->ray.ray_facing_down && a->ray.step_y < 0))
		a->ray.step_y *= -1;
	else
		a->ray.step_y *= 1;
}

void	horizontal_intercept(t_all *a, float next_horz_y, float next_horz_x)
{
	float	tmp;
	int		nums_x;
	int		nums_y;

	nums_x = a->map_num_cols * a->tile_size;
	nums_y = a->map_num_rows * a->tile_size;
	while (next_horz_x >= 0 && next_horz_x <= nums_x &&
		next_horz_y >= 0 && next_horz_y <= nums_y)
	{
		if (a->ray.ray_facing_up)
			tmp = 1;
		else
			tmp = 0;
		if (ft_map_has_wallat(next_horz_x, next_horz_y - tmp, a))
		{
			a->ray.horz_wall_hit_y = next_horz_y;
			a->ray.horz_wall_hit_x = next_horz_x;
			a->ray.found_horz_wall_hit = 1;
			break ;
		}
		next_horz_x += a->ray.step_x;
		next_horz_y += a->ray.step_y;
	}
}

void	horizontal_ray_grid(t_all *a)
{
	a->ray.intercept_y = a->tile_size * floor(a->plr.y / a->tile_size);
	if (a->ray.ray_facing_down)
		a->ray.intercept_y += a->tile_size;
	a->ray.intercept_x = a->plr.x + ((a->ray.intercept_y - a->plr.y) /
	tan(a->ray.ray_angle));
	a->ray.step_y = a->tile_size;
	if (a->ray.ray_facing_up)
		a->ray.step_y *= -1;
	else
		a->ray.step_y *= 1;
	a->ray.step_x = a->tile_size / tan(a->ray.ray_angle);
	if (a->ray.ray_facing_left && a->ray.step_x > 0)
		a->ray.step_x *= -1;
	else
		a->ray.step_x *= 1;
	if (a->ray.ray_facing_right && a->ray.step_x < 0)
		a->ray.step_x *= -1;
	else
		a->ray.step_x *= 1;
}

void	clear_rays(t_ray *ray)
{
	float	a_angle;

	a_angle = ray->ray_angle;
	ft_bzero(ray, sizeof(t_ray));
	ray->ray_angle = ft_normalize(a_angle);
}
