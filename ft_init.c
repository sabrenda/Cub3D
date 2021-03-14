/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:31:41 by sabrenda          #+#    #+#             */
/*   Updated: 2021/03/13 17:06:53 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_null_2(t_all *all)
{
	all->txt[0].path = NULL;
	all->txt[0].txt_ptr = NULL;
	all->txt[0].wall_txt = NULL;
	all->txt[1].path = NULL;
	all->txt[1].txt_ptr = NULL;
	all->txt[1].wall_txt = NULL;
	all->txt[2].path = NULL;
	all->txt[2].txt_ptr = NULL;
	all->txt[2].wall_txt = NULL;
	all->txt[3].path = NULL;
	all->txt[3].txt_ptr = NULL;
	all->txt[3].wall_txt = NULL;
}

void	ft_init_null(t_all *all)
{
	all->gnl_head = NULL;
	all->inf.sprint = NULL;
	all->spr.data = NULL;
	all->spr.ptr = NULL;
	all->spr.distance = NULL;
	all->spr.x = NULL;
	all->spr.y = NULL;
	all->spr.path = NULL;
	all->spr.buffer = NULL;
	all->win.win = NULL;
	all->win.mlx = NULL;
	all->win.img = NULL;
	all->map = NULL;
	all->file = NULL;
	ft_init_null_2(all);
	all->win.mlx = mlx_init();
}

void	ft_init_all_2(t_all *a)
{
	a->win.addr = 0;
	a->wall_strip_width = 1;
	a->tile_size = (a->window_width / a->map_num_cols);
	a->num_rays = (a->window_width / a->wall_strip_width);
	a->fov_angle = (60 * (M_PI / 180));
	a->plr.radius = 4;
	a->plr.turn_dir = 0;
	a->plr.walk_dir = 0;
	a->plr.move_speed = 3;
	a->plr.rot_speed = 3 * (M_PI / 180);
	a->spr.angle = 0;
	a->spr.ptr = 0;
	a->spr.data = 0;
	a->spr.bpp = 0;
	a->spr.endian = 0;
	a->spr.size_l = 0;
	a->spr.width = 0;
	a->spr.height = 0;
	ft_init_player(a);
}

void	init_header_screenshoot(t_bmp *bmp, t_all *a)
{
	bmp->bpp_y = 0;
	bmp->bpp_x = 0;
	bmp->total_colors = 0;
	bmp->important_colors = 0;
	bmp->reserved = 0;
	bmp->compression = 0;
	bmp->color_planes = 1;
	bmp->bpp = 32;
	bmp->header_size = 40;
	bmp->offset = 54;
	bmp->byte[0] = 66;
	bmp->byte[1] = 77;
	bmp->img_width = a->window_width;
	bmp->img_height = -a->window_height;
	bmp->size = (a->window_width * a->window_height * 4) + 54;
	bmp->img_size = (a->window_width * a->window_height * 4);
}

void	write_header_bmp(int fd, t_bmp bmp)
{
	write(fd, &bmp.byte, 2);
	write(fd, &bmp.size, 4);
	write(fd, &bmp.reserved, 4);
	write(fd, &bmp.offset, 4);
	write(fd, &bmp.header_size, 4);
	write(fd, &bmp.img_width, 4);
	write(fd, &bmp.img_height, 4);
	write(fd, &bmp.color_planes, 2);
	write(fd, &bmp.bpp, 2);
	write(fd, &bmp.compression, 4);
	write(fd, &bmp.img_size, 4);
	write(fd, &bmp.bpp_x, 4);
	write(fd, &bmp.bpp_y, 4);
	write(fd, &bmp.total_colors, 4);
	write(fd, &bmp.important_colors, 4);
}
