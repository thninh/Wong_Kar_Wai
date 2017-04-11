/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:16:52 by thninh            #+#    #+#             */
/*   Updated: 2016/11/17 12:02:40 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*nxt;

	if (alst && *alst && del)
	{
		while ((*alst)->next)
		{
			nxt = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = nxt;
		}
		ft_lstdelone(alst, del);
	}
}
