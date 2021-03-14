/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:32:23 by sabrenda          #+#    #+#             */
/*   Updated: 2021/03/13 01:44:24 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_start_event(t_all *a)
{
	mlx_hook(a->win.win, KEYPRESS, KEYPRESSMASK, ft_key_hit, a);
	mlx_hook(a->win.win, KEYRELEASE, KEYRELEASEMASK, ft_key_release, a);
	mlx_hook(a->win.win, 17, 1, destroy_all_2, a);
	mlx_loop_hook(a->win.mlx, ft_run, a);
	mlx_loop(a->win.mlx);
}

int		ft_run(t_all *a)
{
	ft_free_img(a);
	a->win.img = mlx_new_image(a->win.mlx, a->window_width, a->window_height);
	if (!a->win.img)
		destroy_all(a, "error create image\n");
	a->win.addr = (int *)mlx_get_data_addr(a->win.img, &a->win.bpp,
	&a->win.line_l, &a->win.en);
	if (!a->win.addr)
		destroy_all(a, "error create addres image\n");
	ft_move_player(a);
	ft_draw_floor_and_ceiling(a);
	ft_rays(a);
	ft_set_spr(a);
	if (a->screenshoot)
		creating_bmp(a, "screen_save.bmp");
	mlx_put_image_to_window(a->win.mlx, a->win.win, a->win.img, 0, 0);
	return (0);
}

void	ft_parser(t_all *all)
{
	if (!(ft_read_file_with_gnl(all)))
	{
		write(1, "Error read file\n", 15);
		close(all->fd);
		ft_all_free(all);
		ft_all_free_2(all);
		exit(0);
	}
	if (!(check_file(all)))
	{
		write(1, "error info in file .cub\n", 24);
		ft_all_free(all);
		ft_all_free_2(all);
		exit(0);
	}
}

int		main(int argc, char **argv)
{
	t_all	all;

	ft_init_null(&all);
	if ((all.fd = ft_check_args(argc, argv, &all)) < 0)
		return (error_shit("error open file\n"));
	ft_parser(&all);
	ft_load_txt(&all);
	ft_init_all_2(&all);
	if (!(ft_init_sprite(&all)))
		destroy_all(&all, "error alocated memory for sprite\n");
	if (!all.screenshoot)
	{
		if (!(all.win.win = mlx_new_window(all.win.mlx, all.window_width,
			all.window_height, "Interstellar")))
			destroy_all(&all, "error open window\n");
	}
	if (all.screenshoot)
		ft_run(&all);
	ft_start_event(&all);
	return (0);
}
