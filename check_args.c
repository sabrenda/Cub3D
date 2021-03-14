/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:30:32 by sabrenda          #+#    #+#             */
/*   Updated: 2021/03/13 01:30:37 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_open_fd(char *argv)
{
	int		fd;

	if ((fd = open(argv, O_RDONLY)) < 0)
	{
		write(1, "Error open file\n", 16);
		close(fd);
		return (-1);
	}
	return (fd);
}

int	ft_check_name_argv(char *name_m, char *cub, int flag)
{
	int			len_name;
	const char	*name;

	if ((int)ft_strlen(name_m) < (int)(ft_strlen(cub)) + flag)
	{
		write(1, "Error bad name arguments\n", 25);
		return (0);
	}
	len_name = (int)ft_strlen(name_m) - (int)(ft_strlen(cub));
	name = name_m;
	name = &name_m[len_name];
	if (ft_strncmp(name, cub, (ft_strlen(cub))))
	{
		write(1, "Error bad name arguments\n", 25);
		return (0);
	}
	return (1);
}

int	ft_check_args(int ac, char **argv, t_all *a)
{
	int		fd;

	if (ac < 2 || ac > 3)
	{
		write(1, "Error bad number arguments\n", 27);
		return (-1);
	}
	if (ac == 2)
	{
		if (!(ft_check_name_argv(argv[1], ".cub", 1)))
			return (-1);
	}
	if (ac == 3)
	{
		if (!(ft_check_name_argv(argv[1], ".cub", 1)))
			return (-1);
		if (!(ft_check_name_argv(argv[2], "--save", 0)))
			return (-1);
		a->screenshoot = 1;
	}
	return ((fd = ft_open_fd(argv[1])));
}
