/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:59:46 by sabrenda          #+#    #+#             */
/*   Updated: 2021/02/11 14:43:42 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_linestart_or_tail(char **buf_line)
{
	char	*str;

	if (*buf_line)
	{
		str = ft_mystrdup(*buf_line);
		free(*buf_line);
		*buf_line = NULL;
		return (str);
	}
	else
		str = ft_mystrdup("");
	return (str);
}

char	*ft_point_change(char *point_n, char **buf_line)
{
	if (*buf_line)
	{
		free(*buf_line);
		*buf_line = NULL;
	}
	*point_n = '\0';
	point_n++;
	return (ft_mystrdup(point_n));
}

int		ft_get_line(int fd, char **line, char **buf_line)
{
	char			buf[BUFFER_SIZE + 1];
	char			*p_n;
	int				r_fd;

	p_n = NULL;
	r_fd = 0;
	if (!(*line = ft_linestart_or_tail(buf_line)))
		return (-1);
	if ((p_n = ft_mystrchr(*line, '\n')))
		if (!(*buf_line = ft_point_change(p_n, buf_line)))
			return (-1);
	while (!p_n && (r_fd = read(fd, buf, BUFFER_SIZE)) && r_fd > 0)
	{
		buf[r_fd] = '\0';
		if ((p_n = ft_mystrchr(buf, '\n')))
			if (!(*buf_line = ft_point_change(p_n, buf_line)))
				return (-1);
		if (!(*line = ft_mystrjoin(*line, buf)) || r_fd < 0)
			return (-1);
	}
	if (!p_n && (r_fd == 0 || (r_fd < BUFFER_SIZE && r_fd >= 0)))
		return (0);
	if (r_fd == -1)
		return (-1);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static t_gnl	*head;
	t_gnl			*tmp;
	t_gnl			*before;
	int				x;

	before = NULL;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!head && !(head = nw_mylst(fd)))
		return (-1);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			if (!(tmp->next = nw_mylst(fd)))
				return (-1);
		before = tmp;
		tmp = tmp->next;
	}
	if (!(x = ft_get_line(tmp->fd, line, &tmp->buf_line)) || x == -1)
	{
		if (!(ft_clean(&head, tmp, before)))
			head = NULL;
	}
	return (x);
}

int		ft_clean(t_gnl **head, t_gnl *tmp, t_gnl *before)
{
	if (tmp->buf_line)
	{
		free(tmp->buf_line);
		tmp->buf_line = NULL;
	}
	if (!before)
	{
		if (tmp->next == NULL)
		{
			free(tmp);
			return (0);
		}
		*head = tmp->next;
		free(tmp);
		return (1);
	}
	if (tmp->next == NULL)
	{
		before->next = NULL;
		free(tmp);
		return (1);
	}
	before->next = tmp->next;
	free(tmp);
	return (1);
}
