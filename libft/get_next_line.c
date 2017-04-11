/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:23:12 by thninh            #+#    #+#             */
/*   Updated: 2017/03/18 10:42:56 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

t_get				*ft_manage_fd(int fd, t_get **list)
{
	while (*list && (*list)->fd != fd)
		list = &(*list)->next;
	if (!*list)
	{
		*list = (t_get*)malloc(sizeof(**list));
		(*list)->tmp = NULL;
		(*list)->fd = fd;
		(*list)->next = NULL;
	}
	return (*list);
}

char				*ft_strjoin_free(const char *s1, const char *s2, int del)
{
	char			*str;

	str = NULL;
	if (s1 && s2)
	{
		str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) +
					ft_strlen((char *)s2)) + 1);
		if (!str)
			return (NULL);
		str = ft_strcat(ft_strcpy(str, s1), s2);
		if (del == 1)
			ft_strdel((char **)&s1);
		if (del == 2)
			ft_strdel((char **)&s2);
		if (del == 3)
		{
			ft_strdel((char **)&s1);
			ft_strdel((char **)&s2);
		}
	}
	return (str);
}

int					ft_check_stock(t_get *file, char **line)
{
	char			*tmp;

	if (!file->tmp)
		return (0);
	if ((tmp = ft_strchr(file->tmp, '\n')))
	{
		*line = ft_strjoin_free(*line,
				ft_strsub(file->tmp, 0, tmp - file->tmp), 3);
		file->tmp = ft_strdup(file->tmp + (tmp - file->tmp) + 1);
		return (1);
	}
	else
	{
		*line = ft_strjoin_free(*line, file->tmp, 1);
		ft_strdel(&(file->tmp));
	}
	return (0);
}

int					ft_check_folder(t_get *file, char **line)
{
	int				ret;
	char			*tmp;
	char			*buf;

	buf = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (!buf)
		return (-1);
	while ((ret = read(file->fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if ((tmp = ft_strchr(buf, '\n')))
		{
			*line = ft_strjoin_free(*line, ft_strsub(buf, 0, tmp - buf), 3);
			file->tmp = ft_strdup(buf + (tmp - buf) + 1);
			ft_strdel(&buf);
			return (1);
		}
		else
			*line = ft_strjoin_free(*line, buf, 1);
	}
	if (ret == 0 && **line == '\0')
		return (0);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_get	*list = NULL;
	t_get			*cur;

	if (!line || fd < 0)
		return (-1);
	if (*line)
		*line = NULL;
	*line = ft_strdup("");
	cur = ft_manage_fd(fd, &list);
	if (ft_check_stock(cur, line))
		return (1);
	return (ft_check_folder(cur, line));
}
