/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:32:51 by sabrenda          #+#    #+#             */
/*   Updated: 2021/03/13 16:26:38 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rays(t_all *a)
{
	int		i;

	i = -1;
	a->ray.ray_angle = a->plr.rot_angle - (a->fov_angle * 0.5);
	while (++i < a->num_rays)
	{
		clear_rays(&a->ray);
		if (a->ray.ray_angle > 0 && a->ray.ray_angle < M_PI)
			a->ray.ray_facing_down = 1;
		else
			a->ray.ray_facing_up = 1;
		if (a->ray.ray_angle > (1.5 * M_PI) || a->ray.ray_angle < (M_PI / 2))
			a->ray.ray_facing_right = 1;
		else
			a->ray.ray_facing_left = 1;
		horizontal_ray_grid(a);
		horizontal_intercept(a, a->ray.intercept_y, a->ray.intercept_x);
		vertical_ray_grid(a);
		vertical_intercept(a, a->ray.intercept_y, a->ray.intercept_x);
		ft_smallest_distance(&a->ray, &a->plr);
		ft_render_wall_projection(a, i);
		a->ray.ray_angle += (a->fov_angle / a->num_rays);
	}
}

void	ft_drawing_walls(t_all *a, t_render *txt, t_wall *wall, int i)
{
	if (a->ray.ray_facing_up && !a->ray.hit_vertical)
		txt->num = 0;
	if (a->ray.ray_facing_down && !a->ray.hit_vertical)
		txt->num = 1;
	if (a->ray.ray_facing_left && a->ray.hit_vertical)
		txt->num = 2;
	if (a->ray.ray_facing_right && a->ray.hit_vertical)
		txt->num = 3;
	if (a->ray.hit_vertical == 1)
		txt->offset_x = (int)(a->ray.wall_hit_y * a->txt[txt->num].width
		/ a->tile_size) % a->txt[txt->num].width;
	else
		txt->offset_x = (int)(a->ray.wall_hit_x * a->txt[txt->num].width
		/ a->tile_size) % a->txt[txt->num].width;
	while (wall->top < wall->bottom)
	{
		txt->distance_from_top = wall->top + (wall->height / 2) -
		(a->window_height / 2);
		txt->offset_y = txt->distance_from_top *
		((float)a->txt[txt->num].height / wall->height);
		txt->color = a->txt[txt->num].wall_txt[(a->txt[txt->num].width *
		txt->offset_y) + txt->offset_x];
		a->win.addr[(wall->top * a->window_width) + i] = txt->color;
		wall->top++;
	}
}

void	ft_render_wall_projection(t_all *a, int i)
{
	int			win_width_2;
	int			win_height_2;
	int			wal_height_2;
	t_wall		wall;
	t_render	txt;

	win_width_2 = a->window_width * 0.5;
	win_height_2 = a->window_height * 0.5;
	wall.perp_distance = a->ray.distan
	* cos(a->ray.ray_angle - a->plr.rot_angle);
	wall.proj_plane = (win_width_2) / tan(a->fov_angle * 0.5);
	wall.height = (a->tile_size / wall.perp_distance) * wall.proj_plane;
	wal_height_2 = wall.height * 0.5;
	wall.top = (win_height_2) - (wal_height_2);
	if (wall.top < 0)
		wall.top = 0;
	wall.bottom = (win_height_2) + (wal_height_2);
	if (wall.bottom > a->window_height)
		wall.bottom = a->window_height;
	a->spr.buffer[i] = wall.perp_distance;
	ft_drawing_walls(a, &txt, &wall, i);
}

void	update_distance(t_ray *ray, float vertical_dist, float horizontal_dist)
{
	if (vertical_dist < horizontal_dist)
		ray->hit_vertical = 1;
	if (horizontal_dist > vertical_dist)
	{
		ray->wall_hit_x = ray->vert_wall_hit_x;
		ray->wall_hit_y = ray->vert_wall_hit_y;
		ray->distan = vertical_dist;
	}
	else if (vertical_dist > horizontal_dist)
	{
		ray->wall_hit_x = ray->horz_wall_hit_x;
		ray->wall_hit_y = ray->horz_wall_hit_y;
		ray->distan = horizontal_dist;
	}
	else
	{
		ray->wall_hit_x = ray->horz_wall_hit_x;
		ray->wall_hit_y = ray->horz_wall_hit_y;
		ray->distan = horizontal_dist;
	}
}

void	ft_smallest_distance(t_ray *ray, t_player *plr)
{
	float		horizontal_dist;
	float		vertical_dist;

	if (ray->found_vert_wall_hit == 1)
	{
		vertical_dist = (sqrt((ray->vert_wall_hit_x - plr->x) *
		(ray->vert_wall_hit_x - plr->x) + (ray->vert_wall_hit_y - plr->y)
		* (ray->vert_wall_hit_y - plr->y)));
	}
	else
	{
		vertical_dist = INT32_MAX;
	}
	if (ray->found_horz_wall_hit == 1)
	{
		horizontal_dist = (sqrt((ray->horz_wall_hit_x - plr->x) *
		(ray->horz_wall_hit_x - plr->x) + (ray->horz_wall_hit_y - plr->y)
		* (ray->horz_wall_hit_y - plr->y)));
	}
	else
	{
		horizontal_dist = INT32_MAX;
	}
	update_distance(ray, vertical_dist, horizontal_dist);
}
