/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:31:10 by sabrenda          #+#    #+#             */
/*   Updated: 2021/03/13 02:08:16 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "structs.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include <float.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "minilibx_opengl_20191021/mlx.h"
# include <fcntl.h>
# define MAX_VALUE 2147483647
# define PI 3.14159265
# define PI_TWO (PI * 2.0)
# define TWO_PI 6.28318530
# define FT_ABS(X) (((X) < 0) ? (-(X)) : (X))
# define KEY_UP 13
# define KEY_RIGHT 2
# define KEY_LEFT 0
# define KEY_DOWN 1
# define ROTATE_LEFT 123
# define ROTATE_RIGHT 124
# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYPRESSMASK 1
# define KEYRELEASEMASK 10
# define KEY_EXIT 53
# define STRUCTURENOTIFYMASK 10001

void	ft_init_null(t_all *all);
void	ft_init_null_2(t_all *all);
void	ft_init_txt(t_all *all);
void	ft_parser(t_all *all);
int		check_file(t_all *all);
int		ft_get_window_size(t_all *ia, char **file, char sym);
int		ft_get_window_size_2(char *r, t_all *a);
int		ft_get_window_size_3(t_all *a);
int		ft_get_color(t_info *inf, char **file, char sym);
int		ft_get_color_ceiling(char *r, t_info *inf);
int		ft_get_color_floor(char *r, t_info *inf);
int		ft_read_file_with_gnl(t_all *all);
char	**make_file(t_list **head, int size);
int		ft_check_name_argv(char *name_m, char *cub, int flag);
int		ft_check_args(int ac, char **argv, t_all *a);
int		ft_open_fd(char *argv);
int		ft_check_line_end(char *line);
int		get_image_1(t_all *a, char q, char w, char e);
int		ft_image_2(t_all *a, char q, char w, char *line);
int		ft_image_3(t_all *all, char *r, int num);
int		get_sprite(t_all *a, char q, char w);
int		ft_get_sprite_2(t_all *a, char *r);
int		check_to_space(char *line);
int		ft_allocation_sprite(t_all *a);
void	ft_free_content(void *str);
void	ft_destroy_list(t_list **head, void (*del)(void *));
int		ft_max_lenght_map(int start, t_all *a);
int		ft_map_copy(int start, int size, int lenght, t_all *a);
int		get_map(t_all *a);
char	*ft_strdup_2(const char *str, int lenght);
int		ft_pars_west_map(int rows, int cols, t_all *a);
int		ft_pars_east_map(int rows, int cols, t_all *a);
int		ft_pars_north_map(int rows, int cols, t_all *a);
int		ft_pars_south_map(int rows, int cols, t_all *a);
int		ft_pars_map_1(t_all *a);
int		ft_pars_map(t_all *a);
void	ft_newmap(t_all *a);
int		check_for_trash_map(t_all *a);
int		check_player_in_map(t_all *a);
void	ft_load_txt(t_all *a);
void	ft_init_all_2(t_all *a);
void	ft_init_player(t_all *a);
void	rotation_player(t_player *pl);
void	ft_vector_sprite(t_all *a);
void	vector_n(t_all *a);
void	vector_e(t_all *a);
void	vector_w(t_all *a);
void	vector_s(t_all *a);
void	ft_pos_sprite(t_all *a);
int		ft_init_sprite(t_all *a);
int		destroy_all(t_all *a, const char *str);
int		destroy_all_2(t_all *a);
int		ft_key_hit(int key, t_all *a);
int		ft_key_release(int key, t_all *a);
void	ft_start_event(t_all *a);
int		ft_run(t_all *a);
void	ft_free_img(t_all *a);
void	ft_move_player(t_all *a);
float	ft_normalize(float angle);
void	ft_update_pos(t_all *a);
int		ft_map_has_wallat(float x, float y, t_all *a);
void	ft_draw_floor_and_ceiling(t_all *a);
void	ft_set_spr(t_all *a);
void	ft_spr_distan(t_all *a);
void	ft_sort_sprite(t_all *a);
int		ft_spr_vision(t_all *a, int i, float spr_size);
float	ft_sprite_calc_angle(t_player *player, float x, float y);
float	ft_transfer_spr(t_all *a, int id);
void	ft_get_start(t_all *a, float spr_size);
void	drow_txt(t_all *a, int x, int y, float spr_size);
void	ft_rays(t_all *a);
void	clear_rays(t_ray *ray);
void	ray_look(t_ray *ray);
void	horizontal_ray_grid(t_all *a);
void	horizontal_intercept(t_all *a, float next_horz_y, float next_horz_x);
void	vertical_ray_grid(t_all *a);
void	vertical_intercept(t_all *a, float next_horz_y, float next_horz_x);
void	ft_smallest_distance(t_ray *ray, t_player *player);
void	update_distance(t_ray *ray, float vert_hit_distance,
		float horz_hit_distance);
void	ft_render_wall_projection(t_all *a, int i);
void	ft_drawing_walls(t_all *a, t_render *txt, t_wall *wall, int i);
void	ft_move_plus(float *new_plr_y, float *new_plr_x, float step, t_all *a);
void	ft_move_minus(float *new_plr_y, float *new_plr_x, float step, t_all *a);
int		player_finding_angle(float angle);
void	creating_bmp(t_all *a, char *file_name);
void	write_to_bmp(int fd, t_all *a);
void	write_header_bmp(int fd, t_bmp bmp);
void	init_header_screenshoot(t_bmp *bmp, t_all *a);
int		error_shit(const char *str);
void	ft_all_free(t_all *a);
void	ft_all_free_2(t_all *a);
void	free_sprite(t_all *a);
void	ft_clear_map(t_all *a);

#endif
