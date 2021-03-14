/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:31:35 by sabrenda          #+#    #+#             */
/*   Updated: 2021/03/13 01:35:54 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_clear_map(t_all *a)
{
	int		i;

	i = -1;
	if (a->map)
	{
		while (a->map[++i])
		{
			free(a->map[i]);
			a->map[i] = 0;
		}
		free(a->map);
		a->map = 0;
	}
}

void	ft_all_free(t_all *a)
{
	if (a->gnl_head)
		ft_lstclear(&a->gnl_head, &ft_free_content);
	if (a->spr.path)
		free(a->spr.path);
	a->spr.path = NULL;
	if (a->txt[0].path)
		free(a->txt[0].path);
	if (a->txt[1].path)
		free(a->txt[1].path);
	if (a->txt[2].path)
		free(a->txt[2].path);
	if (a->txt[3].path)
		free(a->txt[3].path);
	ft_clear_map(a);
}

void	ft_all_free_2(t_all *a)
{
	int		i;

	i = 0;
	if (a->txt[0].txt_ptr)
	{
		while (i < 4)
		{
			if (a->txt[i].txt_ptr)
				mlx_destroy_image(a->win.mlx, a->txt[i].txt_ptr);
			i++;
		}
	}
}

void	free_sprite(t_all *a)
{
	ft_all_free(a);
	ft_all_free_2(a);
	if (a->spr.ptr)
	{
		mlx_destroy_image(a->win.mlx, a->spr.ptr);
		a->spr.ptr = 0;
		free(a->spr.x);
		free(a->spr.y);
		free(a->spr.distance);
		free(a->spr.buffer);
	}
}
