/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:17:36 by thninh            #+#    #+#             */
/*   Updated: 2016/11/17 09:57:50 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lst_len(t_list *lst)
{
	size_t		len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*tmp_map;
	t_list		*map;

	map = NULL;
	tmp_map = NULL;
	if (lst)
		map = (t_list *)malloc(sizeof(t_list) * ft_lst_len(lst));
	if (lst && map && f)
	{
		map = f(ft_lstnew(lst->content, lst->content_size));
		tmp_map = map;
		lst = lst->next;
		while (lst)
		{
			tmp_map->next = f(ft_lstnew(lst->content, lst->content_size));
			tmp_map = tmp_map->next;
			lst = lst->next;
		}
	}
	return (map);
}
