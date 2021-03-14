/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshoot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:32:59 by sabrenda          #+#    #+#             */
/*   Updated: 2021/03/13 16:53:03 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	write_to_bmp(int fd, t_all *a)
{
	char	*array;
	int		i;
	int		j;

	i = -1;
	j = 0;
	array = NULL;
	if (!(array = (char *)malloc(sizeof(char) * a->bmp.size)))
		destroy_all(a, "error malloc\n");
	a->bmp.size = a->bmp.size / 4;
	while (++i < a->bmp.size)
	{
		array[j++] = a->win.addr[i] & 255;
		array[j++] = (a->win.addr[i] & 65280) >> 8;
		array[j++] = (a->win.addr[i] & 16711680) >> 16;
		array[j++] = 0;
	}
	a->bmp.size *= 4;
	write(fd, array, a->bmp.size);
	free(array);
}

void	creating_bmp(t_all *a, char *file_name)
{
	if (!((a->fd = open(file_name, O_WRONLY | O_CREAT |
	O_TRUNC, S_IRUSR | S_IWUSR)) > 0))
		destroy_all(a, "error creating bmp\n");
	ft_bzero(&a->bmp, sizeof(a->bmp));
	init_header_screenshoot(&a->bmp, a);
	write_header_bmp(a->fd, a->bmp);
	write_to_bmp(a->fd, a);
	close(a->fd);
	destroy_all(a, "screenshoot done\n");
}
