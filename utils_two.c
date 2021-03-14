/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:57:59 by sabrenda          #+#    #+#             */
/*   Updated: 2021/03/13 02:04:24 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		error_shit(const char *str)
{
	printf("%s", str);
	return (0);
}

void	ft_load_txt(t_all *a)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		a->txt[i].txt_ptr = mlx_xpm_file_to_image(a->win.mlx, a->txt[i].path,
			&a->txt[i].width, &a->txt[i].height);
		a->txt[i].wall_txt = (int *)mlx_get_data_addr(a->txt[i].txt_ptr,
			&a->win.bpp, &a->win.line_l, &a->win.en);
		if (!a->txt[i].wall_txt || !a->txt[i].txt_ptr)
		{
			write(1, "error load texture\n", 23);
			ft_all_free(a);
			ft_all_free_2(a);
			exit(0);
		}
		i++;
	}
}

void	ft_free_img(t_all *a)
{
	if (a->win.img)
	{
		mlx_destroy_image(a->win.mlx, a->win.img);
		a->win.img = NULL;
	}
}

int		ft_map_has_wallat(float x, float y, t_all *a)
{
	if (x < 0 || x > (a->map_num_cols * a->tile_size) || y < 0 ||
		y > (a->map_num_rows * a->tile_size))
		return (1);
	return (a->map[(int)floor(y / a->tile_size)][(int)floor(x / a->tile_size)]
		== '1');
}

float	ft_normalize(float angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
		return (angle = angle + (2 * M_PI));
	return (angle);
}
