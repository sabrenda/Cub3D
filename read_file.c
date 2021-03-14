/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:32:55 by sabrenda          #+#    #+#             */
/*   Updated: 2021/03/13 02:00:49 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strdup_2(const char *str, int lenght)
{
	char	*cp;
	int		i;

	i = 0;
	if (!(cp = (char *)malloc(sizeof(char) * lenght + 1)))
		return (NULL);
	cp[lenght + 1] = '\0';
	i = 0;
	while (str[i])
	{
		cp[i] = str[i];
		i++;
	}
	while (i <= lenght)
	{
		cp[i] = ' ';
		i++;
	}
	return (cp);
}

int		check_to_space(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

char	**make_file(t_list **head, int size)
{
	t_list		*tmp;
	char		**file;
	int			i;

	tmp = *head;
	i = 0;
	if (!(file = ft_calloc(size + 1, sizeof(char *))))
		return (0);
	while (tmp)
	{
		if (!(check_to_space(tmp->content)))
		{
			file[i] = tmp->content;
			i++;
		}
		tmp = tmp->next;
	}
	file[i] = NULL;
	return (file);
}

int		ft_read_file_with_gnl(t_all *all)
{
	int		check;
	char	*line;

	line = NULL;
	while ((check = get_next_line(all->fd, &line)))
	{
		ft_lstadd_back(&all->gnl_head, ft_lstnew(line));
	}
	if (check == -1)
	{
		ft_lstclear(&all->gnl_head, &ft_free_content);
		write(1, "FILE_READ_ERROR\n", 16);
		return (0);
	}
	ft_lstadd_back(&all->gnl_head, ft_lstnew(line));
	if (!(all->file = make_file(&all->gnl_head, ft_lstsize(all->gnl_head))))
	{
		ft_lstclear(&all->gnl_head, &ft_free_content);
		write(1, "Error malloc\n", 13);
		return (0);
	}
	return (1);
}
