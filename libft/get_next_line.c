/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:05:31 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/28 10:14:22 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int		lst_contains(t_list *lst, t_read **curr, int fd)
{
	while (lst != NULL)
	{
		*curr = (t_read*)(lst->content);
		if (*curr != NULL)
		{
			if ((*curr)->fd == fd)
				return (1);
		}
		lst = lst->next;
	}
	return (0);
}

int		free_link(t_list **datas, t_read *curr)
{
	//t_read	*read;

	(void)curr;
	if (*datas == NULL)
		return (-1);
	//read = (t_read*)((*datas)->content);
	return (0);
}

int		set_line(t_read *curr, char **line)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while ((curr->str[i] != '\n') && (curr->str[i]))
		i++;
	if (!(*line = ft_strnew(i)))
		return (-1);
	ft_strncpy(*line, curr->str, i);
	if (i < ft_strlen(curr->str) - 1)
	{
		tmp = curr->str;
		if (!(curr->str = ft_strsub(curr->str, i + 1,
						ft_strlen(curr->str) - i - 1)))
			return (-1);
		ft_strdel(&tmp);
	}
	else
	{
		ft_strdel(&(curr->str));
		if (!(curr->str = ft_strnew(0)))
			return (-1);
	}
	return (0);
}

int		set_data(t_list **datas, char **line, t_read *curr, int new)
{
	if (curr->str[0])
	{
		if (set_line(curr, line) == -1)
			return (-1);
		if (new == 0)
		{
			ft_lstadd(datas, ft_lstnew(curr, sizeof(*curr)));
			free(curr);
			curr = NULL;
		}
		return (1);
	}
	if (new == 0)
	{
		ft_lstadd(datas, ft_lstnew(curr, sizeof(*curr)));
		free(curr);
		curr = NULL;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*datas = NULL;
	int				new;
	t_read			*curr;
	char			buff[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || line == NULL || BUFF_SIZE == 0 || read(fd, buff, 0) < 0)
		return (-1);
	if ((new = lst_contains(datas, &curr, fd)) == 0)
	{
		if (!(curr = (t_read*)malloc(sizeof(*curr))))
			return (-1);
		if (!(curr->str = ft_strnew(0)))
			return (-1);
		curr->fd = fd;
	}
	while ((!(ft_strchr(curr->str, '\n'))) && (ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (ret < 0 || !(curr->str = ft_strjoin_free(curr->str, buff)))
			return (-1);
	}
	return (set_data(&datas, line, curr, new));
}
