/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:21:34 by thninh            #+#    #+#             */
/*   Updated: 2016/11/17 15:25:32 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_list_size(t_list *begin_list)
{
	size_t		count;

	count = 0;
	if (begin_list)
	{
		while (begin_list->next)
		{
			count++;
			begin_list = begin_list->next;
		}
		return (count);
	}
	return (0);
}
