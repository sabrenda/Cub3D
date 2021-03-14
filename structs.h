/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:33:17 by sabrenda          #+#    #+#             */
/*   Updated: 2021/03/13 16:44:59 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "libft/libft.h"

typedef struct		s_player
{
	float			x;
	float			y;
	int				radius;
	float			angle_angle;
	int				turn_dir;
	int				walk_dir;
	float			rot_angle;
	float			move_speed;
	float			rot_speed;
	char			pos;
	int				movement;
}					t_player;

typedef struct		s_render
{
	int				offset_x;
	int				offset_y;
	int				color;
	int				distance_from_top;
	int				num;
}					t_render;

typedef struct		s_texture
{
	char			*path;
	void			*txt_ptr;
	int				*wall_txt;
	int				height;
	int				width;
}					t_texture;

typedef struct		s_info
{
	char			*texture[5];
	char			*sprint;
	int				nline_map;
	int				color_ceiling;
	int				color_floor;
	int				size_line;
	char			orientation;
}					t_info;

typedef struct		s_ray
{
	float			distan;
	float			ray_angle;
	float			intercept_x;
	float			intercept_y;
	float			step_x;
	float			step_y;
	float			wall_hit_x;
	float			wall_hit_y;
	float			vert_wall_hit_x;
	float			vert_wall_hit_y;
	float			horz_wall_hit_x;
	float			horz_wall_hit_y;
	float			hit_vertical;
	int				found_vert_wall_hit;
	int				found_horz_wall_hit;
	int				ray_facing_down;
	int				ray_facing_up;
	int				ray_facing_right;
	int				ray_facing_left;
}					t_ray;

typedef struct		s_wall
{
	float			perp_distance;
	float			proj_plane;
	int				height;
	int				top;
	int				bottom;
}					t_wall;

typedef struct		s_bmp
{
	int				img_width;
	int				img_height;
	int				bpp_x;
	int				bpp_y;
	char			byte[2];
	unsigned		header_size;
	unsigned int	size;
	unsigned int	reserved;
	unsigned int	offset;
	unsigned int	compression;
	unsigned int	img_size;
	unsigned int	total_colors;
	unsigned int	important_colors;
	unsigned short	color_planes;
	unsigned short	bpp;
}					t_bmp;

typedef struct		s_sprite
{
	int				*data;
	void			*ptr;
	int				size_l;
	float			*distance;
	float			angle;
	int				width;
	int				bpp;
	int				endian;
	int				height;
	float			*x;
	float			*y;
	char			*path;
	int				nb_sprite;
	float			dir_y;
	float			dir_x;
	float			plan_y;
	float			plan_x;
	float			*buffer;
	int				spritescreenx;
	int				draw_start_y;
	int				draw_start_x;
	int				draw_end_y;
	int				draw_end_x;
}					t_sprite;

typedef struct		s_sprite_2
{
	float			distan_proj;
	float			transfer;
	float			size;
	int				i;
	int				j;
	int				y;
}					t_sprite_2;

typedef struct		s_window
{
	void			*mlx;
	void			*img;
	void			*win;
	int				*addr;
	int				line_l;
	int				bpp;
	int				en;
}					t_win;

typedef struct		s_all
{
	t_player		plr;
	t_texture		txt[4];
	t_info			inf;
	t_ray			ray;
	t_bmp			bmp;
	t_sprite		spr;
	t_win			win;
	t_list			*gnl_head;
	int				fd;
	char			**file;
	char			**map;
	int				screenshoot;
	int				wall_strip_width;
	int				tile_size;
	int				map_num_rows;
	int				map_num_cols;
	int				window_width;
	int				window_height;
	float			num_rays;
	float			fov_angle;
	int				size;
}					t_all;

#endif
