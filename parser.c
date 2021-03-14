/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:32:33 by sabrenda          #+#    #+#             */
/*   Updated: 2021/03/13 01:39:11 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file(t_all *all)
{
	if (!(ft_get_window_size(all, all->file, 'R')))
		return (0);
	if (!(ft_get_color(&all->inf, all->file, 'F')))
		return (0);
	if (!(ft_get_color(&all->inf, all->file, 'C')))
		return (0);
	if (!(get_image_1(all, 'N', 'O', ' ')))
		return (0);
	if (!(get_image_1(all, 'S', 'O', ' ')))
		return (0);
	if (!(get_image_1(all, 'W', 'E', ' ')))
		return (0);
	if (!(get_image_1(all, 'E', 'A', ' ')))
		return (0);
	if (!(get_sprite(all, 'S', ' ')))
		return (0);
	if (!(get_map(all)))
	{
		write(1, "error bad map!\n", 15);
		return (0);
	}
	if (close(all->fd))
		return (0);
	ft_lstclear(&all->gnl_head, &ft_free_content);
	return (1);
}
