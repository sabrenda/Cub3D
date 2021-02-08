/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:06:35 by sabrenda          #+#    #+#             */
/*   Updated: 2021/02/09 00:14:56 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft/libft.h"
#include "get_next_line.h"
#include <fcntl.h>

// #include <mlx.h>

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putendl(char *s)
{
	ft_putstr(s);
	write(1, "\n", 1);
}

void make_map(t_list **head, int size)
{
	char **map = ft_calloc(size + 1, sizeof(char *));
	int i = -1;
	t_list *tmp = *head;

	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	i = -1;
	while (map[++i])
	{
		ft_putendl(map[i]);
	}


}
int main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);
	char *line = NULL;
	t_list *head = NULL;

	if (argc != 2)
	{
		write(1, "i need map\n", 11);
		return (0);
	}
	while (get_next_line(fd, &line))
	{
		ft_lstadd_back(&head, ft_lstnew(line));
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	make_map(&head, ft_lstsize(head));
}
